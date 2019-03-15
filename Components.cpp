#include "Components.h"

using namespace engine;
using namespace game;

/**
 * The Hogwarts School of Magic
 */

EXTENDED_INHERITANCE_DEFINITION(Collider, Component)
EXTENDED_INHERITANCE_DEFINITION(CellCollider, Collider)
EXTENDED_INHERITANCE_DEFINITION(Behaviour, Component)
EXTENDED_INHERITANCE_DEFINITION(Drawable, Behaviour)

EXTENDED_INHERITANCE_DEFINITION(Movement, Behaviour)
EXTENDED_INHERITANCE_DEFINITION(InputController, Movement)
EXTENDED_INHERITANCE_DEFINITION(EnemyAI, Behaviour)

/**
 * Components Implementations
 */

void InputController::Update()
{
  switch (engine::Input::GetKey()) {
    case 'w': break;
    case 'a': break;
    case 's': break;
    case 'd': break;
    default: break;
  }
}
