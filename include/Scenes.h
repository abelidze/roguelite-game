#pragma once

#include "GameSettings.h"
#include "Map.h"

namespace engine {

class Scene
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Scene();
  virtual ~Scene() = default;

  virtual void Update();
  virtual void Draw();

  template <class ObjectType, typename... Args>
  ObjectType& SpawnObject(Args&&... params);

  template <class ObjectType>
  ObjectType& GetObject() const;

  template <class ObjectType>
  TWContainer<ObjectType> GetObjects();

  template <class ObjectType>
  bool DestroyObject();

  template <class ObjectType>
  int DestroyObjects();
  
protected:
  TSContainer<GameObject> _objects;
};

} // namespace engine


namespace game {

class MenuScene: public engine::Scene
{
EXTENDED_INHERITANCE_DECLARE()

public:
  MenuScene();
};

class GameScene: public engine::Scene
{
EXTENDED_INHERITANCE_DECLARE()

public:
  GameScene();
};

} // namespace game


template<typename... Args> struct count;

template<>
struct count<> {
    static const int value = 0;
};

template<typename T, typename... Args>
struct count<T, Args...> {
    static const int value = 1 + count<Args...>::value;
};

/**
 * Adds object to Scene
 * Passes all arguments to object's constructor (via perfect-forwarding)
 */
template <class ObjectType, typename... Args>
ObjectType& engine::Scene::SpawnObject(Args&&... params)
{
  _objects.emplace_back( std::make_shared<ObjectType>(std::forward<Args>(params)...) );
  return *static_cast<ObjectType*>( _objects.back().get() );
}

/**
 * Returns the first object that matches type or its derived class's type
 */
template <class ObjectType>
ObjectType& engine::Scene::GetObject() const
{
  for (auto&& object : _objects) {
    if ( object->IsClassType(ObjectType::TypeHash) )
      return *static_cast<ObjectType*>( object.get() );
  }

  return *std::unique_ptr<ObjectType>(nullptr);
}

/**
 * Returns a vector of pointers to the requested objects
 */
template <class ObjectType>
TWContainer<ObjectType> engine::Scene::GetObjects()
{
  TWContainer<ObjectType> objectsOfType;

  for (auto&& object : _objects) {
    if ( object->IsClassType(ObjectType::TypeHash) )
      objectsOfType.emplace_back( object.get() );
  }
  return objectsOfType;
}

/**
 * Attempt to remove object from the Scene
 * Returns true on success and false except
 */
template <class ObjectType>
bool engine::Scene::DestroyObject()
{
  // if ( objects.empty() ) return false;

  for (auto it = _objects.begin(); it != _objects.end(); ++it) {
    if ( (*it)->IsClassType(ObjectType::TypeHash) )
      _objects.erase(it);
      return true;
  }
  return false;
}

/**
 * Remove all objects of suggested type
 * Returns the number of successful removals, or 0 if none are removed
 */
template <class ObjectType>
int engine::Scene::DestroyObjects()
{
  // if ( objects.empty() ) return 0;

  int count = 0;
  while ( DestroyObject<ObjectType>() ) {
    ++count;
  }
  return count;
}
