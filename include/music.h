#pragma once
#include "Arduino.h"

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0



struct ToneNote {
  uint16_t note;  // Frequency in Hz
  uint16_t duration;   // Duration in milliseconds
};

const ToneNote menuChangeUp[] PROGMEM = {
  {NOTE_B5, 20},
  {NOTE_D6, 15},
  {NOTE_F6, 15},
  {NOTE_A6, 15},
  {NOTE_C7, 15},
  {NOTE_E7, 25},
  {NOTE_G4, 20},  // bass finish
  {REST,    20}
};

const ToneNote menuChangeDown[] PROGMEM = {
  {NOTE_E7, 15},
  {NOTE_C7, 15},
  {NOTE_A6, 15},
  {NOTE_F6, 15},
  {NOTE_D6, 20},
  {NOTE_B5, 30},
  {NOTE_E4, 20},  // bass hit
  {REST,    20}
};

const ToneNote menuClicked[] PROGMEM = {
  {NOTE_G5, 40},   // sharp, bright attack
  {NOTE_FS5, 30},  // quick drop for click texture
  {NOTE_D5, 60},   // short bass “thud” for impact
  {REST, 50}
};

const ToneNote notAllowed[] PROGMEM = {
  {NOTE_A5, 50},
  {NOTE_GS5, 50},
  {REST,  100}
};


const ToneNote menuChange[] PROGMEM = {
  {NOTE_E5, 25}, {NOTE_C5, 40}, {REST, 20},
  {NOTE_D5, 25}, {NOTE_A4, 50}
};


const ToneNote cantinaBand[] PROGMEM = {
  {NOTE_B4, 150}, {NOTE_E5, 150}, {NOTE_B4, 150}, {NOTE_E5, 150},
  {NOTE_B4, 75},  {NOTE_E5, 150}, {NOTE_B4, 75},  {REST, 75}, 
  {NOTE_AS4, 75}, {NOTE_B4, 75},  {NOTE_B4, 75},  {NOTE_AS4, 75},
  {NOTE_B4, 75},  {NOTE_A4, 75},  {REST, 75},     {NOTE_GS4, 75},
  {NOTE_A4, 75},  {NOTE_G4, 75},  {NOTE_G4, 300}, {NOTE_E4, 600},

  {NOTE_B4, 150}, {NOTE_E5, 150}, {NOTE_B4, 150}, {NOTE_E5, 150},
  {NOTE_B4, 75},  {NOTE_E5, 150}, {NOTE_B4, 75},  {REST, 75}, 
  {NOTE_AS4, 75}, {NOTE_B4, 75},

  {NOTE_A4, 150}, {NOTE_A4, 150}, {NOTE_GS4, 75}, {NOTE_A4, 150},
  {NOTE_D5, 75},  {NOTE_C5, 150}, {NOTE_B4, 150}, {NOTE_A4, 150},

  {NOTE_B4, 150}, {NOTE_E5, 150}, {NOTE_B4, 150}, {NOTE_E5, 150},
  {NOTE_B4, 75},  {NOTE_E5, 150}, {NOTE_B4, 75},  {REST, 75},
  {NOTE_AS4, 75}, {NOTE_B4, 75},

  {NOTE_D5, 300}, {NOTE_D5, 150}, {NOTE_B4, 75},  {NOTE_A4, 150},
  {NOTE_G4, 150}, {NOTE_E4, 600},

  {NOTE_E4, 400}, {NOTE_G4, 400},
  {NOTE_B4, 400}, {NOTE_D5, 400},

  {NOTE_F5, 150}, {NOTE_E5, 150}, {NOTE_AS4, 75}, {NOTE_AS4, 75},
  {NOTE_B4, 300}, {NOTE_G4, 300}
};


