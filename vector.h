#ifndef __VECTOR_H__
#define __VECTOR_H__

template <typename T>
struct Vector
{
    T R;
    T S;

    /*Constructor */
    Vector(T r, T s): R(r), S(s) {};
};

#endif
