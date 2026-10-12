#include <stdio.h>
#include <data.h>



float average(const data *array, int size) {
    float average;
    float sum = 0.0f;
    if (size <= 0) {
        return 0.0f;
    }

    for (int i = 0; i < size; i++) {
        sum += array[i].value;
    }

    average = sum/size;

    return average;
}