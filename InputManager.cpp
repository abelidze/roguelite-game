#include "InputManager.h"

namespace engine {

int Input::GetKey()
{
  return Input::Instance()._pressedKey;
}

void Input::Clear()
{
  Input::Instance()._pressedKey = -1;
}

void Input::PressKey(const int key)
{
  Input::Instance()._pressedKey = key;
}

bool Input::IsKeyPressed(const int key)
{
  return (Input::Instance()._pressedKey == key);
  // auto state = Input::Instance()._keyStates.find(key);
  // if (state == Input::Instance()._keyStates.end()) {
  //   return false;
  // }
  // return (state->second != false);
}

} // namespace engine