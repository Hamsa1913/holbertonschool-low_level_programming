#include <stdio.h>

int main(void) {
    int n;
    
    // Assume n is assigned somewhere here by existing code, for example:
    // n = rand();

    int last_digit = n % 10;

    printf("Last digit of %d is ", n);
    if (last_digit > 5) {
        printf("and is greater than 5\n");
    } else if (last_digit == 0) {
        printf("and is 0\n");
    } else {
        printf("and is less than 6 and not 0\n");
    }

    return 0;
}


