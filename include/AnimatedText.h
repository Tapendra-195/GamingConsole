#pragma once
#include "display.h"

class AnimatedText
{
 public:
  AnimatedText()
    {
      this->text = "";
      this->charDuration = 2000;
      index = 0;
      this->loop = false;
      
    }
  
  void attach(String text, bool loop = false, unsigned long charDuration = 150)
  {
    this->text = " "+text; //Don't want it to start right away while looping
    charStartTime = millis();
    index = 0;
    this->charDuration = charDuration;
    this->loop = loop;
    hasEnded = false;
  }
  
  void show()
  {
    if(hasEnded)
      {
        return;
      }
    
    if(millis()-charStartTime<charDuration)
      {
        char c = text[index];
        putChar(c,2,1);
        return;
      }
    else if(millis() - charStartTime < charDuration+0.10*charDuration)
      {
        //Do nothing. some delay before moving to next char.
        return;
      }
    
    charStartTime = millis();
    index++;
    
    if(index >= text.length())
      {
        index = 0;
        if(!loop)
	  {
	    hasEnded = true;
	  }
      }
  }
 private:
  String text;
  unsigned long charDuration;
  unsigned long charStartTime;
  int index;
  bool loop;
  bool hasEnded;
};
