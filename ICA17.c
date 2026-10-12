#include "data.h"
#include "sunspot_parser.h"
#include "minmax.h"
#include "average.h"
#include <stdio.h>code
#include <stdlib.h>
#include <string.h>

#define GROWTH_SIZE 50

data *allocate(data* ptr, int size);
data *reallocate(data* ptr, int size);
int deallocate(data* ptr);


int main(){

    FILE *fptr = fopen("sunspot.dat", "r");

    int curr_size = 50;

    data *data_arr;
    data_arr = allocate(data_arr, curr_size);
    printf("this happen allocate\n");

    if (fptr == NULL) {
        printf("Error: Could not open file.\n");
    }

    char user_input[80];
    char *token1; 
    char *token2;

    int index = 0;

    do{
        fgets(user_input, 80, (fptr+index));
        printf("this happen 1\n");
        strcpy(token1, strtok(user_input, "   "));
        strcpy(token2, strtok(NULL, "   "));
        printf("this happen 2\n");
        if(index < curr_size){
            double *temp = getData(token1, token2);
            ((data_arr + index)->year) = *temp;
            ((data_arr + index)->value) =  *(temp+1);
            index++;
        } else {
            data_arr = reallocate(data_arr, curr_size);
        }
        
    }while(token1 != NULL);

    printf("average = %f", average(data_arr, curr_size));
    printf("min = %f", sunspot_min(data_arr, curr_size));
    printf("max = %f", sunspot_max(data_arr, curr_size));

    return 0;
}

    data *allocate(data* ptr, int size){
    ptr = malloc(size*sizeof(data));
    return ptr;
    }

    data *reallocate(data* ptr, int size){
    size += GROWTH_SIZE;
    ptr = realloc(ptr, size*sizeof(data));
    return ptr;
    }

    int deallocate(data* ptr){
        free(ptr);
        return 0;
    }