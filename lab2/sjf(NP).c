#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,temp1,temp2,time=0;
    float tatsum=0,wtsum=0,rtsum=0;
    printf("Enter number of processes:");
    scanf("%d",&n);
    int at[n],bt[n],ct[n],tat[n],wt[n],rt[n];
    for(i=0;i<n;i++){
        printf("Ënter AT and BT for P%d:",(i+1));
        scanf("%d%d",&at[i],&bt[i]);
    }
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(at[i]>at[j]){
                temp1=at[i];
                at[i]=at[j];
                at[j]=temp1;
                temp2=bt[i];
                bt[i]=bt[j];
                bt[j]=bt[i];
                bt[j]=temp2;
            }
        }
    }
    for(i=0;i<n;i++){
        int min=i;
        for(j=i+1;j<n;j++){
            if(at[j]<=time && bt[j]<bt[min]){
                min=j;
            }
        }
        if(min!=i){
            temp1=at[i];
            at[i]=at[min];
            at[min]=temp1;
            temp2=bt[i];
            bt[i]=bt[min];
            bt[min]=temp2;
        }
        if(time<at[i]){time=at[i];}
        if(i==0){
            ct[i]=time+bt[i];
            rt[i]=time-at[i];
        }
        else{
            ct[i]=bt[i]+ct[i-1];
            rt[i]=time-at[i];
        }
        time+=bt[i];
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        tatsum+=tat[i];
        wtsum+=wt[i];
        rtsum+=rt[i];
    }
    printf("Process\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",(i+1),at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }
    printf("Avg TAT=%.2f\nAvg WT=%.2f\nAvg RT=%.2f\n",(tatsum/n),(wtsum/n),(rtsum/n));
    return 0;
}
