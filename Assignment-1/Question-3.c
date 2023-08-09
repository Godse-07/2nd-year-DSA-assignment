/* 
      1
     2 3
    4 5 6
   7 8 9 10 
 */

#include <stdio.h>

int main() {
    int n = 4;
    int count = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= i; k++) {
            printf("%d ", count);
            count++;
        }
        printf("\n");
    }

    return 0;
}



//Python code
def main():
    n = 4
    count = 1

    for i in range(1, n + 1):
        print(" " * (n - i), end="")
        for k in range(1, i + 1):
            print(count, end=" ")
            count += 1
        print()

if __name__ == "__main__":
    main()
