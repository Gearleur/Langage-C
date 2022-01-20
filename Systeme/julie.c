#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "julie.h"

int bisext(int x)
{
    if( x % 4 != 0)
        return 0;
    if( x % 100 != 0 )
        return 1;
    if ( x % 400 != 0 )
        return 0;
    return 1;
}

int bisext2(int x)
{
    if( (x % 4 == 0 && x % 100 != 0) || x % 400 == 0 )
        return 1;
    return 0;
}