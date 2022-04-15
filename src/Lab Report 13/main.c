#include<stdio.h>
#include<stdlib.h>
int main(){
    int RQ[100],i,n,TotalHeadMoment=0,initial;
    
    printf("Enter the number of Requests: ");
    scanf("%d",&n);
    
    printf("Enter the Requests sequence\n");
    for(i=0;i<n;i++) scanf("%d",&RQ[i]);
    
    printf("Enter initial head position\n");
    scanf("%d",&initial);

    for(i=0;i<n;i++){
        TotalHeadMoment=TotalHeadMoment+abs(RQ[i]-initial);
        initial=RQ[i];
    }
    
    printf("Total head moment is %d\n",TotalHeadMoment);
    return 0;   
}