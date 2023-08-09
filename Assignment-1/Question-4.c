/* . Consider the given series and calculate the summation up-to ‘N’ number.
1+1+4+9+25+64+ .......... +N */

#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

long long calculateSum(int N) {
    long long sum = 0;

    for (int i = 0; i < N; i++) {
        int fib = fibonacci(i);
        sum += (long long)(fib * fib);
    }

    return sum;
}

int main() {
    int N;

    printf("Enter the number of terms: ");
    scanf("%d", &N);

    long long sum = calculateSum(N);

    printf("Summation of squared Fibonacci numbers up to %d terms is: %lld\n", N, sum);

    return 0;
}


//Python code

def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n - 1) + fibonacci(n - 2)

def calculate_sum(N):
    summation = 0

    for i in range(N):
        fib = fibonacci(i)
        summation += fib * fib

    return summation

def main():
    N = int(input("Enter the number of terms: "))

    summation = calculate_sum(N)

    print(f"Summation of squared Fibonacci numbers up to {N} terms is: {summation}")

if __name__ == "__main__":
    main()
