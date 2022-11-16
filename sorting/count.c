/*
 * Author: Sakthi Santhosh
 * Created on: 16/11/2022
 *
 * Count Sort (0-9)
 */
#include <stdio.h>
#include <stdlib.h>

int *count_sort(int *array, int size) {
  int counter1;
  int largest = 0;
  int *result = (int *) malloc(sizeof(int) * size);

  for (counter1 = 0; counter1 < size; counter1++) {
    if (array[counter1] > largest) largest = array[counter1];
  }

  int count_map[largest + 1];

  for (counter1 = 0; counter1 <= largest; counter1++)
    count_map[counter1] = 0;

  for (counter1 = 0; counter1 < size; counter1++)
    count_map[array[counter1]]++;
  for (counter1 = 1; counter1 <= largest; counter1++)
    count_map[counter1] += count_map[counter1 - 1];

  for (counter1 = size - 1; counter1 >= 0; counter1--) { // Reversed for stability.
    result[--count_map[array[counter1]]] = array[counter1];
  }
  return result;
}

int main() {
  int size, counter1;

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", &array[counter1]);

  printf("\nSorted array: ");
  int *result = count_sort(array, size);
  for (counter1 = 0; counter1 < size; counter1++)
    printf("%d ", result[counter1]);
  printf("\n");
  free(result);
  return 0;
}
