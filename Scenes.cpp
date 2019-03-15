#include "Scenes.h"

using namespace engine;
using namespace game;

/**
 * The Hogwarts School of Magic
 */

EXTENDED_INHERITANCE_DEFINITION(Scene, Scene)
EXTENDED_INHERITANCE_DEFINITION(MenuScene, Scene)
EXTENDED_INHERITANCE_DEFINITION(GameScene, Scene)

/**
 * Constructors
 */

Scene::Scene() {}
MenuScene::MenuScene() : Scene() {}
GameScene::GameScene() : Scene()
{
  SpawnObject<Map>();
  SpawnObject<Knight>();
}


/**
 * Scene::Methods
 */

void Scene::Update()
{
  for (auto obj : _objects) {
    auto components = obj->GetComponents<Behaviour>();
    for (auto component : components) {
      component->Update();
    }
  }
}

void Scene::Draw()
{
  for (auto obj : _objects) {
    auto components = obj->GetComponents<Drawable>();
    for (auto component : components) {
      component->Draw();
    }
  }
}
