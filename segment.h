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
        Segment(Vector* v, Point<T>* r, T max, T min):V(v), R(r), tMax(max), tMin(min)
        {
        }

        /*Constructor with two points
         * This constructor finds the parametric form of a line segment
         * when it is constructed with two points
         * Take first point as the starting point
         * All Manhattan arcs have have a slope of
         * +1 => 45 or // to y=x line
         * -1 => -45 or // to y= -x line
         *  0 => // to x axis
         *  inf => // to y axis
         *  */
        Segment(Point<T>* p1, Point<T>* p2):R(p1), tMin(0.0)
        {
            int x,y;
            if(EQZERO(p1->X - p2->X))
            {
                x = 0;
            }
            else if(EQZERO(p1->Y - p2->Y))
            {
                y = 0;
            }
            else if(EQZERO((p1->Y - p2->Y)-(p1->X - p2->X)))
            {
                x = 1;
                y = 1;
            }
            else if(EQZERO((p1->Y - p2->Y)+(p1->X - p2->X)))
            {
                x = -1;
                y = 1;
            }
            else /*Shouldn't happen*/
            {
                x = 0;
                y = 0;
            } 
            V = new Vector(x, y);
            tMax =( p2->X - R->X)/(V->R);          
        }

        /*When the segment is actually a point*/
        Segment(Point<T> P):R(P),tMax(0.0), tMin(0.0)
        {
            /*In reality tMax and can be any value since 
             * V is zero */
            V = new Vector(0,0);
        }

        bool isPoint()
        {
            return tMax == tMin && tMax < EPSILON;
        }

        
    private:
        /* A line can be represented as
         * R+t*V 
         * t is parametrisized*/
        Vector* V;  
        Point<T>* R;

        /*A line segment is essentially a line which has a bound on the
         * parametric */
        double tMax;
        double tMin;
};

MANMATH_NAMESPACE_END 

#endif
