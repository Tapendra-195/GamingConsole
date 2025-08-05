#include "../include/SceneSnakeDead.h"
#include "../include/SceneMenu.h"
#include "../include/GameEngine.h"
#include "../include/Constants.h"
#include "../include/SceneSnake.h"


SceneSnakeDead::SceneSnakeDead(GameEngine* g):Scene(g)
{
  gameEngine->bgm.attachAudio(cantinaBand, ARRAY_LEN(cantinaBand),true);
  gameEngine->fgm.attachAudio(dyingSound, ARRAY_LEN(dyingSound));
  
  currentMenuIndex=0;
  gameEngine->txt.attach(menu[currentMenuIndex], true);
}

void SceneSnakeDead::update()
{
  sRender();
  sAudio();
}

void SceneSnakeDead::sRender()
{
  gameEngine->txt.show();
}

void SceneSnakeDead::onEnd()
{
  gameEngine->changeScene(new SceneMenu(gameEngine));
}

void SceneSnakeDead::changeScene()
{
  switch(currentMenuIndex)
  {
    case 0:
      //do nothing
      break;
    case 1:
      gameEngine->changeScene(new SceneSnake(gameEngine));
      break;
    case 2:
      onEnd();
      break;
    default:
      //do nothing
      break;
  }
}

void SceneSnakeDead::handleInput(const char key)
{
  if(key == 'R')
    {
      changeScene();
    }
  else if(key == 'U')
    {
      currentMenuIndex--;
      currentMenuIndex = currentMenuIndex % ARRAY_LEN(menu);

      gameEngine->txt.attach(menu[currentMenuIndex], true);
      gameEngine->fgm.attachAudio(menuChangeUp, ARRAY_LEN(menuChangeUp));
    }
  else if(key == 'D')
    {
      currentMenuIndex++;
      currentMenuIndex = currentMenuIndex % ARRAY_LEN(menu);
      
      gameEngine->txt.attach(menu[currentMenuIndex], true);
      gameEngine->fgm.attachAudio(menuChangeDown, ARRAY_LEN(menuChangeDown));
    }
  else
    {
      //Do nothing
    }
}
