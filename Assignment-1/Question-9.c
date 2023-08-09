/* Write a program to find frequency of a given number ‘k’. 
 */

#include <stdio.h>

int findFrequency(int num, int k) {
    int frequency = 0;

    while (num != 0) {
        int digit = num % 10;
        if (digit == k) {
            frequency++;
        }
        num /= 10;
    }

    return frequency;
}

int main() {
    int num, k;

    printf("Enter the number: ");
    scanf("%d", &num);

    printf("Enter the number to find its frequency: ");
    scanf("%d", &k);

    int frequency = findFrequency(num, k);

    printf("The frequency of %d in the number %d is: %d\n", k, num, frequency);

    return 0;
}



//pyhon code
def find_frequency(num, k):
    frequency = 0
    while num != 0:
        digit = num % 10
        if digit == k:
            frequency += 1
        num //= 10
    return frequency

def main():
    num = int(input("Enter the number: "))
    k = int(input("Enter the number to find its frequency: "))

    frequency = find_frequency(num, k)

    print(f"The frequency of {k} in the number {num} is: {frequency}")

if __name__ == "__main__":
    main()
