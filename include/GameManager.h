#pragma once

#include "GameSettings.h"
#include "InputManager.h"
#include "Scenes.h"

namespace game {

class GameManager
{
public:
  using scene_pointer = std::weak_ptr<engine::Scene>;

  static GameManager& Instance()
  {
    static GameManager self;
    return self;
  }

  template<class SceneType, typename... Args>
  void RegisterScene(Args&&... params);

  template<class SceneType>
  scene_pointer GetScene();

  template<class SceneType>
  void GoToScene();

  template<class SceneType>
  void SetRootScene();

  void GoToPrevious();
  void LoadConfig(const std::string&);
  void GameLoop();
  void Init();
  void InitGraphics();
  void Update();
  void Draw();

private:
  TSMap<std::size_t, engine::Scene> _scenes;
  TWContainer<engine::Scene> _sceneStack;
  scene_pointer _rootScene;

  GameManager() {};
  ~GameManager() {};

  GameManager(GameManager const&) = delete;
  GameManager& operator=(GameManager const&) = delete;
};


/**
 * Scene registration
 */

template<class SceneType, typename... Args>
void GameManager::RegisterScene(Args&&... params)
{
  if (_scenes.find(SceneType::TypeHash) != _scenes.end()) {
    throw std::runtime_error("RegisterScene misusage");
  }
  _scenes[SceneType::TypeHash] = std::make_shared<SceneType>(std::forward<Args>(params)...);
}

/**
 * Get registered scene
 */

template<class SceneType>
GameManager::scene_pointer GameManager::GetScene()
{
  auto sceneIt = _scenes.find(SceneType::TypeHash);
  if (sceneIt == _scenes.end()) {
    throw std::runtime_error("No registered scene found");
  }
  return sceneIt->second;
}


/**
 * Go to registered scene
 */

template<class SceneType>
void GameManager::GoToScene()
{
  auto sceneIt = _scenes.find(SceneType::TypeHash);
  if (sceneIt == _scenes.end()) {
    throw std::runtime_error("No registered scene found");
  }
  _sceneStack.emplace_back( std::forward<scene_pointer>(sceneIt->second) );
}

/**
 * Root scene
 */

template<class SceneType>
void GameManager::SetRootScene()
{
  auto sceneIt = _scenes.find(SceneType::TypeHash);
  if (sceneIt == _scenes.end()) {
    throw std::runtime_error("SetRootScene misusage");
  }
  _rootScene = sceneIt->second;
  _sceneStack.clear();
  _sceneStack.emplace_back( std::forward<scene_pointer>(sceneIt->second) );
}

} // namespace game