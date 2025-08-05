#include "../include/ScenePutMessage.h"
#include "../include/SceneMenu.h"
#include "../include/GameEngine.h"
#include "../include/Constants.h"
#include "../include/font.h"

//Press rigt button to start setting message length
//select message length with up and down.
//Set message length with right.
//select character

ScenePutMessage::ScenePutMessage(GameEngine* g):Scene(g)
{
  gameEngine->txt.attach("Press Right", true);
  gameEngine->bgm.attachAudio(cantinaBand, ARRAY_LEN(cantinaBand),true);
  gameEngine->fgm.attachAudio(menuClicked, ARRAY_LEN(menuClicked));
}

void ScenePutMessage::nextLed()
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

void ScenePutMessage::update()
{
  nextLed();
  sAudio();
  sRender();
}

void ScenePutMessage::sRender()
{
  gameEngine->txt.show();
}

void ScenePutMessage::onEnd()
{
  gameEngine->changeScene(new SceneMenu(gameEngine));
}

void ScenePutMessage::transitionToReadingMessageLength()
{
  message = "";
  gameEngine->txt.attach(String(messageLength), true);
  currentState = ReadingMessageLength;
}

void ScenePutMessage::transitionToReadingMessage()
{
  currentCharIndex = 0;
  currentChar = getCharAt(currentCharIndex);
  gameEngine->txt.attach(String(currentChar), true);
  currentState = ReadingMessage;
}

void ScenePutMessage::transitionToDisplayMessage()
{
  gameEngine->txt.attach(message, true);
  currentState = DisplayingMessage;
}

void ScenePutMessage::handleInput(const char key)
{
  if(key == 'R')
    {
      switch(currentState)
	    {
      case Idle:
        transitionToReadingMessageLength();
        break;
	    case DisplayingMessage:
	      transitionToReadingMessageLength();
	      break;
	    case ReadingMessageLength:
	      transitionToReadingMessage();
	      break;
	    case ReadingMessage:
	      {
          if(message.length()>= messageLength-1)
	          {
              message += currentChar;
		          transitionToDisplayMessage();
	          }
	        else
	          {
		          message += currentChar;
	          }
          /*
          currentCharIndex = 0;
          currentChar = getCharAt(currentCharIndex);
          gameEngine->txt.attach(String(currentChar), true);
          */
	      }
	      break;
	    default:
	      break;
	}
      
      //do nothing
    }
  else if(key == 'L')
    {
      gameEngine->fgm.attachAudio(menuClicked, ARRAY_LEN(menuClicked));
      onEnd();
    }
  
  else if(key == 'U')
    {
      switch(currentState)
	{
	case ReadingMessageLength:
	  messageLength++;
	  gameEngine->txt.attach(String(messageLength), true);
	  break;
	case ReadingMessage:
  {
	  currentCharIndex++;
    
    if(currentCharIndex>TOTAL_FONT-1)
    {
      currentCharIndex = 0;
    }
    
	  currentChar = getCharAt(currentCharIndex);
	  gameEngine->txt.attach(String(currentChar), true);
  }
	  break;
	default:
	  break;
	}
      
    }
  else if(key == 'D')
    {
      switch(currentState)
	{
	case ReadingMessageLength:
	  messageLength--;
	  gameEngine->txt.attach(String(messageLength), true);
	  break;
	case ReadingMessage:
  {
	  currentCharIndex--;
    
    if(currentCharIndex<0)
    {
      currentCharIndex = TOTAL_FONT-1;
    }
    
	  currentChar = getCharAt(currentCharIndex);
	  gameEngine->txt.attach(String(currentChar), true);
  }
	  break;
	default:
	  break;
	}
      
    }
  else
    {
      //Do nothing
    }
}