const ToneNote forceThemeIntro[] PROGMEM = {
  {NOTE_A4, 500},
  {NOTE_D5, 500},
  {NOTE_B4, 300},
  {NOTE_A4, 300},
  {NOTE_F5, 500},
  {NOTE_E5, 500},
  {NOTE_D5, 700},
  {NOTE_E5, 300},
  {NOTE_F5, 300},
  {NOTE_E5, 500},
  {NOTE_C5, 500},
  {NOTE_B4, 700},
  {NOTE_D5, 300},
  {NOTE_E5, 300},
  {NOTE_F5, 300},
  {NOTE_G5, 800}
};



const ToneNote appleBite[] PROGMEM = {
  {NOTE_C7, 60},
  {NOTE_G6, 60},
  {NOTE_E6, 40},
  {0, 20},
  {NOTE_E2, 80},  // low "chomp"
};

const ToneNote coolMelody[] PROGMEM = {
  {NOTE_E4, 250},  // eighth note
  {NOTE_G4, 250},
  {NOTE_B4, 250},
  {NOTE_E5, 500},  // quarter note
  {0,      250},   // rest
  {NOTE_D5, 250},
  {NOTE_C5, 250},
  {NOTE_A4, 500}
};


const ToneNote starWarsTheme[] PROGMEM = {
  {NOTE_AS4, 125}, {NOTE_AS4, 125}, {NOTE_AS4, 125},
  {NOTE_F5, 500}, {NOTE_C6, 500},
  {NOTE_AS5, 125}, {NOTE_A5, 125}, {NOTE_G5, 125}, {NOTE_F6, 500}, {NOTE_C6, 250},
  {NOTE_AS5, 125}, {NOTE_A5, 125}, {NOTE_G5, 125}, {NOTE_F6, 500}, {NOTE_C6, 250},
  {NOTE_AS5, 125}, {NOTE_A5, 125}, {NOTE_AS5, 125}, {NOTE_G5, 500}, {NOTE_C5, 125}, {NOTE_C5, 125}, {NOTE_C5, 125},
  {NOTE_F5, 500}, {NOTE_C6, 500},
  {NOTE_AS5, 125}, {NOTE_A5, 125}, {NOTE_G5, 125}, {NOTE_F6, 500}, {NOTE_C6, 250},

  {NOTE_AS5, 125}, {NOTE_A5, 125}, {NOTE_G5, 125}, {NOTE_F6, 500}, {NOTE_C6, 250},
  {NOTE_AS5, 125}, {NOTE_A5, 125}, {NOTE_AS5, 125}, {NOTE_G5, 500}, {NOTE_C5, 188}, {NOTE_C5, 62},
  {NOTE_D5, 375}, {NOTE_D5, 125}, {NOTE_AS5, 125}, {NOTE_A5, 125}, {NOTE_G5, 125}, {NOTE_F5, 125},
  {NOTE_F5, 125}, {NOTE_G5, 125}, {NOTE_A5, 125}, {NOTE_G5, 250}, {NOTE_D5, 125}, {NOTE_E5, 250}, {NOTE_C5, 188}, {NOTE_C5, 62},
  {NOTE_D5, 375}, {NOTE_D5, 125}, {NOTE_AS5, 125}, {NOTE_A5, 125}, {NOTE_G5, 125}, {NOTE_F5, 125},

  {NOTE_C6, 188}, {NOTE_G5, 62}, {NOTE_G5, 500}, {0, 125}, {NOTE_C5, 125},
  {NOTE_D5, 375}, {NOTE_D5, 125}, {NOTE_AS5, 125}, {NOTE_A5, 125}, {NOTE_G5, 125}, {NOTE_F5, 125},
  {NOTE_F5, 125}, {NOTE_G5, 125}, {NOTE_A5, 125}, {NOTE_G5, 250}, {NOTE_D5, 125}, {NOTE_E5, 250}, {NOTE_C6, 188}, {NOTE_C6, 62},
  {NOTE_F6, 250}, {NOTE_DS6, 125}, {NOTE_CS6, 250}, {NOTE_C6, 125},
  {NOTE_AS5, 250}, {NOTE_GS5, 125}, {NOTE_G5, 250}, {NOTE_F5, 125},
  {NOTE_C6, 1000}
};



