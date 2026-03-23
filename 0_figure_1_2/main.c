/**
 * Date     : 23 March 2026
 * Author   : Efraim Manurung
 * email    : efraim.manurung@gmail.com
 *
 * Figure 1.2 from the textbook "Invitation to Computer Science" by G. Michael
 * Schneider and Judith L. Gersting, 7th edition, 2016.
 *
 * Given: m >/ 1 and two positive numbers each containing m digits,
 * a_m-1 a_m-2 ... a_0 and b_m-1 b_m-2 ... b_0.
 *
 * Wanted: c_m-1 c_m-2 ... c_0, where c_m c_m-1 c_m-2 ... c_0 = (a_m-1 a_m-2 ...
 * a_0) + (b_m-1 b_m-2 ... b_0).
 *
 * Algorithm:
 * step 1: Set the value of carry to 0
 * step 2: Set the value of i to 0
 * Step 3: While the value of i is less than or equal to m-1, repeat the
 * instructions in steps 4 through 6
 * Step 4:      Add the two digits a_i and b_i to the current value of carry to
 * get c_i
 * Step 5:      If c_i => 10, then reset c_i to (c_i - 10) and reset the
 * value of carry to 1; otherwise, set the new value of carry to 0
 * Step 6: Add 1 to i, effectively moving one column to the left
 * Step 7: Set c_m to the value of carry
 * Step 8: Print out the final answer, c_m c_m-1 c_m-2 ... c_0
 * Step 9: Stop
 *
 *  */

#include <stdio.h>

int a[2] = {7, 4}; // a[0]=7, a[1]=4 → represents 47
int b[2] = {5, 2}; // b[0]=5, b[1]=2 → represents 25
int c[3];

/* step 1 */
int carry = 0;
/* step 2 */
int i = 0;

size_t m = sizeof(a) / sizeof(a[0]);

// int m = 2;

int main() {
  printf("Program of Figure 1.2 exercise has started!");

  while (i <= (m - 1)) {
    c[i] = a[i] + b[i] + carry;

    printf("c[%d]: %d\n", i, c[i]);

    if (c[i] >= 10) {
      /* reset c_i to (c_i - 10) */
      c[i] = c[i] - 10;

      printf("reset c[%d]: %d\n", i, c[i]);
      /* reset the value of carry to 1 */
      carry = 1;
    } else {
      carry = 0;
    }

    i += 1;
  }

  /* set c_m to the value of carry */
  c[m] = carry;

  /* print out the final answer, c_m, c_m-1, c_m-2... c_0 */
  for (int j = m; j >= 0; j--) {
    printf("c_%i %d,", j, c[j]);
  }

  return 0;
};