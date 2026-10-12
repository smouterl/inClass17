/**
File: sunspot_parser.c
Author: Blake Ackland
Date: 10/12/2026
Description: Takes two tokens and makes a double array
 */
#include <stdlib.h>

double *getData(char *year, char *value)
{
    double yearValue[2];
    char *endT1;
    char *endT2;

    yearValue[0] = strtod(year, &endT1);
    yearValue[1] = strtod(value, &endT2);

    return yearValue;
}