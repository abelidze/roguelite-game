#pragma once

#include "GameSettings.h"

namespace engine {

class Component;
class GameObject;

/**
 * Object - base class for gameobjects and components
 */

class Object
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Object();
  virtual ~Object() = default;
};

/**
 * Component - base class for components. Must be attached to GameObject
 */

class Component: public Object
{
EXTENDED_INHERITANCE_DECLARE()

public:
  const GameObject& gameObject;

  Component(const GameObject&);
};

/**
 * GameObject - base class for all ingame objects
 */

class GameObject: public Object
{
EXTENDED_INHERITANCE_DECLARE()

public:
  std::string tag;

  GameObject();
  GameObject(const std::string&);

  template<class ComponentType, typename... Args>
  void AddComponent(Args&&... params);

  template<class ComponentType>
  ComponentType& GetComponent() const;

  template<class ComponentType>
  TContainer<ComponentType*> GetComponents();

  template<class ComponentType>
  bool RemoveComponent();

  template<class ComponentType>
  int RemoveComponents();

protected:
  TUContainer<Component> components;
};

/**
 * Adds component to GameObject
 * Passes all arguments to component's constructor (via perfect-forwarding)
 */
template<class ComponentType, typename... Args>
void GameObject::AddComponent(Args&&... params)
{
  components.emplace_back( std::make_unique<ComponentType>(*this, std::forward<Args>(params)...) );
}

/**
 * Returns the first component that matches type or its derived class's type
 */
template<class ComponentType>
ComponentType& GameObject::GetComponent() const
{
  for (auto&& component : components) {
    if ( component->IsClassType(ComponentType::TypeHash) )
      return *static_cast<ComponentType*>( component.get() );
  }

  return *std::unique_ptr<ComponentType>(nullptr);
}

/**
 * Returns a vector of pointers to the requested components
 */
template<class ComponentType>
TContainer<ComponentType*> GameObject::GetComponents()
{
  TContainer<ComponentType*> componentsOfType;

  for (auto&& component : components) {
    if ( component->IsClassType(ComponentType::TypeHash) )
      componentsOfType.push_back( static_cast<ComponentType*>(component.get()) );
  }
  return componentsOfType;
}

/**
 * Attempt to remove component from the GameObject
 * Returns true on success and false except
 */
template<class ComponentType>
bool GameObject::RemoveComponent()
{
  // if ( components.empty() ) return false;

  for (auto it = components.begin(); it != components.end(); ++it) {
    if ( (*it)->IsClassType(ComponentType::TypeHash) )
      components.erase(it);
      return true;
  }
  return false;
}

/**
 * Remove all components of suggested type
 * Returns the number of successful removals, or 0 if none are removed
 */
template<class ComponentType>
int GameObject::RemoveComponents()
{
  // if ( components.empty() ) return 0;

  int count = 0;
  while ( RemoveComponent<ComponentType>() ) {
    ++count;
  }
  return count;
}

} // namespace engine