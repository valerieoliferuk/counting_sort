// Counting Sort Algorithm
// done by Valeria Oliferuk, KM-32

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "IO_functions.h"

// Function for searching for the largest element on array
void largest_el_search(int *p_arr, int size, int *var_value) {
  for (int i = 0; i < size; ++i) {
    if ((*(p_arr + i)) > *var_value) {
      *var_value = *(p_arr + i);
    }
  }
}

int counting_sort(int input_array[], int size_of_array, int sorted_array[]){
    // K - the largest element in an initial array
    int K = 0;
    //searching for the largest element in an array
    largest_el_search(input_array, size_of_array, &K);
    
    // Dynamically allocate memory for the counting array with size K+1
    int *counting_array = (int*)malloc((K+1) * sizeof(int));

    // Set all the elements of a counting array to zero
    for (int i = 0; i < K; i++) {
        counting_array[i] = 0;
    }

    //looping throught initial array to count the number of occurences of every element
    for (int i=0; i < size_of_array; ++i){
        counting_array[input_array[i]]++;

    }
    // Loop for C[i] to hold not only amount of i-element in input array, but also previous element
    for (int i = 1; i<= K; i++){
        counting_array[i] += counting_array[i-1];
    }
    // Loop for placing each element of initial array on the correct positions in sorted array
    for (int i=size_of_array-1; i>=0; i--){
        sorted_array[counting_array[input_array[i]]-1] = input_array[i];
        counting_array[input_array[i]]--;
    }

    // Free dynamically allocated memory
    free(counting_array);

    return 0;
}

int main(){
    int user_response = 0;
    int size_of_array = 0;
    // Get the size of array from user
    printf("Enter the size of an array[5-100]: ");
    size_of_array = checking_func(5, 100);

    // Dynamically allocate memory for the arrays
    int *initial_array = (int*)malloc(size_of_array*sizeof(int));
    int *sorted_array = (int*)malloc(size_of_array*sizeof(int));

    printf("Input the array manually - enter 1,\ncreate an array with random numbers - enter 2 ");
    user_response = checking_func(1,2);

    if (user_response==1){
        array_input(initial_array, size_of_array);
    }else{
        array_with_random_elem(initial_array, size_of_array);
    }

    printf("\nInitial array: ");
    array_print(initial_array,size_of_array);

    counting_sort(initial_array, size_of_array, sorted_array);
    
    printf("\nSorted array: ");
    array_print(sorted_array, size_of_array);

    // Free dynamically allocated memory
    free(initial_array);
    free(sorted_array);
    return 0;
}