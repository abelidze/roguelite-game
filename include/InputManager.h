#pragma once

#include "GameSettings.h"

namespace engine {

class Input
{
public:
  static void Clear();
  static int GetKey();
  static void PressKey(const int);
  static bool IsKeyPressed(const int);

private:
  // TMap<int, int> _keyStates;
  int _pressedKey = -1;

  Input() {};
  ~Input() {};

  static Input& Instance()
  {
    static Input self;
    return self;
  }

  Input(Input const&) = delete;
  Input& operator=(Input const&) = delete;
};

} // namespace engine