#ifndef MINMAX_H
#define MINMAX_H

#include <stddef.h>
#include "data.h"

/* Return the minimum/maximum value as a float */
float sunspot_min(const data records[], size_t count);
float sunspot_max(const data records[], size_t count);

#endif /* MINMAX_H */
