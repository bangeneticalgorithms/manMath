#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "point.h"
#include "vector.h"

template <typename T>
class Segment
{
    public:
        /*Default Constructor*/
        Segment(Vector<T>* v, Point<T>* r, T max, T min):V(v), R(r), tMax(max), tMin(min){}

        /*Constructor with two points
         * This constructor finds the parametric form of a line segment
         * when it is constructed with two points*/
        Segment(Point<T>* p1, Point<T>* p2)
        {

        }

    private:
        Vector* V; 
        Point* R;
        T tMax;
        T tMin;


};
