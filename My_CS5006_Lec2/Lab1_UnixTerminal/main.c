// CS 5006 - LAB 1
#include <stdio.h>

int power(int base, int n);

int main() {
    int base, n, result;
    
    base = 2;
    n = 1;

    for (n; n < 11; n++) {
        result = power(base,n);
        printf("%d\n", result);
    }

    return 0;
}

int power(int base, int n) {
    if (n != 0) {
        return (base * power(base, n - 1));
    }
    else {
        return 1;
    }
}