const ToneNote forceTheme[] PROGMEM = {
  {NOTE_G4, 500}, {NOTE_C5, 500}, {NOTE_D5, 500}, {NOTE_E5, 500},
  {NOTE_C5, 500}, {NOTE_B4, 500}, {NOTE_C5, 750}, {0, 250},

  {NOTE_G4, 500}, {NOTE_C5, 500}, {NOTE_D5, 500}, {NOTE_E5, 500},
  {NOTE_C5, 500}, {NOTE_B4, 500}, {NOTE_C5, 1000}, {0, 500}
};

const ToneNote imperialMarch[] PROGMEM = {
  {NOTE_A4, 400}, {NOTE_A4, 400}, {NOTE_A4, 400},
  {NOTE_F4, 300}, {NOTE_C5, 100},

  {NOTE_A4, 400}, {NOTE_F4, 300},
  {NOTE_C5, 100}, {NOTE_A4, 800},

  {NOTE_E5, 400}, {NOTE_E5, 400}, {NOTE_E5, 400},
  {NOTE_F5, 300}, {NOTE_C5, 100},

  {NOTE_A4, 400}, {NOTE_F4, 300},
  {NOTE_C5, 100}, {NOTE_A4, 800},

  {NOTE_A5, 400}, {NOTE_A4, 300}, {NOTE_A4, 100},
  {NOTE_A5, 400}, {NOTE_AS4, 300}, {NOTE_G5, 100},

  {NOTE_DS5, 100}, {NOTE_D5, 100}, {NOTE_DS5, 200}, {REST, 200},
  {NOTE_A4, 200}, {NOTE_DS5, 400}, {NOTE_D5, 300}, {NOTE_CS5, 100},

  {NOTE_C5, 100}, {NOTE_B4, 100}, {NOTE_C5, 100}, {REST, 200},
  {NOTE_F4, 200}, {NOTE_AS4, 400}, {NOTE_F4, 300}, {NOTE_A4, 100},

  {NOTE_C5, 400}, {NOTE_A4, 300}, {NOTE_C5, 100}, {NOTE_E5, 800},

  {NOTE_A5, 400}, {NOTE_A4, 300}, {NOTE_A4, 100},
  {NOTE_A5, 400}, {NOTE_AS4, 300}, {NOTE_G5, 100},

  {NOTE_DS5, 100}, {NOTE_D5, 100}, {NOTE_DS5, 200}, {REST, 200},
  {NOTE_A4, 200}, {NOTE_DS5, 400}, {NOTE_D5, 300}, {NOTE_CS5, 100},

  {NOTE_C5, 100}, {NOTE_B4, 100}, {NOTE_C5, 100}, {REST, 200},
  {NOTE_F4, 200}, {NOTE_AS4, 400}, {NOTE_F4, 300}, {NOTE_A4, 100},

  {NOTE_A4, 400}, {NOTE_F4, 300}, {NOTE_C5, 100}, {NOTE_A4, 800},
};

const ToneNote blasterSound[] PROGMEM = {
  {NOTE_E7, 20},
  {NOTE_D7, 20},
  {NOTE_C7, 20},
  {NOTE_B6, 20},
  {NOTE_A6, 20},
  {NOTE_G6, 20},
  {NOTE_F6, 20},
  {NOTE_E6, 20},
  {NOTE_D6, 20},
  {NOTE_C6, 20},
  {NOTE_B5, 30},
  {NOTE_A5, 40},
  {REST,    30}
};

const ToneNote dyingSound[] PROGMEM = {
  {NOTE_C6, 100},
  {NOTE_B5, 120},
  {NOTE_A5, 140},
  {NOTE_G5, 160},
  {NOTE_F5, 180},
  {NOTE_E5, 200},
  {NOTE_D5, 220},
  {NOTE_C5, 300},
  {NOTE_C4, 500},
  {REST,    200}
};


