#include <stdio.h>

struct  Process{
    int pid;
    int arrival;
    int burst;
    int remaining;
    int completion;
    int waiting;
    int turnaround;
};

int main(){
    int n,tq;
    printf("enterthe no of process :");
    scanf("%d",&n);
    struct Process p[n];

    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("arrival time P%d:",p[i].pid);
        scanf("%d",&p[i].arrival);
        printf("burst time P%d:",p[i].pid);
        scanf("%d",&p[i].burst);
        p[i].remaining=p[i].burst;
    }
    printf("enter time Qunatum:");
    scanf("%d",&tq);

    int currentTime=0,completed=0;

    while(completed<n){
        int done = 1;
        for(int i=0;i< n;i++){
            if(p[i].arrival<currentTime && p[i].remaining>0){
                done=0;
                if(p[i].remaining > tq){
                    currentTime +=tq;
                    p[i].remaining -=tq;
                }
                else{
                    currentTime += p[i].remaining;
                    p[i].remaining =0;
                    p[i].completion=currentTime;
                    completed++;

                }
            }

        }
        if(done){
            currentTime++;
        }
    }
    float totalWT =0,totalTAT=0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        p[i].turnaround=p[i].completion-p[i].arrival;
        p[i].waiting =p[i].turnaround-p[i].burst;
        totalWT += p[i].waiting;
        totalTAT += p[i].turnaround;

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
