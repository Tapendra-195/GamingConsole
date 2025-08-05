#pragma once
#include "Scene.h"


class SceneMenu: public Scene
{
public:
  SceneMenu(GameEngine* g);
  void update() override;
  void handleInput(const char key) override;
  void sRender();
  void onEnd();
  
  
private:
  void changeScene();
  int currentMenuIndex;
  String menu[4] = {
    "1. Snake Game", 
    "2. Test All Led", 
    "3. Lit All Led", 
    "4. Put Message"
    };
};
