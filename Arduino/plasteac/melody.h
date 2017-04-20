/* 
 * Copyright (c) 2017 by Paul-Louis Ageneau
 * This file is part of Plasteac
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "pitch.h"

// Global melody status
const char *currentMelody = NULL;
const char *currentMelodyLoop = NULL;
unsigned int currentMelodyLeft = 0;	// sync calls left for current note

// Change current melody
void playMelody(const char *melody, bool looped = false)
{
  currentMelody = melody;
  if(looped) currentMelodyLoop = melody;
  else currentMelodyLoop = NULL;
  currentMelodyLeft = 0;
}

// Update current melody, must be called on each quarter of a beat
void syncMelody()
{
  if(currentMelody)
  {
    // Check for end of melody string
    if(!currentMelody[0] || !currentMelody[1] || !currentMelody[2])
    {
      currentMelody = currentMelodyLoop;
      if(!currentMelody)
        return;
    }
    
    if(currentMelodyLeft) currentMelodyLeft--;
    if(!currentMelodyLeft)
    {
      // Read note in melody string
      unsigned char d = (unsigned char)currentMelody[0];
      unsigned long duration = (d >= 0x41 ? d - 0x41 + 10 : d - 0x30);
      unsigned char note = (unsigned char)currentMelody[1];
      unsigned int octave = (unsigned char)currentMelody[2] - 0x30;

      // 0 is interpreted as a whole note, or semibreve
      if(duration == 0) duration = 16;
      
      // Update status
      currentMelodyLeft = duration;
      currentMelody+= 3;

      // Play note
      unsigned long unit = 60000L/(bpm*4);
      unsigned int frequency = pitch(octave, note);
      if(frequency) tone(speakerPin, frequency, duration*unit - unit/2);
    }
  }
  else {
    noTone(speakerPin);
  }
}

