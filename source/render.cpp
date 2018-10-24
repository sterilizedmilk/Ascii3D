#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <windows.h>

#include "render.hpp"

#include "coord.hpp"
#include "map.hpp"
#include "matrix.hpp"

using namespace std;

/**
 * A=dir, B=vecX. C=vecY
 * k*A = P1 = P0 + x*B + y*C
 * k*A - x*B - y*C = P0
 */
coord3 polygon::transform(coord3 dir) const
{
    coord3 vecX = vertex[1] - vertex[0];
    coord3 vecY = vertex[2] - vertex[0];
   
    matrix3<double> mat = { vecX.x, vecY.x, dir.x,
                            vecX.y, vecY.y, dir.y, 
                            vecX.z, vecY.z, dir.z };

    coord3 transformed = mat.inverse() * vertex[0];

    transformed.x *= -1;
    transformed.y *= -1;
    return transformed;
}

void make_poly(vector<polygon> &polygons, char** map, int map_x, int map_y)
{
    coord3 ver[4] = { { 0.5, 0.5, 1.0},
                      { 0.5,-0.5, 1.0},
                      { 0.5, 0.5, 0.0},
                      { 0.5,-0.5, 0.0} };

    for (int y = 0; y < map_y; ++y)
        for (int x = 0; x < map_x; ++x)
        {
            coord3 center = {x, y, 0};

            switch (map[y][x])
            {
            case '#':
            for (int i = 0; i < 4; ++i)
            {
                coord adjacent = coord(x, y) + compass[2*i];

                if (adjacent >= coord(0, 0) && adjacent < coord(map_x, map_y))
                {
                    if (map[adjacent.y][adjacent.x] != '#')
                    {
                        polygons.push_back(polygon(SHP_REC, TEXTURE_WALL, texture_wall,
                                                                          center + ver[0],
                                                                          center + ver[1],
                                                                          center + ver[2],
                                                                          center + ver[3]));
                    }
                }
                for(coord3 &j : ver) // spin
                {
                    double jx = j.x;
                    j.x = -j.y;
                    j.y = jx;
                }
            }
            break;

            case '@':  case 'A':  case 'B':  case 'C':  case 'D':  case 'E':  case 'F':  case 'G':  case 'H':
            case 'I':  case 'J':  case 'K':  case 'L':  case 'M':  case 'N':  case 'O':  case 'P':  case 'Q':
            case 'R':  case 'S':  case 'T':  case 'U':  case 'V':  case 'W':  case 'X':  case 'Y':  case 'Z':
            polygons.push_back(polygon(SHP_REC, TEXTURE_CHAR, char_texture[map[y][x]],
                                                center + coord3(0.0,-0.5, 1.0),
                                                center + coord3(0.0, 0.5, 1.0),
                                                center + coord3(0.0,-0.5, 0.0),
                                                center + coord3(0.0, 0.5, 0.0)));

            case '.':
            polygons.push_back(polygon(SHP_REC, TEXTURE_FLOOR, nullptr,
                                                               center + coord3( 0.5, 0.5, 0.0),
                                                               center + coord3( 0.5,-0.5, 0.0),
                                                               center + coord3(-0.5, 0.5, 0.0),
                                                               center + coord3(-0.5,-0.5, 0.0)));
                break;

            case '\0':
            default:
                break;
            }
        }
}

