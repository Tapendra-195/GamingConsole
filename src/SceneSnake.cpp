#include "../include/SceneSnake.h"
#include "../include/Constants.h"
#include "../include/SceneSnakeDead.h"

SceneSnake::SceneSnake(GameEngine* g, float s, int x, int y, float frameRate):Scene(g), speed(s)
{
  FRAME_TIME = 1000000/(2*frameRate);
  body[0].x = x;
  body[0].y = y;
  body[1].x = x-1;
  body[1].y = y;
  body[2].x = x-2;
  body[2].y = y;
  length = 3;
  headX = x;
  headY = y;
  
  dir.x = 1;
  dir.y = 0;
  //randomSeed(analogRead(A0));  // seed with noise
  regenerateFruit();
  isRunning = true; 
  gameEngine->bgm.attachAudio(imperialMarch, ARRAY_LEN(imperialMarch), true);
  gameEngine->fgm.attachAudio(menuClicked, ARRAY_LEN(menuClicked));
};

void SceneSnake::handleInput(char key)
{   
  if(key == 'L' && dir.x!=1)
    {
      dir.x = -1;
      dir.y = 0;
    }
  else if(key == 'R' && dir.x!=-1)
    {
      dir.x = 1;
      dir.y = 0;    
    }
  else if(key == 'U' && dir.y!=-1)
    {
      dir.x = 0;
      dir.y = 1;
    }
  else if(key == 'D' && dir.y!=1)
    {
      dir.x = 0;
      dir.y = -1;
    }
  else
    {
      //Do nothing
    }
}

void SceneSnake::update()
{
  unsigned long start = micros();
  sMovement();//collision is tested inside movement
  sAudio();
  sRender();
  
  unsigned long duration = micros() - start;
  while (duration < FRAME_TIME) {
    sAudio();
    sRender();
    duration = micros() - start;
  }  
}

void SceneSnake::sMovement()
{
  headX += speed*dir.x;
  headY += speed*dir.y;
  
  bool snakeHasMoved = false;
  if((int)headX != body[0].x || (int)headY != body[0].y)
    {
      snakeHasMoved = true;
    }
  
  //Now update body
  if(snakeHasMoved)
    {
      //Check if fruit has been eaten
      if((int)headX == fruit.x && (int)headY == fruit.y)
	{
	  //Ate apple play music
	  gameEngine->fgm.attachAudio(blasterSound, ARRAY_LEN(blasterSound));
	  regenerateFruit();
	  length++;
	}
      
      //Body moves towards the head
      for(int i=length-1; i>0; i--)
	{
	  body[i].x = body[i-1].x;
	  body[i].y = body[i-1].y;
	}
      
      //Update the head now
      body[0].x = (int)headX;
      body[0].y = (int)headY;
      
      testCollision();
    }
}

void SceneSnake::sRender()
{
  showScore();
  for(int i=0; i<length; i++)
    {
      putPixel(body[i].x, body[i].y);
      
    }
  
  putPixel(body[0].x, body[0].y);
  //Render fruit
  putPixel(fruit.x, fruit.y);
  
  //Show score
  
}

void SceneSnake::onEnd()
{
  gameEngine->changeScene(new SceneSnakeDead(gameEngine));
}

void SceneSnake::regenerateFruit()
{
  fruit.x = random(1,8);
  fruit.y = random(1,7);
}

void SceneSnake::showScore()
{
  //43->30 3->0
  int score = 0.75*(length - 3);
  litNBorder(score);
}

void SceneSnake::testCollision()
{
  if(body[0].x>7 || body[0].x<1 || body[0].y<1 || body[0].y>6)
    {
      isRunning = false;
      onEnd();
      return;
    }
  
  for(int i=1; i<length; i++)
    {
      if(body[0].x==body[i].x && body[0].y==body[i].y)
	{
	  isRunning = false;
	  onEnd();
	  return;
	}
    }
}
