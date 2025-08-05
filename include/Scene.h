#pragma once
#include "audio.h"
#include "Arduino.h"
#include "AnimatedText.h"

class GameEngine;

class Scene
{
public:
  virtual ~Scene() {}
  Scene(GameEngine* g);
  virtual void update() = 0;
  virtual void handleInput(const char key)=0;
  
  void sAudio();
  bool hasEnded() const;
  
public:
  GameEngine* gameEngine = nullptr;
  bool isRunning = true;
};


