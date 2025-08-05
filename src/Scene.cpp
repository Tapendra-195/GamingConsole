#include "../include/Scene.h"
#include "../include/GameEngine.h"

Scene::Scene(GameEngine* g)
{
  gameEngine = g;
}

void Scene::sAudio()
{
  if(gameEngine->fgm.isPlaying)
    {
      gameEngine->fgm.play();
    }
  else
    {
      if(!gameEngine->muteBgm)
      {
        gameEngine->bgm.play();
      }
    }
}

bool Scene::hasEnded() const
{
  return !isRunning;
}
