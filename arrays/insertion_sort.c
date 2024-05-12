#include <stdio.h>

void insertion_sort (int*, int);

int main(int argc, char *argv[]) {
  
  int listNumnbers[] = {5, 2, 4, 6, 1, 3, 7};
  
  int size = sizeof(listNumnbers) / sizeof(int);

  // sorting
  insertion_sort(listNumnbers, size);
  
  // print affter sorted.
  for (int i = 0; i < size; i++) {
    printf("%d %s", listNumnbers[i], "\n");
  }

  return 0;
}

void insertion_sort(int* listNumnbers, int size) {
  for(int currPos = 1; currPos < size; currPos++) {
    int key = listNumnbers[currPos];
    int prevPos = currPos - 1;
    while (prevPos >= 0 && listNumnbers[prevPos] > key) {
      listNumnbers[prevPos + 1] = listNumnbers[prevPos];
      prevPos--;
    }
    listNumnbers[prevPos + 1] = key;
  }
}

