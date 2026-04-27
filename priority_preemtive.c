#include <stdio.h>
struct Process{
    int pid;
    int arrival;
    int burst;
    int priority;
    int remaining;
    int completion;
    int turnaround;
    int waiting;
};

int main(){
    int n;
    printf("enter the number of process:");
    scanf("%d",&n);

    struct Process p[n];
    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("enter arrival time of P%d :",p[i].pid);
        scanf("%d",&p[i].arrival);
        printf("enter burst time of P%d :",p[i].pid);
        scanf("%d",&p[i].burst);
        printf("enter priority of P%d :",p[i].pid);
        scanf("%d",&p[i].priority);
        p[i].remaining=p[i].burst;
    }
    int currentTime=0,completed=0;
    float totalTAT=0,totalWT=0;
    while(completed<n){
        int idx =-1;
        int highestPriority =100000;

        for(int i=0;i<n;i++){
            if(p[i].arrival<currentTime && p[i].remaining>0){
                if(p[i].priority<highestPriority){
                    highestPriority=p[i].priority;
                    idx=i;
                }
            }
        }
        if(idx != -1){
            p[idx].remaining--;
            currentTime++;
            if(p[idx].remaining ==0){
                p[idx].completion=currentTime;
                p[idx].turnaround=p[idx].completion-p[idx].arrival;
                p[idx].waiting=p[idx].turnaround-p[idx].burst;

                completed++;
                totalTAT=p[idx].turnaround;
                totalWT=p[idx].waiting;
            }
        }
        else{
            currentTime++;
        }
    }
       // 🔹 Output
    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].priority,
               p[i].completion,
               p[i].turnaround,
               p[i].waiting);
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;


}