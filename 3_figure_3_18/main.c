/**
 * Date     : 23 March 2026
 * Author   : Efraim Manurung
 * email    : efraim.manurung@gmail.com
 *
 * Chapter 3 - The Efficiency of Algorithms
 * 3.4.2 Binary Search
 *
 * Figure 3.18 from the textbook "Invitation to Computer Science" by G. Michael
 * Schneider and Judith L. Gersting, 7th edition, 2016.
 *
 * Algorithm:
 * Get values for NUMBER, n, T_1,..., T_n and N_1,..., N_n
 * Set the value of beginning to 1 and set the value of Found to NO
 * Set the value of end to n
 * While Found = NO and beginning is less than or equal to end to Steps 5
 * through 10 Set the value of m to the middle value between beginning and end
 *      if NUMBER = T_m, the number found at the midpoint between beginning
 *      and end, then do Steps 7 and 8
 *          Print the name of the corresponding person, N_m
 *          Set the value of Found to YES
 *      Else if NUMBER < T_m, then set end = m - 1
 *      Else (NUMBER > T_m) set beginning = m + 1
 * if (Found = NO) then print the message 'Sorry, this number is not in our
 * directory' Stop
 *
 *  */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
  uint64_t T[] = {2478346543ULL, 3563278900ULL, 3597211488ULL, 5656170224ULL,
                  6485551285ULL, 7719215281ULL, 8796562127ULL};
  uint8_t N[] = {1U, 2U, 3U, 4U, 5U, 6U, 7U};
  size_t n = sizeof(T) / sizeof(T[0U]);
  size_t beginning = 0U;
  bool Found = false;

  // uint64_t NUMBER = 5656170224U;
  uint64_t NUMBER = 3563278900U;

  /* set the value of end to n */
  size_t end = n - 1;

  while ((Found == false) && (beginning <= end)) {
    /* set the value of m to the middle value between beginning and end */
    size_t m = (beginning + end) / 2U;

    /* if NUMBER == T_m, the number found at the midpoint between beginning and
     * end, then do Steps 7 and 8 */
    if (NUMBER == T[m]) {
      printf("Print the name of the corresponding person: %d\n", N[m]);
      Found = true;
    } else if (NUMBER < T[m]) {
      /* set end = m - 1 */
      end = m - 1;
    } else if (NUMBER > T[m]) {
      /* set beginning = m + 1 */
      beginning = m + 1;
    }
  }

  if (Found == false) {
    printf("Sorry, this number is not in our directory");
  }

  return 0;
}

/**
 * Practice problems pg. 129:
 * 1. Suppose that, using the list of seven numbers from this section, we try
 * binary search to decide whether 6485551285 is in the list. What numbers would
 * be compared with 6485551285?
 *
 * Answer:
 * Correct steps:
Middle index = 4 → value = 5656170224
Since 6485551285 > 5656170224 → go right
New middle = 6 → value = 7719215281
Since 6485551285 < 7719215281 → go left
New middle = 5 → value = 6485551285 ✅ FOUND
 *
 * 2. Suppose that, using the list of seven numbers from this section, we try
 * binary search to decide whether 9342426855 is in the list. What numbers would
 * be compared with 9342426855?
 * Answer:
 * Once again first is compared to 5656170224 → 7719215281 → 8796562127 → NOT
FOUND
 * 8796562127, then, then a few iteration it will say "Sorry, this number is not
 * in our directory"
 *
 * 3.
 *
 *
 * */