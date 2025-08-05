#pragma once
#include "Scene.h"


class SceneSnakeDead: public Scene
{
public:
  SceneSnakeDead(GameEngine* g);
  void update() override;
  void handleInput(const char key) override;
  void sRender();
  void onEnd();
  void changeScene();
  
  
private:
  int currentMenuIndex;
  String menu[3] = { 
    "*Game Over!. Press U/D*",
    "1. Retry",
    "2. Main Menu", 
    };
};
