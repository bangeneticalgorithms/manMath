#ifndef __SEGMENT_H__
#define __SEGMENT_H__

template <typename T>
struct Segment
{
    Vector* V;
    Point* R;

    T tMax;
    T tMin;

};
