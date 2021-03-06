#ifndef DRAW_H_
#define DRAW_H_

#include "common.h"
#include "mapdata.h"
#include "player.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// print mapdata from the current map_pos_offset
void draw_mapdata_from_curr_mappos(char *mapdata);
// print the HUD, used by print_mapdata_from_curr_mappos
void draw_map_hud();

// thread for drawing mapdata (from current mappos)
void *draw_thread();

#endif
