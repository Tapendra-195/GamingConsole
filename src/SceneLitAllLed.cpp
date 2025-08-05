#include "../include/SceneLitAllLed.h"
#include "../include/SceneMenu.h"
#include "../include/GameEngine.h"
#include "../include/Constants.h"



SceneLitAllLed::SceneLitAllLed(GameEngine* g):Scene(g)
{
  gameEngine->bgm.attachAudio(cantinaBand, ARRAY_LEN(cantinaBand),true);
  gameEngine->fgm.attachAudio(menuClicked, ARRAY_LEN(menuClicked));
}

void SceneLitAllLed::nextLed()
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

void SceneLitAllLed::update()
{
  nextLed();
  sAudio();
  sRender();
}

void SceneLitAllLed::sRender()
{
  putPixel(curLedx, curLedy);
}

void SceneLitAllLed::onEnd()
{
  gameEngine->changeScene(new SceneMenu(gameEngine));
}


void SceneLitAllLed::handleInput(const char key)
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
     //nothing
    }
  else if(key == 'D')
    {
      //nothing
    }
  else
    {
      //Do nothing
    }
}
