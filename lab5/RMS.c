#include <stdio.h>
int main() {
    int C[3]={3,2,2};
    int T[3]={20,5,10};
    float U;
    printf("Rate Monotonic Scheduling\nTasks:\n");
    printf("T1-> C=3  T=20\n");
    printf("T2-> C=2  T=5\n");
    printf("T3-> C=2  T=10\n");
    U=(float)3/20+(float)2/5+(float)2/10;
    printf("CPU Utilization U=%.2f\n",U);
    printf("RMS Bound for 3 tasks=0.78\n");
    if(U<=0.78)
        printf("Taks are schedulable\n");
    else{
        printf("Tasks are not schedulable\n");return 0;
    }
    printf("\nPriority(Smaller period-> Higher priority)\n");
    printf("T2>T3>T1\nExecution Timeline(0-20)\n");
    printf("0-2:T2\n2-4:T3\n4-5:T1\n5-7:T2\n7-9:T1\n9-10:Idle\n10-12:T2\n12-14:T3\n14-15:Idle\n15-17:T2\n17-20:Idle\n");
    return 0;
}
