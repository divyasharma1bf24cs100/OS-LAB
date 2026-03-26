#include <stdio.h>
int main(){
    int n,i,time=0,completed=0,min_pr,highest;
    int bt[20],at[20],pr[20],rt[20],wt[20],tat[20],ct[20];
    printf("Enter number of processes:");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter AT,BT and PR for P%d:",i+1);
        scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
        rt[i]=bt[i]; 
    }
    int done[20]={0};
    while(completed<n){
        highest=-1;
        min_pr=9999;
        for(i=0;i<n;i++){
            if(at[i]<=time && done[i]==0){
                if(pr[i]<min_pr && rt[i]>0){
                    min_pr=pr[i];
                    highest=i;
                }
            }
        }
        if(highest==-1){
            time++;
            continue;
        }
        rt[highest]--;
        time++;
        if(rt[highest]==0){
            completed++;
            done[highest]=1;
            ct[highest]=time;
            tat[highest]=ct[highest]-at[highest];
            wt[highest]=tat[highest]-bt[highest];
        }
    }
    double avg_wt=0,avg_tat=0;
    printf("P\tAT\tBT\tPR\tWT\tTAT\n");
    for(i=0;i<n;i++){
        avg_wt+=wt[i];
        avg_tat+=tat[i];
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],pr[i],wt[i],tat[i]);
    }
    printf("Average WT=%.2f",avg_wt/n);
    printf("\nAverage TAT=%.2f\n",avg_tat/n);
    return 0;
}
