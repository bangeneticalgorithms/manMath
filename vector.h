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

#endif
