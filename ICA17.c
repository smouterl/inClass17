#include "data.h"
#include "sunspot_parser.h"
#include "minmax.h"
#include <stdio.h>
#include <stdlib.h>

#define GROWTH_SIZE 50

struct data allocate(struct data** ptr);
struct data *reallocate(struct data** ptr);
int deallocate(data* ptr);


void main(){

    FILE *fptr = fopen("sunspot.dat", "r");

    int curr_size = 250;

    struct data data_arr;
    allocate(data** data_arr);

    if (fptr == NULL) {
        printf("Error: Could not open file.\n");
    }

    char user_input[80];
    char *token1; 
    char *token2;

    int index = 0;

    do{
        fgets(user_input, 80, fptr);
        token1 = strtok(user_input, "   ");
        token2 = strtok(NULL, "   ");

        double temp[2] = getData(*token1, *token2);
        *(data_arr + index).year = temp[0];
        *(data_arr + index).value =  temp[1];

    }while(token1 != NULL);

    printf("average = %f", average(data_arr, curr_size));
    printf("min = %f", min(data_arr, curr_size));
    printf("max = %f", max(data_arr, curr_size));


    return 0;
}

    struct data allocate(struct data** ptr){
    ptr = malloc(curr_size*sizeof(struct data));
    return ptr;
    }

    struct data *reallocate(struct data** ptr){
    curr_size += GROWTH_SIZE;
    ptr = realloc(ptr, curr_size*sizeof(data));
    return ptr;
    }

    int deallocate(data* ptr){
        free(ptr);
        return 0;
    }