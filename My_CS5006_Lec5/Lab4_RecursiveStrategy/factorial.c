/** Factorial - Recursive function to compute 
 * factorial numbers
 * */

#include <stdio.h>

/** PART I - Compute factorial number with 
 * iteration. Each time we iterate, we substract
 * 1 from the original input and multiply by the 
 * current number.
 * 
 * Input(s):
 *          (1) an integer
 * Returns that factorial of the given integer.
 * */
int factorial(int n) {
    int i, result, limit;
    // set upper bound limit of for loop
    // set at n-1 so result does not multiply by 0
    limit = n-1;
    result = n;

    // start at 0 and stop at limit
    for (i=0; i<limit; i++) {
        
        result = result * (n-1);
        
        // substract 1 from current number and go
        // back to top of the loop
        n = n-1;
    }
    return result;
};

/** PART II - Compute factorial number with 
 * recursion. Base case is n = 1, at which point return
 * the result. Each time call function, substract 1 from
 * input integer.
 *
 * Input(s):
 *          (1) an integer
 * Returns that factorial of the given integer.
 * */
unsigned long long int factorial_rec(long int n) {

    // base case: n is equal to 0, return 1
    if (n==0) {
        return 1;
    }
    else {
        return n*factorial_rec(n-1);
    }
}

int main(){

    printf("factorial(10) = %d\n",factorial(10));
    printf("factorial(4) = %d\n",factorial(4));
    printf("factorial(3) = %d\n",factorial(3));
    printf("factorial(4) = %d\n",factorial_rec(4));
    printf("factorial_rec(10) = %d\n",factorial_rec(10));
    printf("factorial_rec(3) = %d\n",factorial_rec(3));


    return 0;
}
