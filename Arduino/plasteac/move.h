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
 
#include <Servo.h>

Servo servos[4];

void sync();  // defined in main file

void nsync(unsigned int count)
{
  // Call count times sync
  while(count--)
    sync();
}

// Move left leg
void left(int hip, int foot)
{
  servos[0].write(90 - (hip + leftHipOffset));
  servos[2].write(90 - (foot + leftFootOffset));
}

// Move right leg
void right(int hip, int foot)
{
  servos[1].write(90 - (hip + rightHipOffset));
  servos[3].write(90 - (foot + rightFootOffset));
}

// Initialize legs
void initialize()
{
  // Init servos
  for(int i = 0; i<4; ++i)
    servos[i].attach(servoPins[i]);

  left(0, 0);
  right(0, 0);
}

// -------- Moves --------

void stand(int cycles)
{
  while(cycles--)
  {
    left(-20, 0);
    right(-20, 0);
    nsync(4);
  }
}

void stand_rythm(int cycles)
{
  while(cycles--)
  {
    left(-20, 0);
    right(-20, 0);
    nsync(4);
    left(20, 0);
    right(20, 0);
    nsync(4);
  }
}

void walk(int cycles)
{
  const int a = 20;
  const int b = 80;
  const int c = 25;
  
  while(cycles--)
  {
    left(c, -(a+5));
    right(-c, a+5);
    nsync(2);
    left(c, 0);
    right(-c, 0);
    nsync(2);
    left(c, a);
    right(-c, -b);
    nsync(8);
    left(c, a+5);
    right(-c, -(a+5));
    nsync(4);

    left(-c, a+5);
    right(c, -(a+5));
    nsync(2);
    left(-c, 0);
    right(c, 0);
    nsync(2);
    left(-c, -b);
    right(c, a);
    nsync(8);
    left(-c, -(a+5));
    right(c, a+5);
    nsync(4);
  }

  left(0, 0);
  right(0, 0);
  nsync(4);
}

void side_left(int cycles)
{
  const int a = 50;
  
  while(cycles--)
  {
    left(0, -a);
    right(0, 0);
    nsync(2);

    left(0, 0);
    right(-0, a/2);
    nsync(2);
    
    left(0, a/2);
    right(0, 0);
    nsync(2);

    left(0, 0);
    right(0, -a);
    nsync(2);
  }
  
  left(0, 0);
  right(0, 0);
  nsync(4);
}

void side_right(int cycles)
{
  const int a = 50;
  
  while(cycles--)
  {
    left(0, 0);
    right(0, -a);
    nsync(2);

    left(0, a/2);
    right(0, 0);
    nsync(2);
    
    left(0, 0);
    right(0, a/2);
    nsync(2);

    left(0, -a);
    right(0, 0);
    nsync(2);
  }
  
  left(0, 0);
  right(0, 0);
  nsync(4);
}

void hello_left(int cycles)
{
  const int a = 20;
  const int b = 80;
  const int c = 25;

  left(0, -b);
  right(0, a);
  nsync(8);
  left(0, 0);
  right(0, a+5);
  nsync(4);

  while(cycles--)
  {
    left(-c, 0);
    right(-c/4, a+10);
    nsync(4);
    left(c, 0);
    right(c/4, a+10);
    nsync(4);
  }

  left(0, 0);
  right(0, a);
  nsync(2);
  left(0, 0);
  right(0, 0);
  nsync(2);
}

void hello_right(int cycles)
{
  const int a = 20;
  const int b = 80;
  const int c = 25;

  left(0, a);
  right(0, -b);
  nsync(8);
  left(0, a+5);
  right(0, 0);
  nsync(4);

  while(cycles--)
  {
    left(-c/4, a+10);
    right(-c, 0);
    nsync(4);
    left(c/4, a+10);
    right(c, 0);
    nsync(4);
  }

  left(0, a);
  right(0, 0);
  nsync(2);
  left(0, 0);
  right(0, 0);
  nsync(2);
}

