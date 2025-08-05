#pragma once
#include "Scene.h"


class SceneLitAllLed: public Scene
{
public:
  SceneLitAllLed(GameEngine* g);
  void update() override;
  void handleInput(const char key) override;
  void sRender();
  void onEnd();
  
  
private:
  int curLedx = 0;
  int curLedy = 0;
  void nextLed();
};
