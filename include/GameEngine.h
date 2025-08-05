#pragma once
#include "SceneMenu.h"
#include "Scene.h"
#include <Bounce2.h>

class GameEngine
{
public:
  GameEngine();
  void run();
  void changeScene(Scene* scene);
  char getKey();
  AnimatedText txt;
  AudioPlayer fgm;
  AudioPlayer bgm;
  bool muteBgm = false;

public:
  Scene* currentScene = nullptr;

private:
  Bounce leftButton;
  Bounce rightButton;
  Bounce upButton;
  Bounce downButton;
  void updateButtons();
};
