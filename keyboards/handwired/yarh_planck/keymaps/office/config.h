/* This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.  */


#pragma once




#define MK_KINETIC_SPEED							//Activate Mouse Kinetic Mode

#define MOUSEKEY_DELAY 5
#define MOUSEKEY_INTERVAL 10						//Smoothness of the cursor movement. the shorter the smoother
#define MOUSEKEY_MOVE_DELTA 16
#define MOUSEKEY_INITIAL_SPEED 100
#define MOUSEKEY_BASE_SPEED 3000
#define MOUSEKEY_DECELERATED_SPEED 400
#define MOUSEKEY_ACCELERATED_SPEED 2000

#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 3
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS 15
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 10
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8

#define TAPPING_TERM 1000        //Tappimg term for one shot mods to delay the hold function of the OSM
#define PERMISSIVE_HOLD
#define RETRO_TAPPING           //Releasing the key without pressing another will send the original keycode even if it is outside the tapping term.



#define ONESHOT_TAP_TOGGLE 0  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */


#define CAPS_WORD_IDLE_TIMEOUT 5000  // 5 seconds.