void screen_assign(const coord3 &cam_pos, const spher_coord &cam_dir, const vector<polygon> &polygons, screen scr[][SCR_LENGTH])
{
    coord3 cam = cam_dir.spher_to_coord3();
    coord3 cam_center = cam * SCR_DISTANCE;
    coord3 vecX = spher_coord(cam_dir.azimuth + PI/2, PI/2).spher_to_coord3() * SCR_HORIZONTAL / SCR_LENGTH;
    coord3 vecY = spher_coord(cam_dir.azimuth, cam_dir.polar + PI/2).spher_to_coord3() * SCR_VERTICAL / SCR_WIDTH;

    for (polygon po : polygons)
    {
        po -= cam_pos;

        coord3 poly_center = (po.vertex[1] + po.vertex[2]) / 2;

        if (poly_center.square() > 100.0)
            continue;

        if (po.type == TEXTURE_CHAR)
        {
            coordd v = coordd(-poly_center.y, poly_center.x) * (po.vertex[1] - po.vertex[0]).abs() / poly_center.abs() / 2;

            po.vertex[0].x = poly_center.x - v.x;
            po.vertex[0].y = poly_center.y - v.y;
            po.vertex[1].x = poly_center.x + v.x;
            po.vertex[1].y = poly_center.y + v.y;

            po.vertex[2].x = po.vertex[0].x;
            po.vertex[2].y = po.vertex[0].y;
            po.vertex[3].x = po.vertex[1].x;
            po.vertex[3].y = po.vertex[1].y;
        }

        bool coin = true;
        double inner[4];

        for (int i = 0; i < 4; ++i)
        {
            inner[i] = po.vertex[i] * cam;
            if (inner[i] < -0.2)
            {
                coin = false; // flip!
                break;
            }
        }

        if (!coin)
            continue;

        coordd prj[4];
        for (int i = 0; i < 4; ++i)
        {
            matrix3<double> mat = { vecX.x, vecY.x, cam.x,
                                    vecX.y, vecY.y, cam.y, 
                                    vecX.z, vecY.z, cam.z };
            
            coord3 transformed = mat.inverse() * (po.vertex[i] * SCR_DISTANCE / inner[i] - cam_center);
            
            prj[i] = {transformed.x, transformed.y};

            if (fabs(prj[i].x) < SCR_LENGTH / 2.0 && fabs(prj[i].y) < SCR_WIDTH / 2.0)
                coin = false;
        }

        if (coin)
            continue;

        for (coordd &p : prj)
        {
            p.x += SCR_LENGTH / 2;
            p.y += SCR_WIDTH / 2;
        }

        const coord coord_min = { max(min(min(prj[0].x, prj[1].x), min(prj[2].x, prj[3].x)) -1, 0.0),
                                  max(min(min(prj[0].y, prj[1].y), min(prj[2].y, prj[3].y)) -1, 0.0) };
        const coord coord_max = { min(max(max(prj[0].x, prj[1].x), max(prj[2].x, prj[3].x)) +1, static_cast<double>(SCR_LENGTH)),
                                  min(max(max(prj[0].y, prj[1].y), max(prj[2].y, prj[3].y)) +1, static_cast<double>(SCR_WIDTH)) };

        for (int y = coord_min.y; y < coord_max.y; ++y)
            for (int x = coord_min.x; x < coord_max.x; ++x)
            {
                coord loc = {x - SCR_LENGTH/2, y - SCR_WIDTH/2};
                coord3 dir = cam_center + vecX * loc.x + vecY * loc.y;
                coord3 trans = po.transform(dir);

                if ((scr[y][x].distance == -1.0 || scr[y][x].distance > trans.z) && trans.x >= 0 && trans.y >= 0
                                                                                 && trans.x < 1 && trans.y < 1)
                {
                    switch (po.type)
                    {
                    case TEXTURE_FLOOR:
                    {
                        scr[y][x].ch = '.';
                        break;
                    }
                    case TEXTURE_WALL:
                    {
                        const int texture_x = static_cast<int>(trans.x * 8);
                        const int texture_y = static_cast<int>(trans.y * 8);
                        scr[y][x].ch = po.texture[texture_y][texture_x];
                        break;
                    }
                    case TEXTURE_CHAR:
                    {
                        const int texture_x = static_cast<int>(trans.x * 8);
                        const int texture_y = static_cast<int>(trans.y * 8);

                        if (po.texture[texture_y][texture_x] == ' ')
                            continue;
                        scr[y][x].ch = po.texture[texture_y][texture_x];
                        break;
                    }
                    default:
                        break;                    
                    }

                    scr[y][x].distance = trans.z;
                }
            }
    }
}
