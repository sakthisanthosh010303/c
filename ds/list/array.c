/*
 * Author: Sakthi Santhosh
 * Created on: 23/27/2022
 *
 * List Implementation - Array
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

// Globals
int array[MAX_SIZE];
int end = 0;

// UDMs
int is_empty() {
  return !end;
}

int is_full() {
  return end == MAX_SIZE;
}

int out_range(int position) {
  return position < 1 || position - 1 > end;
}

int read(int position) {
  if (is_empty()) {
    printf("\n\033[31;01mError:\033[00m Array empty.\n");
    return -1;
  }
  if (out_range(position)) {
    printf("\n\033[31;01mError:\033[00m Invalid read position.\n");
    return -1;
  }

  printf("\n");
  return array[position - 1];
}

void write(int position, int data) {
  if (is_empty()) {
    printf("\n\033[31;01mError:\033[00m Array empty.\n");
    return;
  }
  if (out_range(position)) {
    printf("\n\033[31;01mError:\033[00m Invalid write position.\n");
    return;
  }

  array[position - 1] = data;
  return;
}

void insert(int position, int data) {
  if (is_full()) {
    printf("\n\033[31;01mError:\033[00m Array overflow.\n");
    return;
  }
  if (out_range(position)) {
    printf("\n\033[31;01mError:\033[00m Invalid insert position.\n");
    return;
  }

  int counter1;

  for (counter1 = end; counter1 > position - 1; counter1--) {
    array[counter1] = array[counter1 - 1];
  }
  array[position - 1] = data;
  end++;
  return;
}

int delete(int position) {
  if (is_empty()) {
    printf("\n\033[31;01mError:\033[00m Array underflow.\n");
    return -1;
  }
  if (out_range(position)) {
    printf("\n\033[31;01mError:\033[00m Invalid remove position.\n");
    return -1;
  }

  int counter1;
  int temp = array[position - 1];

  printf("\n");
  for (counter1 = position; counter1 < end; counter1++) {
    array[counter1 - 1] = array[counter1];
  }
  end--;
  return temp;
}

void display() {
  if (is_empty()) {
    printf("\n\033[31;01mError:\033[00m Array empty.\n");
    return;
  }

  int counter1;

  printf("\nDisplay: ");
  for (counter1 = 0; counter1 < end; counter1++) {
    printf("%d ", array[counter1]);
  }
  printf("\n");
  return;
}

int main() {
  int data, operation, position;
  short flag = 1;

  printf("\033[35;01mArray Operations\033[00m\n1 - Read\n2 - Write\n3 - Insert\n4 - Remove\n5 - Display\n6 - Exit\n");
  while (flag) {
    printf("\nOperation: ");
    scanf("%d", &operation);

    // Not using switch() to avoid code redundancy.
    if (operation > 0 && operation < 7) {
      if (operation == 6) {
        printf("\nExit\n");
        return 0;
      } else if (operation == 5) {
        display();
        continue;
      }

      printf("Enter position: ");
      scanf("%d", &position);
      if (operation == 1) {
        printf("Read: %d\n", read(position));
        continue;
      } else if (operation == 4) {
        printf("Remove: %d\n", delete(position));
        continue;
      }

      printf("Enter data: ");
      scanf("%d", &data);
      if (operation == 2) {
        write(position, data);
      } else if (operation == 3) {
        insert(position, data);
      }
    } else {
      printf("\n\033[31;01mError:\033[00m Invalid operation.\n");
    }
  }
}
