#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int start;        // Start Time
    int end;          // End Time
    int completion;   // Completion Time
    int waiting;      // Waiting Time
    int turnaround;   // Turnaround Time
    int isCompleted;  // 0 = not completed, 1 = completed
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter arrival time of P%d: ", p[i].pid);
        scanf("%d", &p[i].arrival);

        printf("Enter burst time of P%d: ", p[i].pid);
        scanf("%d", &p[i].burst);

        p[i].isCompleted = 0;
    }

    int currentTime = 0, completed = 0;
    float totalWT = 0, totalTAT = 0;

    // SJF Scheduling
    while (completed < n) {
        int idx = -1;
        int minBT = 100000;

        // Find shortest job among arrived processes
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= currentTime && p[i].isCompleted == 0) {
                if (p[i].burst < minBT) {
                    minBT = p[i].burst;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            // Start Time
            p[idx].start = currentTime;

            // End Time
            p[idx].end = p[idx].start + p[idx].burst;

            // Completion Time
            p[idx].completion = p[idx].end;

            // Turnaround Time
            p[idx].turnaround = p[idx].completion - p[idx].arrival;

            // Waiting Time
            p[idx].waiting = p[idx].turnaround - p[idx].burst;

            // Update current time
            currentTime = p[idx].completion;

            // Mark completed
            p[idx].isCompleted = 1;
            completed++;

            // Add totals
            totalWT += p[idx].waiting;
            totalTAT += p[idx].turnaround;
        } 
        else {
            // CPU Idle
            currentTime++;
        }
    }

    // Output
    printf("\nPID\tAT\tBT\tST\tET\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].start,
               p[i].end,
               p[i].completion,
               p[i].turnaround,
               p[i].waiting);
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}
