#include <stdio.h>

struct Process {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // 🔹 Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter arrival time of P%d: ", p[i].pid);
        scanf("%d", &p[i].arrival);

        printf("Enter burst time of P%d: ", p[i].pid);
        scanf("%d", &p[i].burst);

        p[i].remaining = p[i].burst; // initially same
    }

    int currentTime = 0, completed = 0;
    float totalWT = 0, totalTAT = 0;

    // 🔹 Main Scheduling Loop
    while (completed < n) {
        int idx = -1;
        int minRT = 100000;

        // Find process with smallest remaining time
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= currentTime && p[i].remaining > 0) {
                if (p[i].remaining < minRT) {
                    minRT = p[i].remaining;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            // Execute for 1 unit
            p[idx].remaining--;
            currentTime++;

            // If process completes
            if (p[idx].remaining == 0) {
                p[idx].completion = currentTime;
                p[idx].turnaround = p[idx].completion - p[idx].arrival;
                p[idx].waiting = p[idx].turnaround - p[idx].burst;

                completed++;

                totalWT += p[idx].waiting;
                totalTAT += p[idx].turnaround;
            }
        } 
        else {
            // CPU idle
            currentTime++;
        }
    }

    // 🔹 Output
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
