#ifndef MINMAX_H
#define MINMAX_H

#include <stddef.h>
#include "data.h"

/* Return the minimum/maximum value as a float and store its year in *year.
 * Ties use the first matching record. Invalid input returns NAN.
 */
float sunspot_min(const data records[], size_t count, int *year);
float sunspot_max(const data records[], size_t count, int *year);

#endif /* MINMAX_H */
