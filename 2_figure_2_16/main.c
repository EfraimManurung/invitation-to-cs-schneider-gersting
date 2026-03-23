/**
 * Date     : 23 March 2026
 * Author   : Efraim Manurung
 * email    : efraim.manurung@gmail.com
 *
 * Figure 2.16 from the textbook "Invitation to Computer Science" by G. Michael
 * Schneider and Judith L. Gersting, 7th edition, 2016.
 *
 * Example: Meeting your match
 *
 * Given: Consider the following text.
 *      Text: A man and a woman
 * Trace the pattern-matching algorithm of Figure 2.16 using the two-character
 * pattern "an" and show the output produced
 *
 * Algorithm:
 * Get values for n and m, the size of the text and the pattern, respectively
 * Get values for both the text T_1 T_2...T_n and the pattern P_1 P_2...P_m
 * Set k, the starting location for the attempted match, to 1
 * While (k <= (n - m + 1)) do
 *      Set the value of i to 1
 *      Set the value of Mismatch to NO
 *      While both (i <= m) and (Mismatch = NO) do
 *          if P != T_k+(i-1) then
 *              Set Mismatch to YES
 *          Else
 *              Increment i by 1 (to move to the next character)
 *      End of the loop
 *      If Mismatch = NO then
 *          Print the message 'There is a match at position'
 *          Print the value of k
 *      Increment k by 1
 * End of the loop
 * Stop
 *
 * */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main() {
  printf("Meeting your match program has started!\n");

  /* size of the text */
  char T[] = "A man and a woman";

  /* size of the pattern */
  char P[] = "an";

  /* get the values both for text and the pattern */
  //   size_t n = sizeof(T) / sizeof(T[0]);
  //   size_t m = sizeof(P) / sizeof(P[0]);

  /* get the actual length (excluding null terminator) */
  int n = strlen(T); // or: sizeof(T) - 1
  int m = strlen(P); // or: sizeof(P) - 1

  /* set k, the starting location for the attempted match to 1 */
  int k = 0;

  while (k <= (n - m)) { // Note: simplified condition
    /* set values of i to 0 */
    int i = 0;

    /* set the values of mismatch to NO */
    bool mismatch = false;

    while ((i < m) && (mismatch == false)) {
      printf("P[%d]: %c\n", i, P[i]);
      printf("T[%d]: %c\n", (k + (i - 1)), T[k + (i - 1)]);

      if (P[i] != T[k + i]) { /* changed to k+i */
        /* set mismatch to YES */
        mismatch = true;
      } else {
        /* increment i by 1 (to move the next character) */
        i += 1;
      }
      /* end of the loop */
    }

    if (mismatch == false) {
      /* print the message */
      printf("There is a match at position: %d\n", k);
    } else {
      printf("There is no match position!\n");
    }

    /* increment k by 1 */
    k += 1;
  }
  /* end of the loop */

  return 0;
}