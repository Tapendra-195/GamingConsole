#pragma once
#include "Scene.h"


class ScenePutMessage: public Scene
{
public:
  ScenePutMessage(GameEngine* g);
  void update() override;
  void handleInput(const char key) override;
  void sRender();
  void onEnd();
  
private:
  String message = "";
  enum State{Idle, ReadingMessageLength, ReadingMessage, DisplayingMessage};
  State currentState = Idle;
  char currentChar = ' ';
  int currentCharIndex = 0;
  int curLedx = 0;
  int curLedy = 0;
  unsigned messageLength = 0;
  void nextLed();
  void transitionToReadingMessageLength();
  void transitionToReadingMessage();
  void transitionToDisplayMessage();
};
