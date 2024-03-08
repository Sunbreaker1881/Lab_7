// Evan Suarez
// Lab 7

#include <stdio.h>

void bubblesort(int array[], int size, int swap_counter[]) 
{
    int total_swaps = 0; // initialize total swaps counter
    int temp_swap = 0; // placeholder for swaping the swap counter
    for (int i = 0; i < size - 1; i++) 
    {
        for (int j = 0; j < size - i - 1; j++) 
        {
            if (array[j] > array[j + 1]) 
            {
                // swap element in array
                int n = array[j];
                array[j] = array[j + 1];
                array[j + 1] = n;

                // increment the counters
                swap_counter[j]++;
                swap_counter[j + 1]++;

                // swap the counters in the array
                temp_swap = swap_counter[j];
                swap_counter[j] = swap_counter[j + 1];
                swap_counter[j + 1] = temp_swap;

                // total swaps
                total_swaps++;
            }
        }
    }

    // printing the results
    for (int i = 0; i < size; i++) 
    {
        printf("%d: %d\n", array[i], swap_counter[i]);
    }
    printf("Total number of swaps: %d\n\n", total_swaps); // print total swaps
}

void selectionsort(int array[], int size, int swap_counter[]) 
{
    // set the counter to 0 again
    int total_swaps = 0;
    int temp_swap = 0;
    for (int i = 0; i < size; i++) 
    {
        swap_counter[i] = 0;
    }
    int min_index = 0;
    int temp = 0;

    // set min index equal to the lowest number
    for (int i = 0; i < size - 1; i++) 
    {
        min_index = i;

        for (int j = i + 1; j < size; j++) 
        {
            if (array[j] < array[min_index]) 
            {
                min_index = j;
            }
        }

        // swap elements
        if (array[min_index] != array[i]) 
        {
            // increment counters
            swap_counter[i]++;
            swap_counter[min_index]++;

            // swap counter postions
            temp_swap = swap_counter[i];
            swap_counter[i] = swap_counter[min_index];
            swap_counter[min_index] = temp_swap;

            // swap elements
            temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;

            // increment total counter
            total_swaps++;
        }
    }

    // print results
    for (int i = 0; i < size; i++) 
    {
        printf("%d: %d\n", array[i], swap_counter[i]);
    }
    printf("Total number of swaps: %d\n\n", total_swaps); // Print total swaps
}

int main() 
{
    // inital arrays 
    int array[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int temp_array_1[9];
    int temp_array_2[9];
    int swap_counter_1[9] = {0};
    int swap_counter_2[9] = {0};

    // copying array to temp array
    for (int i = 0; i < 9; i++) {
        temp_array_1[i] = array[i];
        temp_array_2[i] = array2[i];
    }

    // inital size of arrays 
    int size = sizeof(array) / sizeof(array[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    // function calls
    printf("Bubble sort for Array 1\n");
    bubblesort(array, size, swap_counter_1);

    printf("Bubble sort for Array 2\n");
    bubblesort(array2, size, swap_counter_2);

    printf("Selection sort for Array 1\n");
    selectionsort(temp_array_1, size, swap_counter_1);

    printf("Selection sort for Array 2\n");
    selectionsort(temp_array_2, size2, swap_counter_2);

    return 0;
}
