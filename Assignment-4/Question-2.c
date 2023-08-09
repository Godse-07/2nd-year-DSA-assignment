/* Write a program to collect height & weight of ‘N’ students. Find the highest weight/ height
ratio.  */


#include <stdio.h>

typedef struct {
    float height;
    float weight;
} Student;

float calculateRatio(float weight, float height) {
    return weight / height;
}

int main() {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];
    float maxRatio = 0.0;
    int maxIndex = -1;

    for (int i = 0; i < n; i++) {
        printf("Enter height and weight for student %d: ", i + 1);
        scanf("%f %f", &students[i].height, &students[i].weight);

        float ratio = calculateRatio(students[i].weight, students[i].height);
        if (ratio > maxRatio) {
            maxRatio = ratio;
            maxIndex = i;
        }
    }

    if (maxIndex != -1) {
        printf("Student with highest weight/height ratio:\n");
        printf("Height: %.2f\nWeight: %.2f\nRatio: %.2f\n", students[maxIndex].height, students[maxIndex].weight, maxRatio);
    } else {
        printf("No data entered.\n");
    }

    return 0;
}


/* Enter the number of students: 3
Enter height and weight for student 1: 165.5 60.5
Enter height and weight for student 2: 175.0 70.2
Enter height and weight for student 3: 160.0 55.0
Student with highest weight/height ratio:
Height: 175.00
Weight: 70.20
Ratio: 0.40 */



def calculate_ratio(weight, height):
    return weight / height

def main():
    n = int(input("Enter the number of students: "))

    students = []
    max_ratio = 0.0
    max_index = -1

    for i in range(n):
        height, weight = map(float, input(f"Enter height and weight for student {i+1}: ").split())
        ratio = calculate_ratio(weight, height)

        if ratio > max_ratio:
            max_ratio = ratio
            max_index = i

    if max_index != -1:
        print("Student with highest weight/height ratio:")
        print(f"Height: {students[max_index][0]:.2f}")
        print(f"Weight: {students[max_index][1]:.2f}")
        print(f"Ratio: {max_ratio:.2f}")
    else:
        print("No data entered.")

if __name__ == "__main__":
    main()

