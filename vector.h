#ifndef __VECTOR_H__
#define __VECTOR_H__

struct Vector
{
    /* All Manhattan arcs have have a slope of
     * 1 => 45 or // to y=x line
     * -1 => -45 or // to y= -x line
     *  0 => // to x axis
     *  inf => // to y axis
     *  Therefore there is no need for templated values
     *  for this struct */
    
    int K;
    int L;

    /*Constructor */
    Vector(int k, int l): K(k), L(l) {};
};

template <typename T>
Vector operator*(T t, Vector V)
{
    Vector newV((int)t*(V.K),(int)t*(V.L));

    return newV;
};

template <typename T>
Vector operator+(T t, Vector V)
{
    Vector newV((int)t+(V.K),(int)t+(V.L));

    return newV;
};

Vector operator+(Vector V,Vector W)
{
    Vector newV((V.K)+(W.K),(V.L)+(W.L));

    return newV;
};

Vector operator-(Vector V,Vector W)
{
    Vector newV((V.K)-(W.K),(V.L)-(W.L));

    return newV;
};

#endif
