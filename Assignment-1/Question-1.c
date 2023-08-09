/* 
    *
   # *
  # * #
 * # * #
* # * # * 
 */


#include <stdio.h>

int main() {
    int n = 5;

    int c=0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            c++;
            if(c%2==0){
                printf("#");
            }else{
                printf("*");
            }
        }
        printf("\n");
    }

    return 0;
}


//Python code
def main():
    n = 5
    c = 0

    for i in range(1, n + 1):
        for j in range(1, i):
            c += 1
            if c % 2 == 0:
                print("#", end="")
            else:
                print("*", end="")
        print()

if __name__ == "__main__":
    main()
