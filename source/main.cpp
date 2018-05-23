#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "coord.hpp"
#include "define.hpp"
#include "map.hpp"
#include "render.hpp"
#include "console.hpp"

using namespace std;

static screen scr[SCR_WIDTH][SCR_LENGTH];

static coord3 cam_pos = {1.0, 1.0, 0.7};
static spher_coord cam_dir = {0.0, PI/2};


bool cam_move(double dir)
{
    double stride = 0.25;
    dir += cam_dir.azimuth;

    coord3 move = {cos(dir), sin(dir), 0.0};
    move *= stride;
    cam_pos += move;

    return true;
}


int main()
{
    set_title("Ascii3D");

    printf("Press any key to start.");
    _getch();

    int map_x = 0, map_y = 0;
    char** map = load_map(map_x, map_y);

    if (!map)
    {
        printf("\nFailed to load \"map.txt\".");
        _getch();
        return 0;
    }

    set_font(L"Terminal", {8, 8});
    set_buffer(coord(SCR_LENGTH+1, SCR_WIDTH+1));
    set_size(coord(SCR_LENGTH, SCR_WIDTH));

    vector<polygon> polygons;
    make_poly(polygons, map, map_x, map_y);

    bool end = false;
    while (!end)
    {
        for (int y = 0; y < SCR_WIDTH; ++y)
            for (int x = 0; x < SCR_LENGTH; ++x)
            {
                scr[y][x].ch = ' ';
                scr[y][x].distance = -1.0;
            }

        screen_assign(cam_pos, cam_dir, polygons, scr);

        string lines;
        for (int y = 0; y < SCR_WIDTH; ++y)
        {
            for (int x = 0; x < SCR_LENGTH; ++x)
                lines += scr[y][x].ch;
            lines += '\n';
        }

        set_cursor();
        printf("%s", lines.c_str());

        switch (_getch())
        {
        case CMD_UP:
            cam_move(0);
            break;
        case CMD_RIGHT_UP:
            cam_move(PI/4);
            break;
        case CMD_RIGHT:
            cam_move(PI/2);
            break;
        case CMD_RIGHT_DOWN:
            cam_move(PI*3/4);
            break;
        case CMD_DOWN:
            cam_move(PI);
            break;
        case CMD_DOWN_LEFT:
            cam_move(PI*5/4);
            break;
        case CMD_LEFT:
            cam_move(PI*3/2);
            break;
        case CMD_LEFT_UP:
            cam_move(PI*7/4);
            break;

        case CMD_VIEW_RIGHT:
            cam_dir.spher_spin(PI/16);
            break;
        case CMD_VIEW_UP:
            cam_dir.spher_spin(0.0, -PI/16);
            break;
        case CMD_VIEW_LEFT:
            cam_dir.spher_spin(-PI/16);
            break;
        case CMD_VIEW_DOWN:
            cam_dir.spher_spin(0.0, PI/16);
            break;

        case CMD_QUIT:
            end = true;
            break;
        default:
            continue;
        }
    }

    if (map)
    {
        for (int i = 0; i < map_y; ++i)
        {
            delete[] map[i];
        }
        delete[] map;
    }

    return 0;
}
