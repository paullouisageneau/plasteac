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
const int servoPins[4] = {5, 6, 9, 10};
const int speakerPin = 3;

// -------- Servo offsets --------
const int leftHipOffset  = 5;
const int rightHipOffset = 5;
const int leftFootOffset  = 10;
const int rightFootOffset = 10;

// ------------- BPM -------------
long bpm = 120L;

#include "dance.h"

void sync()
{
  static unsigned long lastMillis = 0;
  unsigned long duration = 60000L/(bpm*4);
  long leftMillis = lastMillis + duration - millis();
  if(leftMillis > 0) delay(leftMillis);
  lastMillis = millis();
}

void setup()
{
  Serial.begin(9600);
  init_dance();
  delay(4000);
}

void loop() 
{
  stand_rythm(2);
  side_left(2);
  hello_left(2);
  walk(2);

  stand_rythm(2);
  side_right(2);
  hello_right(2);
  walk(2);
}

