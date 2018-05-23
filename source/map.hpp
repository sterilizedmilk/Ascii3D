#pragma once
#include <map>

#include "coord.hpp"
#include "define.hpp"


enum block_type
{
    BLOCK_FLOOR = 0,
    BLOCK_WALL,
    NUM_BLOCKS,
};

enum texture_type
{
    TEXTURE_FLOOR = 0,
    TEXTURE_WALL,
    TEXTURE_CHAR,
    NUM_TEXTURE,
};

//extern char mapping[MAP_MAX_Y][MAP_MAX_X+1];


extern char texture_wall[8][8+1];

extern char texture_at[8][8+1];
extern char texture_A[8][8+1];
extern char texture_B[8][8+1];
extern char texture_C[8][8+1];
extern char texture_D[8][8+1];
extern char texture_E[8][8+1];
extern char texture_F[8][8+1];
extern char texture_G[8][8+1];
extern char texture_H[8][8+1];
extern char texture_I[8][8+1];
extern char texture_J[8][8+1];
extern char texture_K[8][8+1];
extern char texture_L[8][8+1];
extern char texture_M[8][8+1];
extern char texture_N[8][8+1];
extern char texture_O[8][8+1];
extern char texture_P[8][8+1];
extern char texture_Q[8][8+1];
extern char texture_R[8][8+1];
extern char texture_S[8][8+1];
extern char texture_T[8][8+1];
extern char texture_U[8][8+1];
extern char texture_V[8][8+1];
extern char texture_W[8][8+1];
extern char texture_X[8][8+1];
extern char texture_Y[8][8+1];
extern char texture_Z[8][8+1];

extern std::map<char, char (*)[8+1]> char_texture;

char** load_map(int &map_x, int &map_y);