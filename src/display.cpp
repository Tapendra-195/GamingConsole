#include "../include/display.h"
#include "../include/font.h"
#include "Arduino.h"

void clearScreen()
{
  //Set PinMode to input for pins 2 to 10
  DDRD &= 0b00000011;
  DDRB &= 0b11111000; 

  //Set the output to 0. output 1 means pullup when DDR is 0.
  PORTD &= 0b00000011;
  PORTB &= 0b11111000;
}

void putPixel(int x, int y)
{
  clearScreen();

  //Outside screen, return.
  if(x<0 or x > 8 or y <0 or y > 7)
  {
  	return;
  }
  
  //Set x to high
  if(x<6)
  {
  	DDRD |= (1<<(x+2));
    PORTD |= (1<<(x+2));
  }
  else
  {
  	DDRB |= (1<<(x-6));
    PORTB |= (1<<(x-6));  
  }
  
  //Diagonal led are shifted in y
  if(y >= x)
  {
    y += 1;
  }

  //Set y to low
  if(y<6)
  {
  	DDRD |= (1<<(y+2));
    PORTD &= ~(1<<(y+2));
  }
  else
  {
  	DDRB |= (1<<(y-6));
    PORTB &= ~(1<<(y-6));  
  }
}


void litScreen()
{
  for(int y=0; y<8; y++)
  {
  	for(int x=0; x<9; x++)
    {
    	putPixel(x,y);
    }
  }
}

void testAllLeds(int dt)
{
  for(int y=0; y<8; y++)
  {
  	for(int x=0; x<9; x++)
    {
    	putPixel(x,y);
        delay(dt);
    }
  }
}
  
void litBorder()
{
	for(int i=0; i<9; i++)
    {
    	putPixel(i,0);
      	putPixel(i,7);
    }
  
  	for(int j=0; j<8; j++)
    {
    	putPixel(0,j);
      	putPixel(8,j);
    }

}

void indexToCoord(int i, int& x, int& y)
{    
    if(i<9)
    {
      x = i;
      y = 0;
    }
    else if(i<16)
    {
      x = 8;
      y = i-8;
    
    }
    else if(i<24)
    {
      y = 7;
      x = 8-(i-15);
    }
    else
    {
      x = 0;
      y = 7-(i-23);
    
    }
}


//Lit n leds in border. Counterclockwise
void litNBorder(int n)
{
  for(int i=0; i<n; i++)
  {
    int x,y;
    indexToCoord(i, x, y);
  	putPixel(x, y);
  } 
}

void putChar(char c, int x0, int y0)
{
  uint32_t font = getFont(c);
  for(int j=0; j<6; j++)
  {
    for(int i=0; i<5; i++)
    {
      if(font & 1)
      {
        putPixel(x0 + 4-i, y0 + j);
      }
      font = font >> 1;
    }
  }
  clearScreen();
}

