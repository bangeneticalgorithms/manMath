#ifndef __MANMATH_H__
#define __MANMATH_H__

#include "point.h"
#include "vector.h"
#include "segment.h"

#include "manMath_utils.h"

MANMATH_NAMESPACE_BEGIN

/*Manhattan distance between 2 points */
template <typename T>
Segment<T>* getDistanceP2P(Point<T>* p1, Point<T>* p2)
{
    return ABS(p1->X - p2->X) + ABS(p1->Y - p2->Y);
}

/*Get the list of points/Manhattan arc that 
 * are equidistant from 2 Points */
template <typename T>
Segment<T>* p2pManArc(Point<T>* p1, Point<T>* p2);

/* get the manhattan distance between two line segments*/
template <typename T>
Segment<T>* getDistanceL2L(Point<T>* p1, Point<T>* p2);


MANMATH_NAMESPACE_END

#endif

