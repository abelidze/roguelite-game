#include "Map.h"

using namespace engine;

/**
 * Constructors
 */

Room::Room(seed_t id) : id(id) {};
Room::Room(int w, int h) : id(w * ROOM_SHIFT_X + h * ROOM_SHIFT_Y) {};

Map::Map() : _room(DEFAULT_ROOM_SEED), _rooms() {};
Map::Map(seed_t seed) : _room(seed), _rooms() {};
Map::Map(const std::string& path) : _room(0), _rooms() { LoadMap(path); };

/**
 * Room::Methods
 */

void Room::LoadRoom(const TContainer<std::string>& roomSource)
{
  // std::ifstream fin(path);
  // std::vector<std::string> scheme;
  // std::string line;
  // while (getline(fin, line))
  //   scheme.push_back(line);
  // fin.close();

  // auto height = roomSource.size();
  // auto width = roomSource.front().size();

  // cells.clear();
  // cells.resize(height);
  // updatedCells.clear();
  // for (auto line : roomSource) {
  //   cells.emplace_back( TSContainer<Cell>(line->size()) );
  //   for (auto symbol : line) {
  //     switch (symbol) {
  //       case WALL_SYMBOL:     cells.back().push_back() = new Wall(j, i); break;
  //       case FLOOR_SYMBOL:    cells.back().push_back() = new Floor(j, i); break;
  //       case PRINCESS_SYMBOL: cells.back().push_back() = new Princess(j, i); break;
  //       case KNIGHT_SYMBOL:   cells.back().push_back() = new Player(j, i); cursor.y = i; cursor.x = j; break;
  //       case ZOMBIE_SYMBOL:   cells.back().push_back() = new Zombie(j, i); actors.push_back(static_cast<Actor*>(cells.back().push_back())); break;
  //       case DRAGON_SYMBOL:   cells.back().push_back() = new Dragon(j, i); actors.push_back(static_cast<Actor*>(cells.back().push_back())); break;
  //       case HEALING_POTION_SYMBOL: cells.back().push_back() = new HealingPotion(j, i);
  //       default: break;
  //     }
  //   }
  // }
}

/**
 * Map::Methods
 */

void Map::LoadMap(const std::string& path)
{
  std::ifstream fin(path);
  std::vector<std::string> scheme;
  std::string line;
  while (getline(fin, line))
    scheme.push_back(line);
  fin.close();

  auto height = scheme.size();
  auto width = scheme.front().size();

  // tiles.resize(height);
  // for (size_t i = 0; i < tiles.size(); ++i) {
  //   tiles[i] = std::vector<Tile*>(width);
  //   for (size_t j = 0; j < tiles[i].size(); ++j) {
  //     switch (scheme[i][j]) {
  //       case WALL_SYMBOL:     tiles[i][j] = new Wall(j, i); break;
  //       case FLOOR_SYMBOL:    tiles[i][j] = new Floor(j, i); break;
  //       case PRINCESS_SYMBOL: tiles[i][j] = new Princess(j, i); break;
  //       case KNIGHT_SYMBOL:   tiles[i][j] = new Player(j, i); cursor.y = i; cursor.x = j; break;
  //       case ZOMBIE_SYMBOL:   tiles[i][j] = new Zombie(j, i); actors.push_back(static_cast<Actor*>(tiles[i][j])); break;
  //       case DRAGON_SYMBOL:   tiles[i][j] = new Dragon(j, i); actors.push_back(static_cast<Actor*>(tiles[i][j])); break;
  //       case HEALING_POTION_SYMBOL: tiles[i][j] = new HealingPotion(j, i);
  //       default: break;
  //     }
  //   }
  // }
}

void Map::Draw()
{
  if (_needRedraw) {
    _needRedraw = false;
    clear();
  }
  refresh();
}

void Map::Redraw()
{
  _needRedraw = true;
}