#include "minmax.h"
#include <math.h>

float sunspot_min(const data records[], size_t count)
{
    if (records == NULL || count == 0) {
        return NAN;
    }

    double minimum = records[0].value;
    for (size_t i = 1; i < count; ++i) {
        if (records[i].value < minimum) {
            minimum = records[i].value;
        }
    }
    return (float)minimum;
}

float sunspot_max(const data records[], size_t count)
{
    if (records == NULL || count == 0) {
2    }

    double maximum = records[0].value;
    for (size_t i = 1; i < count; ++i) {
        if (records[i].value > maximum) {
            maximum = records[i].value;
        }
    }
    return (float)maximum;
}
