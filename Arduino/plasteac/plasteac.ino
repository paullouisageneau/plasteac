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

// ---------- Pin setup ----------
const int servoPins[4] = {5, 6, 7, 8};
const int speakerPin = 3;	// connected to a piezzo speaker

// -------- Servo offsets --------
const int leftHipOffset  = 5;
const int rightHipOffset = 5;
const int leftFootOffset  = 10;
const int rightFootOffset = 10;

// ------------- BPM -------------
long bpm = 120L;

// I'm a little teapot
//const char melody[] = "4C42D44E42F46G46C56A46C56G46R06F44F42G46E46E46D44D42E46C46R07C52A44G42G46F46E46D46C46R0";

// Tetris
const char melody[] = "4E52B42C54D52C52B44A42A42C54E52D52C56B42C54D54E54C54A42A42A42B42C56D52F54A52G52F56E52C54E52D52C54B42B42C54D54E54C54A44A44R0";

#include "move.h"
#include "melody.h"

void sync()
{
  // Given set BPM, delay until the next quarter of a beat
  static unsigned long lastMillis = 0;
  unsigned long duration = 60000L/(bpm*4);
  long leftMillis = lastMillis + duration - millis();
  if(leftMillis > 0) delay(leftMillis);
  lastMillis = millis();
  
  // Update melody
  syncMelody();
}

void setup()
{
  // Init serial
  Serial.begin(9600);

  // Init legs
  initialize();

  delay(4000);
}

void loop() 
{
  playMelody(melody, false);
  stand_rythm(2);
  side_left(2);
  hello_left(1);
  walk(2);

  playMelody(melody, false);
  stand_rythm(2);
  side_right(2);
  hello_right(1);
  walk(2);
}

