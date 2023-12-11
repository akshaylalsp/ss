#include <stdio.h>

struct process
{
    int pid,at,bt,wt,ta;
}processes[10],temp;

void sort(int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(processes[j].at > processes[j+1].at ){
                temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1]=temp;
            }
        }
    }
}

void display(int n){
    int total_wt = 0;
    int total_ta = 0;
    printf("\npid\tat\tbt\twt\ttat");
    for(int i=0;i<n;i++){
        total_ta += processes[i].ta;
        total_wt += processes[i].wt;
        printf("\n%d\t%d\t%d\t%d\t%d",processes[i].pid,processes[i].at,processes[i].bt,processes[i].wt,processes[i].ta);
    }
    printf("\naverage waiting time : %f",(float)total_wt/n);
    printf("\naverage turnaround time : %f",(float)total_ta/n);
}

void read(int n){
    printf("\nenter arrival and burst time :");
    for(int i=0;i<n;i++){
        scanf("%d%d",&processes[i].at,&processes[i].bt);
        processes[i].pid = i;
    }
    sort(n);
}

void fcfs(int n){
    int i = 0;
    processes[i].wt =0;
    for(i=1;i<n;i++){
        processes[i].wt = processes[i-1].bt+processes[i-1].wt;
    }
    for(i=0;i<n;i++){
        processes[i].ta = processes[i].bt + processes[i].wt;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    int n;
    printf("enter no of processes : ");
    scanf("%d",&n);
    read(n);
    fcfs(n);
    display(n);
    return 0;
}
