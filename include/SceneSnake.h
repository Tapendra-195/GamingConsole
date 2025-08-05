#pragma once
#include "Scene.h"
#include "GameEngine.h"
#include "Arduino.h"

class SceneSnake: public Scene
{
public:
  SceneSnake(GameEngine* g, float s=4.0/60, int x=4, int y=3, float frameRate = 60);
  
  void update() override;
  void handleInput(char key) override;
  void sRender();
  void onEnd();
  
  void sMovement();

private:
  struct Point
  {
    int x, y;
  };
  Point body[43]; //Whole body of a snake
  int length;
  Point dir;
  float speed;
  float headX;
  float headY;
  Point fruit;
  unsigned long FRAME_TIME; // Time per frame. set at 60 fps

  void regenerateFruit();
  void showScore();
  void testCollision();
};
