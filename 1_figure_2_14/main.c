/**
 * Date     : 23 March 2026
 * Author   : Efraim Manurung
 * email    : efraim.manurung@gmail.com
 *
 * Figure 2.14 from the textbook "Invitation to Computer Science" by G. Michael
 * Schneider and Judith L. Gersting, 7th edition, 2016.
 *
 * Given: A value n >= 1 and a list containing exactly n unique numbers called
 * A_1, A_2, ..., A_n, find and print both the largest value in the list and the
 * position in the list where that largest value occured.
 *
 * For example, if our list contained the five values
 * 19, 41, 12, 63, 22 (n = 5)
 *
 * then our algorithm should locate the largest value, 63, and print that value
 * together with the fact that it occured in the fourth position of the list.
 *
 * Algorithm:
 * - Get a value for n, the size of the list
 * - Get values for A_1, A_2, ..., A_n, the list to be searched
 * - Set the value of largest so far to A_1
 * - Set the value of location to 1
 * - Set the value of i to 2
 * - While (i <= n ) do
 * -    if A_i > largest so far then
 * -            Set largest so far to A_i
 * -            Set location to i
 * -    Add 1 to the value of i
 * - End of the loop
 * - Print out the values of largest so far and location
 * - Stop
 *
 *  */

#include <stdio.h>

int main() {
  int A[5] = {19, 41, 12, 63, 22};
  size_t n = sizeof(A) / sizeof(A[0]);

  int largest_so_far = A[0];
  int location = 0;
  int i = 1;

  while (i < n) {
    if (A[i] > largest_so_far) {
      largest_so_far = A[i];
      location = i;
    }

    i += 1;
  }

  printf("Values: %d, location: %d", largest_so_far, location);

  return 0;
}