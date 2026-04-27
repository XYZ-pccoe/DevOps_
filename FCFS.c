#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int completion;
    int waiting;
    int turnaround;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time of P%d: ", p[i].pid);
        scanf("%d", &p[i].arrival);
        printf("Enter burst time of P%d: ", p[i].pid);
        scanf("%d", &p[i].burst);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival > p[j].arrival) {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int currentTime = 0;
    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].arrival)
            currentTime = p[i].arrival; 

        p[i].completion = currentTime + p[i].burst;
        p[i].turnaround = p[i].completion - p[i].arrival;
        p[i].waiting = p[i].turnaround - p[i].burst;

        currentTime = p[i].completion;

        totalWT += p[i].waiting;
        totalTAT += p[i].turnaround;
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].completion,
               p[i].turnaround,
               p[i].waiting);
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}
