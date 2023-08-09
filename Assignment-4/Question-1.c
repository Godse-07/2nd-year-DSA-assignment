/* Write a program to calculate difference between Start time & End time of an event. Time is
expressed as hr-min-sec. Final result to be produced in seconds. 
 */



#include <stdio.h>

typedef struct {
    int hours;
    int minutes;
    int seconds;
} Time;

int timeInSeconds(Time t) {
    return t.hours * 3600 + t.minutes * 60 + t.seconds;
}

int main() {
    Time startTime, endTime;
    int diffInSeconds;

    printf("Enter start time (hh:mm:ss): ");
    scanf("%d:%d:%d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    printf("Enter end time (hh:mm:ss): ");
    scanf("%d:%d:%d", &endTime.hours, &endTime.minutes, &endTime.seconds);

    diffInSeconds = timeInSeconds(endTime) - timeInSeconds(startTime);

    printf("Time difference: %d seconds\n", diffInSeconds);

    return 0;
}


/* Enter start time (hh:mm:ss): 10:30:45
Enter end time (hh:mm:ss): 12:15:30
Time difference: 6265 seconds */


def time_in_seconds(time):
    return time[0] * 3600 + time[1] * 60 + time[2]

def main():
    start_time = list(map(int, input("Enter start time (hh:mm:ss): ").split(":")))
    end_time = list(map(int, input("Enter end time (hh:mm:ss): ").split(":")))

    diff_in_seconds = time_in_seconds(end_time) - time_in_seconds(start_time)

    print("Time difference:", diff_in_seconds, "seconds")

if __name__ == "__main__":
    main()
