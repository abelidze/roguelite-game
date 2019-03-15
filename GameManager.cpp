#include "GameManager.h"

namespace game {

using namespace std::chrono;

void GameManager::LoadConfig(const std::string& path)
{
  
}

void GameManager::GameLoop()
{
  Init();
  while (true) {
    auto startTime = steady_clock::now();

    Update();
    Draw();

    // napms(1000 / FRAME_RATE);
    std::this_thread::sleep_for(startTime + milliseconds(UPDATE_TIME) - steady_clock::now());
  }

  endwin();
}

void GameManager::InitGraphics()
{
  initscr();
  raw();
  nonl();
  noecho();
  curs_set(0);
  attron(A_BOLD);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  color_set(1, NULL);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  resize_term(WINDOW_H, WINDOW_W);
  // mouse_set(ALL_MOUSE_EVENTS);

  clear();
  refresh();
}

void GameManager::Init()
{
  InitGraphics();
  RegisterScene<MenuScene>();
  RegisterScene<GameScene>();
  SetRootScene<GameScene>();
  // _sceneStack.clear();
  // _sceneStack.push_back();
}

void GameManager::Update()
{
  // Input
  engine::Input::Clear();
  auto key = getch();
  if (key != ERR) {
    while (key == getch()) {};
    engine::Input::PressKey(key);
  }

  // Behaviours update
  auto currentScene = _sceneStack.back().lock();
  if (!currentScene) return;

  currentScene->Update();
}

void GameManager::Draw()
{
  auto currentScene = _sceneStack.back().lock();
  if (!currentScene) return;

  currentScene->Draw();
}


/**
 * Go to previous scene in stack
 */

void GameManager::GoToPrevious()
{
  if (_sceneStack.size() < 2) return;
  _sceneStack.pop_back();
}


} // namespace game