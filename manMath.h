#ifndef __MANMATH_H__
#define __MANMATH_H__

#include "point.h"
#include "vector.h"
#include "segment.h"

#include "manMath_utils.h"

#include <vector>

MANMATH_NAMESPACE_BEGIN

/*Manhattan distance between 2 segments */
template <typename T>
T getDistance(Segment<T>* s1, Segment<T>* s2)
{
    if(s1->isPoint() && s2->isPoint)
    {
        return getDistance(s1->R, s2->R);
    }
}

/*Distance between two points*/
template <typename T>
T getDistance(Point<T>* p1, Point<T>* p2)
{
    return ABS(p1->X - p2->X) + ABS(p1->Y - p2->Y);
}


/*Get the list of points/Manhattan arc that 
 * are equidistant from 2 Points */
template <typename T>
Segment<T>* p2pManArc(Segment<T>* p1, Segment<T>* p2);

/* get the manhattan distance between two line segments*/
template <typename T>
Segment<T>* getDistanceL2L(Segment<T>* p1, Segment<T>* p2);

MANMATH_NAMESPACE_END

#endif

