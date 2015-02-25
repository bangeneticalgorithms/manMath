
#ifndef __TRR_H__
#define __TRR_H__

#include <utility>
#include <vector>

#include "point.h"
#include "vector.h"
#include "segment.h"

#include "manMath_utils.h"

MANMATH_NAMESPACE_BEGIN

template <typename T>
class TRR
{
    public:

        
    private:
        Segment<T>* Core;  
        T radius;
        std::vector<Segment<T>*> boundary;

};

MANMATH_NAMESPACE_END 

#endif
