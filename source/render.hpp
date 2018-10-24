#include "coord.hpp"
#include "define.hpp"

using namespace std;

enum shape_type
{
    SHP_TRI = 0,
    SHP_REC,
    SHP_CIR,
    NUM_SHAPES,
};

enum texture_type;

class polygon
{
public:
    shape_type shape;
    texture_type type;
    char (*texture)[8+1];
    coord3 vertex[4];

public:
    polygon(shape_type shp, texture_type typ, char(*tex)[8+1], coord3 ver[4])
    {
        shape = shp;
        type = typ;
        texture = tex;

        for (int i = 0; i < 4; ++i)
        {
            vertex[i] = ver[i];
        }
    }

    polygon(shape_type shp, texture_type typ, char (*tex)[8+1],
                                              coord3 ver0,
                                              coord3 ver1,
                                              coord3 ver2,
                                              coord3 ver3)
    {
        shape = shp;
        type = typ;
        texture = tex;
        vertex[0] = ver0;
        vertex[1] = ver1;
        vertex[2] = ver2;
        vertex[3] = ver3;
    }

    // unnecessary yet
    polygon(const polygon& poly)
    {
        shape = poly.shape;
        type = poly.type;
        texture = poly.texture;
        vertex[0] = poly.vertex[0];
        vertex[1] = poly.vertex[1];
        vertex[2] = poly.vertex[2];
        vertex[3] = poly.vertex[3];
    }

    coord3 transform(coord3 dir) const;
    polygon &operator-=(const coord3 &c)
    {
        for (coord3 &v : vertex)
            v -= c;

        return *this;
    }
};

class screen
{
public:
    char ch = ' ';
    double distance;
    //    color
};

void make_poly(std::vector<polygon> &polygons, char** map, int map_x, int map_y);
void screen_assign(const coord3 &cam_pos, const spher_coord &cam_dir, const vector<polygon> &polygons, screen scr[][SCR_LENGTH]);
