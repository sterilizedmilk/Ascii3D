#include <fstream>
#include <string>

#include "map.hpp"

#include "define.hpp"

using namespace std;

char texture_wall[8][8+1] =
{
    "########",
    "#      #",
    "#      #",
    "#      #",
    "#      #",
    "#      #",
    "#      #",
    "########"

/*
    "        ",
    "  #  #  ",
    " ###### ",
    "  #  #  ",
    "  #  #  ",
    " ###### ",
    "  #  #  ",
    "        "
*/
};

char texture_at[8][8+1] =
{
    "        ",
    "  @@@@@ ",
    " @@   @@",
    " @@ @@@@",
    " @@ @@@@",
    " @@ @@@@",
    " @@     ",
    "  @@@@  "
};

char texture_A[8][8+1] =
{
    "        ",
    "   AA   ",
    "  AAAA  ",
    " AA  AA ",
    " AA  AA ",
    " AAAAAA ",
    " AA  AA ",
    " AA  AA "
};

char texture_B[8][8+1] =
{
    "        ",
    " BBBBBB ",
    "  BB  BB",
    "  BB  BB",
    "  BBBBB ",
    "  BB  BB",
    "  BB  BB",
    " BBBBBB "
};

char texture_C[8][8+1] =
{
    "        ",
    "   CCCC ",
    "  CC  CC",
    " CC     ",
    " CC     ",
    " CC     ",
    "  CC  CC",
    "   CCCC "

};

char texture_D[8][8+1] =
{
    "        ",
    " DDDDDD ",
    "  DD DD ",
    "  DD  DD",
    "  DD  DD",
    "  DD  DD",
    "  DD DD ",
    " DDDDDD "
};

char texture_E[8][8+1] =
{
    "        ",
    " EEEEEEE",
    "  EE   E",
    "  EE E  ",
    "  EEEE  ",
    "  EE E  ",
    "  EE   E",
    " EEEEEEE"
};

char texture_F[8][8+1] =
{
    "        ",
    " FFFFFFF",
    "  FF   F",
    "  FF F  ",
    "  FFFF  ",
    "  FF F  ",
    "  FF    ",
    " FFFF   "
};

char texture_G[8][8+1] =
{
    "        ",
    "   GGGG ",
    "  GG  GG",
    " GG     ",
    " GG     ",
    " GG  GGG",
    "  GG  GG",
    "   GGGGG"
};

char texture_H[8][8+1] =
{
    "        ",
    " HH  HH ",
    " HH  HH ",
    " HH  HH ",
    " HHHHHH ",
    " HH  HH ",
    " HH  HH ",
    " HH  HH "
};

char texture_I[8][8+1] =
{
    "        ",
    "  IIII  ",
    "   II   ",
    "   II   ",
    "   II   ",
    "   II   ",
    "   II   ",
    "  IIII  "
};

char texture_J[8][8+1] =
{
    "        ",
    "    JJJJ",
    "     JJ ",
    "     JJ ",
    "     JJ ",
    " JJ  JJ ",
    " JJ  JJ ",
    "  JJJJ  "
};

char texture_K[8][8+1] =
{
    "        ",
    " KKK  KK",
    "  KK  KK",
    "  KK KK ",
    "  KKKK  ",
    "  KK KK ",
    "  KK  KK",
    " KKK  KK"
};

char texture_L[8][8+1] =
{
    "        ",
    " LLLL   ",
    "  LL    ",
    "  LL    ",
    "  LL    ",
    "  LL   L",
    "  LL  LL",
    " LLLLLLL"
};

char texture_M[8][8+1] =
{
    "        ",
    " MM   MM",
    " MMM MMM",
    " MMMMMMM",
    " MM M MM",
    " MM   MM",
    " MM   MM",
    " MM   MM"
};

char texture_N[8][8+1] =
{
    "        ",
    " NN   NN",
    " NNN  NN",
    " NNNN NN",
    " NN NNNN",
    " NN  NNN",
    " NN   NN",
    " NN   NN"
};

char texture_O[8][8+1] =
{
    "        ",
    "  OOOO  ",
    " OO  OO ",
    "OO    OO",
    "OO    OO",
    "OO    OO",
    " OO  OO ",
    "  OOOO  "
};

