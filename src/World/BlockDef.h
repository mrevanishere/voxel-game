//
// Created by Evan on 20/12/12.
//

#ifndef BLOCKSANDSTICKS_BLOCKDEF_H
#define BLOCKSANDSTICKS_BLOCKDEF_H

typedef struct {
	unsigned int type;
} Block;

#define CHUNK_SIZE 16

#define AIR_BLOCK 0
#define GRASS_BLOCK 1
#define STONE_BLOCK 2
#define DIRT_BLOCK 3

static int BLOCK_FACES[][7] = {
	//first 6 are face textures, next int is a boolean of whether or not this block has some transparency
	// N,E,S,W,T,B,Opacity
	{ 0, 0, 0, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 3, 1, 0 },
	{ 2, 2, 2, 2, 2, 2, 0 },
    { 3, 3, 3, 3, 3, 3, 0 },
};

#endif //BLOCKSANDSTICKS_BLOCKDEF_H
