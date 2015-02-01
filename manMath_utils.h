
#ifndef __MANMATH_UTILS_H__ 
#define __MANMATH_UTILS_H__

#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif

#ifndef ABS
#define ABS(a) (((a) < (0)) ? ((a) * ((typeof((a)))(-1))) : ((a)))
#endif


//make sure that true and false are actually defined and in lowercase. 
#ifndef TRUE
#define TRUE (1==1)
#endif

#ifndef true
#define true (TRUE)
#endif

#ifndef FALSE
#define FALSE (!(TRUE))
#endif

#ifndef false
#define false (FALSE)
#endif

#ifndef MANMATH_NAMESPACE
#define MANMATH_NAMESPACE manMath
#endif

#ifndef MANMATH_NAMESPACE_BEGIN
#define MANMATH_NAMESPACE_BEGIN namespace MANMATH_NAMESPACE {
#endif


#ifndef MANMATH_NAMESPACE_END
#define MANMATH_NAMESPACE_END }
#endif


#endif
