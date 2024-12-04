#include <stdio.h>
#include <stdlib.h>

unsigned long long int fibonacci_recursive(unsigned long long int number);
unsigned long long int fibonacci_iterative(unsigned long long int number);

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: %s <integer> <r/i>\n", argv[0]);
        return 1;
    }

    unsigned long long int input_num = atoll(argv[1]);
    char method = argv[2][0];

    unsigned long long int fibonacci_input
        = input_num - 1; // sequence starts from fib(1) = 1

    unsigned long long int result;
    if (method == 'r') {
        result = fibonacci_recursive(fibonacci_input);
    } else if (method == 'i') {
        result = fibonacci_iterative(fibonacci_input);
    } else {
        printf("Invalid method! Use 'r' for recursive or 'i' for iterative.\n");
        return 1;
    }

    printf("%llu\n", result); // outputs results as an unsigned long long int
    return 0;
}

unsigned long long int fibonacci_recursive(unsigned long long int number)
{
    if (number == 0)
        return 0;
    if (number == 1)
        return 1;
    return fibonacci_recursive(number - 1) + fibonacci_recursive(number - 2);
}

unsigned long long int fibonacci_iterative(unsigned long long int number)
{
    if (number <= 1)
        return number;

    unsigned long long int previous = 0, current = 1, next_term;

    for (unsigned long long int i = 2; i <= number; i++) {
        next_term = previous + current;
        previous = current;
        current = next_term;
    }
    return current;
}
