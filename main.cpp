#include <stdio.h>
#include "queue.h"

int main() {
  Tqueue q;
  const int size = 8, w = 3;
  int A[size] = { 5, 3, 7, 5, 9, 1, 8, 7 };
  int sum = 0;
  double An[size - w + 1];

  for (int i = 0; i < w; i++) {
    sum += A[i];
    q.push(A[i]);
  }

  int old, next;
  for (int i = w; i < size; i++) {
    An[i - w] = static_cast<double>(sum) / w;
    old = q.front();
    next = A[i];
    sum = sum - old + next;
    q.pop();
    q.push(next);
  }
  An[size - w] = static_cast<double>(sum) / w;

  for (int i = 0; i < size - w + 1; i++) {
    printf("%lf ", An[i]);
  }
  printf("\n");
}