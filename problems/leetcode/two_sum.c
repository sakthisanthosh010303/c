/*
 * Author: Sakthi Santhosh
 * Created on: 04/12/2022
 *
 * Element Range: 1 to 100
 *
 * Two Sum
 */
#include <stdio.h>

int main() {
  int size, counter1, counter2, target, map[100];

  printf("Enter size: ");
  scanf("%d", &size);

  int array[size];

  printf("Enter array: ");
  for (counter1 = 0; counter1 < size; counter1++)
    scanf("%d", array + counter1);

  printf("Enter target: ");
  scanf("%d", &target);

  for (counter1 = 0; counter1 < 100; counter1++)
    map[counter1] = -1;

  printf("\nResult: ");
  for (counter1 = 0; counter1 < size; counter1++) {
    map[array[counter1]] = counter1;
    counter2 = target - array[counter1];
    if (counter2 > 0 && counter2 < 100 && map[target - array[counter1]] != -1) {
      printf("%d %d\n", counter1, map[target - array[counter1]]);
      return 0;
    }
  }
  printf("(null)\n");
  return 0;
}
