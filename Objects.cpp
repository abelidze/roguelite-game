#include "Objects.h"

namespace engine {

/**
 * The Hogwarts School of Magic
 */

EXTENDED_INHERITANCE_DEFINITION(Object, Object)
EXTENDED_INHERITANCE_DEFINITION(Component, Object)
EXTENDED_INHERITANCE_DEFINITION(GameObject, Object)

/**
 * Constructors
 */

Object::Object() {}
Component::Component(const GameObject& obj) : Object(), gameObject(obj) {}
GameObject::GameObject() : GameObject("") {}
GameObject::GameObject(const std::string& tag) : Object(), tag(tag) {}

} // namespace engine