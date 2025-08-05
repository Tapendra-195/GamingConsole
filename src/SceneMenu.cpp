#include "../include/SceneMenu.h"
#include "../include/GameEngine.h"
#include "../include/Constants.h"
#include "../include/SceneSnake.h"
#include "../include/SceneTestAllLed.h"
#include "../include/SceneLitAllLed.h"
#include "../include/ScenePutMessage.h"

SceneMenu::SceneMenu(GameEngine* g):Scene(g)
{
  currentMenuIndex = 0;
  gameEngine->txt.attach(menu[currentMenuIndex], true);
  gameEngine->bgm.attachAudio(cantinaBand, ARRAY_LEN(cantinaBand),true);
}

void SceneMenu::update()
{
  sRender();
  sAudio();
}

void SceneMenu::sRender()
{
  litBorder();
  gameEngine->txt.show();
}

void SceneMenu::onEnd()
{
  //maybe back to power off?
}

void SceneMenu::changeScene()
{
  switch(currentMenuIndex)
  {
    case 0:
      gameEngine->changeScene(new SceneSnake(gameEngine));
      break;
    case 1:
      gameEngine->changeScene(new SceneTestAllLed(gameEngine));
      break;
    case 2:
      gameEngine->changeScene(new SceneLitAllLed(gameEngine));
      break;
    case 3:
      gameEngine->changeScene(new ScenePutMessage(gameEngine));
    default:
      break;

  }
  
}

void SceneMenu::handleInput(const char key)
{
  if(key == 'R')
  {
    changeScene();
        
  }
  else if(key == 'L')
  {
    gameEngine->muteBgm = !(gameEngine->muteBgm);
    
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
