/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#undef EE_HANDS
#define MASTER_LEFT


#define	MK_3_SPEED						//Enable constant cursor speeds
#define MK_MOMENTARY_ACCEL    //Enable momentary speed selection
/*
The mouse keys Interval and Offset values are based on the default values by QMK. Please refer to  the docs for different settings available:
https://docs.qmk.fm/features/mouse_keys#constant-mode
*/

//change to per key tapping terms
#define TAPPING_TERM 250        //Tappimg term for one shot mods to delay the hold function of the OSM
#define PERMISSIVE_HOLD
#define RETRO_TAPPING           //Releasing the key without pressing another will send the original keycode even if it is outside the tapping term.



#define ONESHOT_TAP_TOGGLE 0  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */


#define CAPS_WORD_IDLE_TIMEOUT 5000  // 5 seconds.
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD //Double tap left shift within tapping terms to activate caps word




