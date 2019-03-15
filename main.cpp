#include "GameManager.h"

int main(int argc, char const *argv[])
{
  game::GameManager::Instance().GameLoop();
  return 0;
}