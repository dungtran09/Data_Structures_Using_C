#include <stdio.h>

void merge_sort(int*, int, int);
void merge(int*, int, int, int);

int main(int argc, char *argv[]) {
  int originList[] = {12, 3, 7, 9, 14, 6, 11, 2};
  int left = 0;
  int right = sizeof(originList) / sizeof(originList[0]);

  // before sort
  printf("%s \n", "Before sort: ");
  for (int i = 0; i < right; i++) {
    printf("%d ", originList[i]);
  }
 
  printf("\n%s \n", "After sorted: ");
  merge_sort(originList, left, right - 1);

  // printf after sorted
  for (int i = 0; i < right; i++) {
    printf("%d ", originList[i]);
  }
  
  return 0;

}

void merge_sort(int* originList, int left, int right) {
  if (left >= right) return;
  
  int mid = left + (right - left) / 2;

  merge_sort(originList, left, mid);
  merge_sort(originList, mid + 1, right);

  merge(originList, left, mid, right);
}

void merge(int* originList, int left, int mid, int right) {
  int i, j, k;
  int sizeLeft = mid - left + 1;
  int sizeRight = right - mid;
  int leftList[sizeLeft], rightList[sizeRight];

  for (i = 0; i < sizeLeft; i++) {
    leftList[i] = originList[left + i];
  }

  for (j = 0; j < sizeRight; j++) {
    rightList[j] = originList[mid + j + 1];
  }
  

  i = 0, j = 0;
  k = left;

  while (i < sizeLeft && j < sizeRight) {
    if (leftList[i] <= rightList[j]) {
      originList[k] = leftList[i];
      i++;
    } else {
      originList[k] = rightList[j];
      j++;
    }
    k++;
  }

  while (i < sizeLeft) {
    originList[k] = leftList[i];
    i++;
    k++;
  }
  while (j < sizeRight) {
    originList[k] = rightList[j];
    j++;
    k++;
  }
}
