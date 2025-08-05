#include "../include/SceneTestAllLed.h"
#include "../include/SceneMenu.h"
#include "../include/GameEngine.h"
#include "../include/Constants.h"



SceneTestAllLed::SceneTestAllLed(GameEngine* g):Scene(g)
{
  start = millis();
  
  gameEngine->bgm.attachAudio(cantinaBand, ARRAY_LEN(cantinaBand),true);
  gameEngine->fgm.attachAudio(menuClicked, ARRAY_LEN(menuClicked));
}

void SceneTestAllLed::nextLed()
{
  curLedx++;
  if(curLedx>8)
    {
      curLedx = 0;
      curLedy++;
      if(curLedy > 7)
	{
	  curLedy = 0;
	}
    }
}

void SceneTestAllLed::update()
{
  unsigned long duration = millis() - start;
  if (duration > dt) {
    start = millis();
    nextLed();
  }
    
  sAudio();
  sRender();
}

void SceneTestAllLed::sRender()
{
  putPixel(curLedx, curLedy);
}

void SceneTestAllLed::onEnd()
{
  gameEngine->changeScene(new SceneMenu(gameEngine));
}


void SceneTestAllLed::handleInput(const char key)
{
  if(key == 'R')
    {
      //do nothing
    }
  else if(key == 'L')
    {
      gameEngine->fgm.attachAudio(menuClicked, ARRAY_LEN(menuClicked));
      onEnd();
    }

  else if(key == 'U')
    {
      dt-=10;
      if(dt<0)
      {
        dt = 0;
      }
    }
  else if(key == 'D')
    {
      dt+=10;
      if(dt>100)
      {
        dt = 50;
      }
    }
  else
    {
      //Do nothing
    }
}
