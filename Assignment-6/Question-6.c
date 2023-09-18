/* Write a program to implement recursive & tail recursive version a) to find factorial of a number
b) to find Fibonacci series.  */



(a)
#include <stdio.h>


unsigned long long recursive_factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * recursive_factorial(n - 1);
    }
}


unsigned long long tail_recursive_factorial_helper(int n, unsigned long long result) {
    if (n == 0 || n == 1) {
        return result;
    } else {
        return tail_recursive_factorial_helper(n - 1, n * result);
    }
}

unsigned long long tail_recursive_factorial(int n) {
    return tail_recursive_factorial_helper(n, 1);
}

int main() {
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Recursive Factorial: %llu\n", recursive_factorial(n));
        printf("Tail Recursive Factorial: %llu\n", tail_recursive_factorial(n));
    }

    return 0;
}





/* Enter a number: 5
Recursive Factorial: 120
Tail Recursive Factorial: 120 */


(b)

#include <stdio.h>


unsigned long long recursive_fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
    }
}

// Tail recursive version to generate Fibonacci series
unsigned long long tail_recursive_fibonacci_helper(int n, unsigned long long a, unsigned long long b) {
    if (n == 0) {
        return a;
    } else {
        return tail_recursive_fibonacci_helper(n - 1, b, a + b);
    }
}

unsigned long long tail_recursive_fibonacci(int n) {
    return tail_recursive_fibonacci_helper(n, 0, 1);
}

int main() {
    int n;
    
    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Number of terms should be at least 1.\n");
    } else {
        printf("Recursive Fibonacci Series: ");
        for (int i = 0; i < n; i++) {
            printf("%llu ", recursive_fibonacci(i));
        }
        printf("\n");

        printf("Tail Recursive Fibonacci Series: ");
        for (int i = 0; i < n; i++) {
            printf("%llu ", tail_recursive_fibonacci(i));
        }
        printf("\n");
    }

    return 0;
}




/* Enter the number of terms in the Fibonacci series: 7
Recursive Fibonacci Series: 0 1 1 2 3 5 8
Tail Recursive Fibonacci Series: 0 1 1 2 3 5 8
 */





(a)


# Recursive version to find factorial
def recursive_factorial(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * recursive_factorial(n - 1)


def tail_recursive_factorial(n, result=1):
    if n == 0 or n == 1:
        return result
    else:
        return tail_recursive_factorial(n - 1, n * result)

n = int(input("Enter a number: "))

if n < 0:
    print("Factorial is not defined for negative numbers.")
else:
    print("Recursive Factorial:", recursive_factorial(n))
    print("Tail Recursive Factorial:", tail_recursive_factorial(n))




/* Enter a number: 5
Recursive Factorial: 120
Tail Recursive Factorial: 120 */




(b)



# Recursive version to generate Fibonacci series
def recursive_fibonacci(n):
    if n <= 1:
        return n
    else:
        return recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2)


def tail_recursive_fibonacci_helper(n, a=0, b=1):
    if n == 0:
        return a
    else:
        return tail_recursive_fibonacci_helper(n - 1, b, a + b)

def tail_recursive_fibonacci(n):
    return tail_recursive_fibonacci_helper(n, 0, 1)

n = int(input("Enter the number of terms in the Fibonacci series: "))

if n < 1:
    print("Number of terms should be at least 1.")
else:
    print("Recursive Fibonacci Series:", [recursive_fibonacci(i) for i in range(n)])
    print("Tail Recursive Fibonacci Series:", [tail_recursive_fibonacci(i) for i in range(n)])




/* Enter the number of terms in the Fibonacci series: 7
Recursive Fibonacci Series: [0, 1, 1, 2, 3, 5, 8]
Tail Recursive Fibonacci Series: [0, 1, 1, 2, 3, 5, 8] */
