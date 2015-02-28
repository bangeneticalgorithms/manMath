#ifndef __SEGMENT_H__
#define __SEGMENT_H__

#include <utility>


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
            tMax =( p2->X - R->X)/(V->K);          
        }

        /*When the segment is actually a point*/
        Segment(Point<T> P):R(P),tMax(0.0), tMin(0.0)
        {
            /*In reality tMax and can be any value since 
             * V is zero */
            V = new Vector(0,0);
        }

        /*is it a Point */
        bool isPoint()
        {
            return tMax == tMin && tMax < EPSILON;
        }

        bool isHorizontal()
        {
            return (V->K == 0);
        }
        
        bool isVertical()
        {
            return (V->L == 0);
        }


        /* Returns the points on the edges
         * */ 
        std::pair<Point<T>* , Point<T>* > getEdgePoints()
        {
            Point<T> *p1, *p2;
            *p1 = *R + tMin*(*V);
            *p2 = *R + tMax*(*V);

            return std::make_pair(p1,p2);
        }

        /* Checks if a given point is within the horizontal level 
         * as the segment */
        bool isInBetweenX(Point<T>* P)
        {
            return (P->X > (*R + tMin*(*V)).X) && (P->X < (*R + tMax*(*V)).X);
        }

        
        /* Checks if a given point is within the vertical level 
         * as the segment */
        bool isInBetweenY(Point<T>* P)
        {
            return (P->Y > (*R + tMin*(*V)).Y) && (P->Y < (*R + tMax*(*V)).Y);
        }


    private:
        /* A line can be represented as
         * R+t*V 
         * t is parametricized*/
        Vector* V;  
        Point<T>* R;

        /*A line segment is essentially a line which has a bound on the
         * parametric */
        double tMax;
        double tMin;
};

MANMATH_NAMESPACE_END 

#endif
