#pragma once

#include <ctime>
#include <thread>
#include <chrono>
#include <memory>
#include <string>
#include <vector>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <type_traits>
#include <unordered_map>
#include <stdexcept>

#include "curses.h"

/**
 * Ultra-magic creation of Gods#1
 */

#define EXTENDED_INHERITANCE_DECLARE()                                   \
public:                                                                  \
  static const std::size_t TypeHash;                                     \
  virtual bool IsClassType(const std::size_t) const;                     \

/**
 * Ultra-magic creation of Gods#2
 */

#define EXTENDED_INHERITANCE_DEFINITION(ChildClass, ParentClass)         \
const std::size_t ChildClass::TypeHash = typeid(ChildClass).hash_code(); \
bool ChildClass::IsClassType(const std::size_t classType) const          \
{                                                                        \
  if (classType == ChildClass::TypeHash)                                 \
    return true;                                                         \
  if (std::is_same<ChildClass, ParentClass>::value)                      \
    return false;                                                        \
  return ParentClass::IsClassType(classType);                            \
}                                                                        \

/**
 * Compilation time constants
 */

namespace engine {

const int DEFAULT_ROOM_SEED = 2147483648;
const int ROOM_SHIFT_X = 1;
const int ROOM_SHIFT_Y = 65536;

const char WALL_SYMBOL  = '#';
const char FLOOR_SYMBOL = '.';
const char KNIGHT_SYMBOL = 'K';
const char ZOMBIE_SYMBOL = 'Z';
const char DRAGON_SYMBOL = 'D';
const char CASTER_SYMBOL = 'X';
const char PRINCESS_SYMBOL = 'P';
const char PROJECTILE_SYMBOL = '*';
const char HEALING_SYMBOL = '+';

} // namespace engine

namespace game {

const int UPDATE_TIME = 350;
const int WINDOW_W = 120;
const int WINDOW_H = 50;

} // namespace game

/**
 * Typedef and co.
 */

typedef uint32_t seed_t;

template<class T>
using TWContainer = std::vector< std::weak_ptr<T> >;

template<class T>
using TSContainer = std::vector< std::shared_ptr<T> >;

template<class T>
using TUContainer = std::vector< std::unique_ptr<T> >;

template<class T>
using TContainer = std::vector<T>;

template<typename Key, class T>
using TSMap = std::unordered_map< Key, std::shared_ptr<T> >;

template<typename Key, class T>
using TMap = std::unordered_map< Key, T >;