char texture_P[8][8+1] =
{
    "        ",
    " PPPPPP ",
    "  PP  PP",
    "  PP  PP",
    "  PPPPP ",
    "  PP    ",
    "  PP    ",
    " PPPP   "
};

char texture_Q[8][8+1] =
{
    "        ",
    "  QQQQ  ",
    " QQ  QQ ",
    " QQ  QQ ",
    " QQ  QQ ",
    " QQ QQQ ",
    "  QQQQ  ",
    "    QQQ "
};

char texture_R[8][8+1] =
{
    "        ",
    " RRRRRR ",
    "  RR  RR",
    "  RR  RR",
    "  RRRRR ",
    "  RRRR  ",
    "  RR RR ",
    " RRR  RR"
};

char texture_S[8][8+1] =
{
    "        ",
    "  SSSS  ",
    " SS  SS ",
    " SSS    ",
    "   SSS  ",
    "    SSS ",
    " SS  SS ",
    "  SSSS  "
};

char texture_T[8][8+1] =
{
    "        ",
    " TTTTTT ",
    " T TT T ",
    "   TT   ",
    "   TT   ",
    "   TT   ",
    "   TT   ",
    "  TTTT  "
};

char texture_U[8][8+1] =
{
    "        ",
    "UU    UU",
    "UU    UU",
    "UU    UU",
    "UU    UU",
    "UU    UU",
    "UU    UU",
    "UUUUUUUU"
};


char texture_V[8][8+1] =
{
    "        ",
    " VV  VV ",
    " VV  VV ",
    " VV  VV ",
    " VV  VV ",
    " VV  VV ",
    "  VVVV  ",
    "   VV   "
};

char texture_W[8][8+1] =
{
    "        ",
    " WW   WW",
    " WW   WW",
    " WW   WW",
    " WW W WW",
    " WWWWWWW",
    " WWW WWW",
    " WW   WW"
};

char texture_X[8][8+1] =
{
    "        ",
    " XX   XX",
    " XX   XX",
    "  XX XX ",
    "   XXX  ",
    "  XX XX ",
    " XX   XX",
    " XX   XX"
};

char texture_Y[8][8+1] =
{
    "        ",
    " YY  YY ",
    " YY  YY ",
    " YY  YY ",
    "  YYYY  ",
    "   YY   ",
    "   YY   ",
    "  YYYY  "
};

char texture_Z[8][8+1] =
{
    "        ",
    " ZZZZZZZ",
    " ZZ  ZZ ",
    " Z  ZZ  ",
    "   ZZ   ",
    "  ZZ   Z",
    " ZZ   ZZ",
    " ZZZZZZZ"
};

/*
char texture_[8][8+1] =
{
    "",
    "",
    "",
    "",
    "",
    "",
    "",
    ""
};
*/

std::map<char, char (*)[8+1]> char_texture =
{
    {'@', texture_at},
    {'A', texture_A},
    {'B', texture_B},
    {'C', texture_C},
    {'D', texture_D},
    {'E', texture_E},
    {'F', texture_F},
    {'G', texture_G},
    {'H', texture_H},
    {'I', texture_I},
    {'J', texture_J},
    {'K', texture_K},
    {'L', texture_L},
    {'M', texture_M},
    {'N', texture_N},
    {'O', texture_O},
    {'P', texture_P},
    {'Q', texture_Q},
    {'R', texture_R},
    {'S', texture_S},
    {'T', texture_T},
    {'U', texture_U},
    {'V', texture_V},
    {'W', texture_W},
    {'X', texture_X},
    {'Y', texture_Y},
    {'Z', texture_Z}
};

char** load_map(int &map_x, int &map_y)
{
    ifstream file("map.txt");

    char temp_map[100][100+1] = {'\0', };
    
    if (file.is_open())
    {
        while (!file.eof())
        {
            file.getline(temp_map[map_y], 100+1);

            for (int i = 0; i < 100+1; ++i)
            {
                if (temp_map[map_y][i] == '\0')
                {
                    if (map_x < i)
                        map_x = i;
                    break;
                }
            }

            ++map_y;
            if (map_y == 100)
                break;
        }

        char** map = new char*[map_y];
        for (int i = 0; i < map_y; ++i)
        {
            map[i] = new char[map_x+1];

            for (int j = 0; j < map_x+1; ++j)
                map[i][j] = temp_map[i][j];
        }

        return map;
    }

    return nullptr;
}
