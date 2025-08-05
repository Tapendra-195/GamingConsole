#pragma once
#include "music.h"
#include "Constants.h"
#include "Arduino.h"


class AudioPlayer
{
  public:
    ToneNote* audio;
    int length;
    int curIndex;
    bool isPlaying;

    AudioPlayer()
    {
      audio = nullptr;
      length = 0;
      curIndex = 0;
      isPlaying = false;
    }

    void attachAudio(ToneNote* audio, int length, bool loop=false)
    {
      this->audio = audio;
      this->length = length;
      this->loop = loop;
      curIndex = 0;
      isPlaying = true;
      pauseStartTime = millis();
    }

    void play()
    {
      if(length == 0)
      {
        return;
      }

      if(millis()-pauseStartTime<pauseBetweenNotes)
      {
        return;
      }

      ToneNote t;
      memcpy_P(&t, &audio[curIndex], sizeof(ToneNote));


      int noteDuration = t.duration/2.0;//audio[curIndex].duration/2.0;//10000 / audio[curIndex].duration;

      //tone(BUZZER, audio[curIndex].note*2, noteDuration);
      tone(BUZZER, t.note*2, noteDuration);
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      pauseBetweenNotes = noteDuration * 1.3;
      pauseStartTime = millis();
      //delay(pauseBetweenNotes);
      // stop the tone playing:
      curIndex++;
      if(curIndex>=length)
      {
        if(!loop)
        {
          noTone(BUZZER);
          this->audio = nullptr;
          this->length = 0;
          isPlaying = false;
        }
        else
        {
          this->curIndex = 0;
          isPlaying = true;
        }
      }
    }

  private:
    int pauseBetweenNotes;
    unsigned long pauseStartTime;
    bool loop;

};
