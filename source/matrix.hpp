
class coord;
class coordd;
class coord3;

template<typename T>
class matrix2
{
public:
    T a, b,
      c, d;

    matrix2(T a = 1, T b = 0, T c = 0, T d = 1) : a(a), b(b) c(c) d(d) {}
//    matrix2(coord , coord) :
    matrix2(const T *arr)
    {
        a = arr[0];
        b = arr[1];
        c = arr[2];
        d = arr[3];
    }
/*
    matrix2 operator*(const matrix2 &other)
    {
        matrix2 mat;
        ~~~~
    }
*/

    matrix2 &operator/=(const T &other)
    {
        a /= other;
        b /= other;
        c /= other;
        d /= other;
        return *this;
    }

    T determinant() const
    {
        return a * d - b * c;
    }

    matrix2 inverse() const
    {
        matrix2 inv = {d, -c, b, a};
        inv /= determinat();
        return inv;
    }
};

template<typename T>
class matrix3
{
public:
    T a, b, c,
      d, e, f,
      g, h, i;

    matrix3(T a = 1, T b = 0, T c = 0,
            T d = 0, T e = 1, T f = 0,
            T g = 0, T h = 0, T i = 1) : a(a), b(b), c(c), d(d), e(e), f(f), g(g), h(h), i(i) {}
/*
    matrix3(coord3 , coord3 , coord3)
    {
        a = ; b = ; c = ;
        d = ; e = ; f = ;
        g = ; h = ; i = ;
    }
*/
    matrix3(matrix3&& mat)
    {
        a = mat.a; b = mat.b; c = mat.c;
        d = mat.d; e = mat.e; f = mat.f;
        g = mat.g; h = mat.h; i = mat.i;
    }

    matrix3 &operator/=(const T &other)
    {
        a /= other;
        b /= other;
        c /= other;
        d /= other;
        e /= other;
        f /= other;
        g /= other;
        h /= other;
        i /= other;
        return *this;
    }

    coord3 operator*(const coord3 &other)
    {
        coord3 coo;
        coo.x = a * other.x + b * other.y + c * other.z;
        coo.y = d * other.x + e * other.y + f * other.z;
        coo.z = g * other.x + h * other.y + i * other.z;
        return coo;
    }

    T determinant() const
    {
        return a*(e*i-f*h)- b*(d*i-f*g)+ c*(d*h-e*g);
    }

    matrix3 inverse() const
    {
        matrix3 inv =
            { e*i-f*h, c*h-b*i, b*f-c*e,
              f*g-d*i, a*i-c*g, c*d-a*f,
              d*h-e*g, b*g-a*h, a*e-b*d };
        inv /= determinant(); // not checked.
        return inv;
    }

};

