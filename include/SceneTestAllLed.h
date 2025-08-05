#pragma once
#include "Scene.h"


class SceneTestAllLed: public Scene
{
public:
  SceneTestAllLed(GameEngine* g);
  void update() override;
  void handleInput(const char key) override;
  void sRender();
  void onEnd();
  
  
private:
  int curLedx = 0;
  int curLedy = 0;
  int dt = 20;
  unsigned long start=0;
  void nextLed();
};
