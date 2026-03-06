#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,j,n,time=0,completed=0,min;
    float tatsum=0,wtsum=0,rtsum=0;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int at[n],bt[n],ct[n],tat[n],wt[n],rt[n],rem[n],start[n];
    for(i=0;i<n;i++){
        printf("Enter AT and BT for P%d:",(i+1));
        scanf("%d%d",&at[i],&bt[i]);
        rem[i]=bt[i]; 
        start[i]=-1;
    }
    while(completed<n)
    {
        min=-1;
        for(i=0;i<n;i++){
            if(at[i]<=time && rem[i]>0){
                if(min==-1 || rem[i]<rem[min]){
                    min=i;
                }
            }
        }
        if(min==-1){
            time++;
            continue;
        }
        if(start[min]==-1){
            start[min]=time;
        }
        rem[min]--;
        time++;
        if(rem[min]==0){
            completed++;
            ct[min]=time;
            tat[min]=ct[min]-at[min];
            wt[min]=tat[min]-bt[min];
            rt[min]=start[min]-at[min];
            tatsum+=tat[min];
            wtsum+=wt[min];
            rtsum+=rt[min];
        }
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        (i+1),at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }
    printf("Avg TAT=%.2f\nAvg WT=%.2f\nAvg RT=%.2f\n",(tatsum/n),(wtsum/n),(rtsum/n));
    return 0;
}
