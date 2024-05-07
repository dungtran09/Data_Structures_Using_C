#include <stdio.h>

void insertion_sort (int*, int);

int main(int argc, char *argv[]) {
  
  int listNumnbers[] = {5, 2, 4, 6, 1, 3, 7};
  
  int size = sizeof(listNumnbers) / sizeof(int);

  insertion_sort(listNumnbers, size);
  
  // print affter sorted.
  for (int i = 0; i < size; i++) {
    printf("%d ", listNumnbers[i]);
  }
  return 0;
}

void insertion_sort(int* listNumnbers, int size) {
  for(int curr = 1; curr < size; curr++) {
    int key = listNumnbers[curr];
    int prev = curr - 1;
    while (prev >= 0 && listNumnbers[prev] > key) {
      listNumnbers[prev + 1] = listNumnbers[prev];
      prev = prev - 1;
    }
    listNumnbers[prev + 1] = key;
  }

}
