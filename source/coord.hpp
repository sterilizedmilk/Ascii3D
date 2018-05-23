#pragma once

#include "define.hpp"

class coord
{
public:
    int x, y;
    coord(int x = 0, int y = 0) : x(x), y(y) {};
    coord(double x, double y) : x(static_cast<int>(x)), y(static_cast<int>(y)) {};

    coord operator+(const coord &b)
    {
        coord c;
        c.x = x + b.x;
        c.y = y + b.y;
        return c;
    }

    coord operator-(const coord &b)
    {
        coord c;
        c.x = x - b.x;
        c.y = y - b.y;
        return c;
    }

    coord operator*(const coord &b)
    {
        coord c;
        c.x = x * b.x;
        c.y = y * b.y;
        return c;
    }

    coord &operator-=(const coord &b)
    {
        x -= b.x;
        y -= b.y;
        return *this;
    }

    bool operator>(const coord &b)
    {
        if (x > b.x && y > b.y)
            return true;
        return false;
    }

    bool operator>=(const coord &b)
    {
        if (x >= b.x && y >= b.y)
            return true;
        return false;
    }

    bool operator<(const coord &b)
    {
        if (x < b.x && y < b.y)
            return true;
        return false;
    }

    bool operator<=(const coord &b)
    {
        if (x <= b.x && y <= b.y)
            return true;
        return false;
    }
};

const coord compass[8] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} };


class coordd
{
public:
    double x, y;
    coordd(double x = 0, double y = 0) : x(x), y(y) {};
    coordd(int x, int y) : x(x), y(y) {};
    coordd(coord c) : x(c.x), y(c.y) {};

    coordd operator+(const coordd &b)
    {
        coordd c;
        c.x = x + b.x;
        c.y = y + b.y;
        return c;
    }

    coordd operator-(const coordd &b)
    {
        coordd c;
        c.x = x - b.x;
        c.y = y - b.y;
        return c;
    }

    coordd operator*(const coord &b)
    {
        coordd c;
        c.x = x * b.x;
        c.y = y * b.y;
        return c;
    }

    coordd operator*(const double &b)
    {
        x *= b;
        y *= b;
        return *this;
    }

    coordd operator/(const double &b)
    {
        coordd c;
        c.x = x / b;
        c.y = y / b;
        return c;
    }

    coordd &operator*=(const double &b)
    {
        x *= b;
        y *= b;
        return *this;
    }
};


class coord3
{
public:
    double x, y, z;

    coord3(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {};
    coord3(int x, int y, int z) : x(static_cast<double>(x)), y(static_cast<double>(y)), z(static_cast<double>(z)) {};


    bool operator==(const coord3 &b)
    {
        if (x == b.x && y == b.y && z == b.z)
            return true;
        return false;
    }

    bool operator!=(const coord3 &b)
    {
        if (x == b.x && y == b.y && z == b.z)
            return false;
        return true;
    }

    coord3 &operator+=(const coord3 &b)
    {
        x += b.x;
        y += b.y;
        z += b.z;
        return *this;
    }

    coord3 &operator-=(const coord3 &b)
    {
        x -= b.x;
        y -= b.y;
        z -= b.z;
        return *this;
    }

    coord3 &operator*=(const double &b)
    {
        x *= b;
        y *= b;
        z *= b;
        return *this;
    }

    coord3 operator+(const coord3 &b)
    {
        coord3 c;
        c.x = x + b.x;
        c.y = y + b.y;
        c.z = z + b.z;
        return c;
    }

    coord3 operator-(const coord3 &b)
    {
        coord3 c;
        c.x = x - b.x;
        c.y = y - b.y;
        c.z = z - b.z;
        return c;
    }

    coord3 operator*(const double b)
    {
        coord3 c;
        c.x = x * b;
        c.y = y * b;
        c.z = z * b;
        return c;
    }

    double operator*(const coord3 &b) // inner
    {
        return x * b.x + y * b.y + z * b.z;
    }

    coord3 operator/(const double &b)
    {
        coord3 c;
        c.x = x / b;
        c.y = y / b;
        c.z = z / b;
        return c;
    };

    double square();
    double abs();
};


struct spher_coord
{
    double azimuth;      // degree with X in XY    clockwise
    double polar;        // degree with Z          only use absolute value.

    spher_coord(double azimuth = 0.0, double polar = PI / 2) : azimuth(azimuth), polar(polar) {};

    void spher_spin(double azi, double pol = 0.0);
    coord3 spher_to_coord3();
};
