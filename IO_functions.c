#include <time.h>
#include <stdio.h>
#include <stdlib.h>
// Function to check if number is in given range
int checking_func(int lower_limit, int upper_limit) {
    int input;
    int read_num;
    while (1) {
        read_num = scanf("%d", &input);
        if (read_num == 1 && (input >= lower_limit && input <= upper_limit)) {
            break;
        } else {
            printf("Enter the number from %d to %d included\n", lower_limit, upper_limit);
            while (getchar() != '\n')
                ;
        }
    }
    return input;
}

// Function for checking input of array with fixed size
void array_input(int array[], int size_of_array) {
  printf("Enter %d elements of array from range [0,100]", size_of_array);
  for (int i=0; i < size_of_array; ++i){
    printf("\nArray[%d] ", i);
    array[i] = checking_func(0, 100);
  }
}

// Function for creating an array with fixed size with random numbers
void array_with_random_elem(int array[], int size_of_array){
    srand(time(NULL));
    for (int i = 0; i < size_of_array; ++i) {
        *(array + i) = rand() % 1000;
  }
}

// Function for outputting the array
void array_print(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d ", array[i]);
  }
  printf("\n");
}