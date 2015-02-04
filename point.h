/* This header file contains the struct for a point
 * the type of X and Y could be of any numerical type
 * as long as they are of the same type
 */

#ifndef __POINT_H__
#define __POINT_H__

template <typename T>
class Point
{
    T X;
    T Y;

    Point(T x, T y):X(x), Y(y){}
};

/*Is a given point gP in between 
 * two target points tP1 and tP2
 */
template <typename T>
bool inBetween(Point<T>* gP, Point<T>* tP1, Point<T>* tP2)
{
    T maxX = (tP1->X > tP2->X) ? tP1->X : tP2->X ;
    T maxY = (tP1->Y > tP2->Y) ? tP1->Y : tP2->Y ;
    T minX = (tP2->X > tP1->X) ? tP1->X : tP2->X ;
    T minY = (tP2->Y > tP1->Y) ? tP1->Y : tP2->Y ;

    return ((gP->X > minX) &&(gP->X < maxX)) || ((gP->Y > minY) &&(gP->X < maxY));

}

template <typename T>
Point<T>* operator+(Point<T>* p1, Point<T>* p2)
{
    Point<T>* P = new Point<T>(p1->X + p2->X , p1->Y + p2->Y);
    return P;
}
#endif
