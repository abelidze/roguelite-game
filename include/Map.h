#pragma once

#include "GameSettings.h"
#include "GameObjects.h"

namespace engine {

/**
 * Cell class
 */

class Cell
{
public:
  Cell();
  // Cell(GameObject& obj) : object(obj) {};
  virtual ~Cell() = default;

  inline bool IsEmpty() const { return _objects.empty(); };

private:
  TWContainer<GameObject> _objects;
};

/**
 * Room class
 */

class Room
{
public:
  const seed_t id;

  Room(seed_t);
  Room(int, int);
  virtual ~Room() = default;

  // void Generate(seed_t);
  void LoadRoom(const TContainer<std::string>&);

private:
  TContainer< TSContainer<Cell> > cells;
  // TWContainer<Cell> updatedCells;
};

/**
 * Map class
 */

class Map: public GameObject
{
public:

  Map();
  Map(seed_t);
  Map(const std::string&);
  virtual ~Map() = default;

  // void GoToRoom(int, int);
  void LoadMap(const std::string&);
  void Redraw();
  void Draw();

private:
  bool _needRedraw = true;
  std::unordered_map<seed_t, Room> _rooms;
  seed_t _room;
};

} // namespace engine
