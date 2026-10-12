#include "data.h"
#include "sunspot_parser.h"
#include "minmax.h"
#include "average.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GROWTH_SIZE 50

data *allocate(data* ptr, int size);
data *reallocate(data* ptr, int size);
int deallocate(data* ptr);


int main(){

    FILE *fptr = fopen("sunspot.dat", "r");

    int curr_size = 50;

    data *data_arr = NULL;
    data_arr = allocate(data_arr, curr_size);

    if (fptr == NULL) {
        printf("Error: Could not open file.\n");
        deallocate(data_arr);
        return 1;
    }
    if(data_arr == NULL){
        fclose(fptr);
        return 1;
    }

    char user_input[80];
    char *token1; 
    char *token2;

    int index = 0;

    while(fgets(user_input, 80, fptr) != NULL){
        token1 = strtok(user_input, " \t\r\n");
        token2 = strtok(NULL, " \t\r\n");
        if(token1 == NULL || token2 == NULL){
            continue;
        }

        if(index == curr_size){
            data *temp = reallocate(data_arr, curr_size);
            if(temp == NULL){
                deallocate(data_arr);
                fclose(fptr);
                return 1;
            }
            data_arr = temp;
            curr_size += GROWTH_SIZE;
        }
        double *temp = getData(token1, token2);
        ((data_arr + index)->year) = *temp;
        ((data_arr + index)->value) =  *(temp+1);
        index++;
        
    }

    printf("Average = %f\n", average(data_arr, index));
    printf("Min = %f\n", sunspot_min(data_arr, index));
    printf("Max = %f\n", sunspot_max(data_arr, index));

    deallocate(data_arr);
    fclose(fptr);
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
