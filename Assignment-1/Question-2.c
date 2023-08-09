/*    A
     B B
    C C C
   D D D D 
*/

#include <stdio.h>

int main() {
    int i, j;
    char str[] = "ABCD";

    for (i = 1; i <= 4; i++) {
        for (int k = 1; k <= 4 - i; k++) {
            printf(" ");
        }
        for (j = 1; j <= i; j++) {
            printf("%c", str[i - 1]);
            if (j < i) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}


//Python code
def main():
    str = "ABCD"

    for i in range(1, 5):
        print(" " * (4 - i), end="")
        print(str[i - 1] * i, end="")
        if i < 4:
            print("")

if __name__ == "__main__":
    main()
