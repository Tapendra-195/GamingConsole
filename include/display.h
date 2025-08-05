#pragma once

void clearScreen();
void putPixel(int x, int y);
void litScreen();
void testAllLeds(int dt=100);
void litBorder();
void indexToCoord(int i, int& x, int& y);
void litNBorder(int n);
void putChar(char c, int x0 = 0, int y0 = 0);
  
