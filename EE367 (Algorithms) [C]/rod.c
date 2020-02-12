//Jake Castillo
#include <stdlib.h>
#include <stdio.h>
#define P_LENGTH 20

int p[] = {
  0,
  1,
  3,
  4,
  6,
  10,
  9,
  13,
  16,
  14,
  17,
  23,
  20,
  21,
  28,
  27,
  24,
  34,
  25,
  25,
  24
};

int total_price_iter(int p[], int length, int memo[], int cut[]) {
  if (length <= 0) return 0;
  if (memo[length] == 0) {
    if (length == 1) {
      memo[1] = p[1];
    } else {
      int best_cut = 0;
      int best_value = 0;
      for (int k = 1; k <= length; k++) {
        int temp = p[k] + total_price_iter(p, length - k, memo, cut);
        if (best_value < temp) {
          best_value = temp;
          best_cut = k;
          if (k > cut[length]) {
            cut[length] = k;
          }
        }
      }
      memo[length] = best_value;
    }
  }
  return memo[length];
}


void total_price(int p[], int length) {
  int * memo = (int * ) malloc((length + 1) * sizeof(int));
  int * cut = (int * ) malloc((length + 1) * sizeof(int));
  for (int i = 0; i <= length; i++) {
    memo[i] = 0;
    cut[i] = 0;
  }

  int sum = total_price_iter(p, length, memo, cut);
  printf("Sum of prices of rods: %d\n", sum);

  printf("Memo: ");
  for (int i = 0; i <= length; i++) {
    printf("%d ", memo[i]);
  }
  printf("\n");

  printf("Cuts on the original rod: ");
  for (int total = 0; length != 0; length -= cut[length]) {
    total += cut[length];
    printf("%d ", total);
  }
  printf("\n");

  free(cut);
  free(memo);
}

void main() {
  printf("Prices of rod lengths [0 through 20]:\n");
  for (int i = 0; i <= P_LENGTH; i++) {
    printf("%d ", p[i]);
  }
  printf("\n");

  total_price(p, P_LENGTH);
}
