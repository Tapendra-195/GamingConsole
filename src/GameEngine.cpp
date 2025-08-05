#include "../include/GameEngine.h"
#include "../include/SceneMenu.h"
#include "../include/Constants.h"
#include <Bounce2.h>

GameEngine::GameEngine()
{
  changeScene(new SceneMenu(this));

  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);
  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  
  leftButton.attach(LEFT);
  rightButton.attach(RIGHT);
  upButton.attach(UP);
  downButton.attach(DOWN);

  leftButton.interval(25);
  rightButton.interval(25);
  upButton.interval(25);
  downButton.interval(25);
}

void GameEngine::run()
{
  char key = getKey();
  currentScene->handleInput(key);
  currentScene->update();
}

void GameEngine::changeScene(Scene* scene)
{
  delete currentScene;
  currentScene = scene;
}

void GameEngine::updateButtons() 
{
  leftButton.update();
  rightButton.update();
  upButton.update();
  downButton.update();
}

char GameEngine::getKey()
{
  updateButtons();

  if (leftButton.fell()) return 'L';
  if (rightButton.fell()) return 'R';
  if (upButton.fell()) return 'U';
  if (downButton.fell()) return 'D';

  return 'N';
}
