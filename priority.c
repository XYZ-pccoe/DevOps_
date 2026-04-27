#include <stdio.h>

struct Process{
    int pid;
    int arrival;
    int burst;
    int priority; 
    int start;
    int completion;
    int turnaround;
    int waiting;
    int iscompleted;

};
 int main(){
    int n;
    printf("enter the number od process :");
    scanf("%d",&n);
    struct Process p[n];

    for(int i=0;i<n;i++){
        p[i].pid=i+1;
        printf("Arrival time of Process P%d",p[i].pid);
        scanf("%d",&p[i].arrival);
        printf("Burst Time of Process P%d",p[i].pid);
        scanf("%d",&p[i].burst);
        printf("Priority of Process P%d",p[i].pid);
        scanf("%d",&p[i].priority);
        p[i].iscompleted=0;
    }
    int currentTime=0,completed=0;
    float totalTAt=0,totalWT=0;

    while(completed<n){
        int idx =-1;
        int highpriority=100000;
        for(int i=0;i<n;i++){
            if(p[i].arrival<=currentTime && p[i].iscompleted==0){
                if(p[i].priority<highpriority){
                    highpriority=p[i].priority;
                    idx=i;
                }
            }
        }
        if(idx != -1){
            p[idx].start=currentTime;
            p[idx].completion=p[idx].start+p[idx].burst;
            p[idx].turnaround=p[idx].completion-p[idx].arrival;
            p[idx].waiting=p[idx].turnaround-p[idx].burst;

            currentTime=p[idx].completion;

            p[idx].iscompleted=1;
            completed++;

            totalTAt += p[idx].turnaround;
            totalWT += p[idx].waiting;
        }
        else{
            currentTime++;
        }
    }
    printf("\nPID\tAT\tBT\tP\tST\tCT\tTAT\tWT\n ");
    for(int i=0;i<n;i++){
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid,
            p[i].arrival,
            p[i].burst,
            p[i].priority,
            p[i].start,
            p[i].completion,
            p[i].turnaround,
            p[i].waiting);
    }
    printf("avg wt =%.2f",totalWT);
    printf("avg TAt =%.2f",totalTAt);
    return 0;
 }