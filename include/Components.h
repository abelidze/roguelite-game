#pragma once

#include "GameSettings.h"
#include "InputManager.h"
#include "Objects.h"

namespace engine {

/**
 * Collider
 */
  
class Collider: public Component
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Collider(const GameObject& obj) : Component(obj) {}
};

/**
 * CellCollider
 */

class CellCollider: public Collider
{
EXTENDED_INHERITANCE_DECLARE()

public:
  CellCollider(const GameObject& obj) : Collider(obj) {}
};

/**
 * Behaviour
 */

class Behaviour: public Component
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Behaviour(const GameObject& obj) : Component(obj) { Start(); }

  virtual void Start() {}
  virtual void Update() {}
};

/**
 * Drawable
 */

class Drawable: public Behaviour
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Drawable(const GameObject& obj) : Behaviour(obj) {}

  virtual void Draw() = 0;
};

} // namespace engine



/**
 * EVERYTHING ABOUT GAME EVERYTHING ABOUT GAME EVERYTHING ABOUT GAME EVERYTHING ABOUT GAME EVERYTHING ABOUT GAME
 * EVERYTHING ABOUT GAME EVERYTHING ABOUT GAME EVERYTHING ABOUT GAME EVERYTHING ABOUT GAME EVERYTHING ABOUT GAME
 * EVERYTHING ABOUT GAME EVERYTHING ABOUT GAME EVERYTHING ABOUT GAME EVERYTHING ABOUT GAME EVERYTHING ABOUT GAME
 */


namespace game {

/**
 * Movement
 */

class Movement: public engine::Behaviour
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Movement(const engine::GameObject& obj) : Behaviour(obj) {}
};

/**
 * InputController
 */

class InputController: public Movement
{
EXTENDED_INHERITANCE_DECLARE()

public:
  InputController(const engine::GameObject& obj) : Movement(obj) {}

  void Update() override;
};

/**
 * EnemyAI
 */

class EnemyAI: public engine::Behaviour
{
EXTENDED_INHERITANCE_DECLARE()

public:
  EnemyAI(const engine::GameObject& obj) : Behaviour(obj) {}
};

} // namespace game
