/**
File: minmax.c
Author: Logan Smouter
Date: 10/12/2026
Description: Finds the minimum and maximum values in an array of data records
 */
#include "minmax.h"
#include <math.h>

float sunspot_min(const data records[], size_t count, int *year)
{
    if (records == NULL || count == 0 || year == NULL) {
        return NAN;
    }

    double minimum = records[0].value;
    *year = records[0].year;
    for (size_t i = 1; i < count; ++i) {
        if (records[i].value < minimum) {
            minimum = records[i].value;
            *year = records[i].year;
        }
    }
    return (float)minimum;
}

float sunspot_max(const data records[], size_t count, int *year)
{
    if (records == NULL || count == 0 || year == NULL) {
        return NAN;
    }

    double maximum = records[0].value;
    *year = records[0].year;
    for (size_t i = 1; i < count; ++i) {
        if (records[i].value > maximum) {
            maximum = records[i].value;
            *year = records[i].year;
        }
    }
    return (float)maximum;
}
