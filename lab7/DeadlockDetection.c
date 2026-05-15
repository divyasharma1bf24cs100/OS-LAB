#include <stdio.h>
int main(){
    int n,m,i,j,k;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter number of resource types: ");
    scanf("%d",&m);
    int alloc[n][m],request[n][m];
    int avail[m];
    printf("\nEnter Allocation Matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("\nEnter Request Matrix:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&request[i][j]);
        }
    }
    printf("\nEnter Available Resources:\n");
    for(i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }
    int finish[n];
    for(i=0;i<n;i++){
        int zeroAlloc=1;
        for(j=0;j<m;j++){
            if(alloc[i][j]!= 0){
                zeroAlloc=0;
                break;
            }
        }
        if(zeroAlloc)
            finish[i]=1;
        else
            finish[i]=0;
    }
    int found;
    do{
        found=0;
        for(i=0;i<n;i++){
            if(finish[i]==0){
                int possible=1;
                for(j=0;j<m;j++){
                    if(request[i][j]>avail[j]){
                        possible=0;
                        break;
                    }
                }
                if(possible){
                    for(k=0;k<m;k++){
                        avail[k]+=alloc[i][k];
                    }
                    finish[i]=1;
                    found=1;
                }
            }
        }

    }while(found);
    int deadlock=0;
    printf("\nDeadlocked Processes: ");
    for(i=0;i<n;i++){
        if(finish[i]==0){
            printf("P%d ",i);
            deadlock=1;
        }
    }
    if(deadlock==0){
        printf("None");
    }
    printf("\n");
    return 0;
}
