#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include "point.h"
#include "vector.h"

#include "manMath_utils.h"

MANMATH_NAMESPACE_BEGIN

template <typename T>
class Segment
{
    public:
        /*Default Constructor*/
        Segment(Vector<T>* v, Point<T>* r, T max, T min):V(v), R(r), tMax(max), tMin(min){}

        /*Constructor with two points
         * This constructor finds the parametric form of a line segment
         * when it is constructed with two points
         * Take first point as the starting point
         * and the second point is the ending point
         * Hence => tMin =0 tMax =1*/
        Segment(Point<T>* p1, Point<T>* p2):R(p1), tMin(0.0), tMax(1.0)
        {
            /*Then use the two points to calculate V*/
            T _x = p2->X - p1->X;
            T _y = p2->Y - p1->Y;

            V = new Vector(_x,_y);
        }

        /*When the segment is actually a point*/
        Segment(Point<T> P):R(P),tMax(0.0), tMin(0.0)
        {
            V = new Vector<T>(0,0);
        }

        bool isPoint()
        {
            return tMax == tMin && tMax < EPSILON;
        }

        
    private:
        /* A line can be represented as
         * R+t*V 
         * t is parametrisized*/
        Vector<T>* V;  
        Point<T>* R;

        /*A line segment is essentially a line which has a bound on the
         * parametric */
        double tMax;
        double tMin;


};

MANMATH_NAMESPACE_END 

#endif
