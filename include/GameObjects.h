#pragma once

#include "Components.h"

namespace game {
  
class Wall: public engine::GameObject
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Wall() : GameObject() {};

};

class Actor: public engine::GameObject
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Actor() : GameObject() {};
  
};

class Projectile: public Actor
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Projectile() : Actor() {};

};

class Knight: public Actor
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Knight() : Actor() { AddComponent<Movement>(); };

  void Draw()
  {
    
  }

};

class Monster: public Actor
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Monster() : Actor() {};

};

class Skelet: public Monster
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Skelet() : Monster() {};

};

class Dragon: public Monster
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Dragon() : Monster() {};

};

class Caster: public Monster
{
EXTENDED_INHERITANCE_DECLARE()

public:
  Caster() : Monster() {};

};

} // namespace game