// C program for implementation of FCFS scheduling
#include <stdio.h>

int main(){
    int n, i, j, burst_time[10], waiting_time[10], turn_around_time[10], total_waiting_time = 0, total_turn_around_time = 0, avg_waiting_time = 0, avg_turn_around_time = 0;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("\nEnter Burst time of processes\n");
    for(i = 0; i < n; i++){
        printf("P[%d]: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    waiting_time[0] = 0;
    for(i = 1; i < n; i++){
        waiting_time[i] = 0;
        for(j = 0; j < i; j++){
            waiting_time[i] = waiting_time[i] + burst_time[j];
        }
    }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for(i = 0; i < n; i++){
        turn_around_time[i] = burst_time[i] + waiting_time[i];
        total_waiting_time += waiting_time[i];
        total_turn_around_time += turn_around_time[i];
        printf("P[%d]\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turn_around_time[i]);
    }

    avg_waiting_time = total_waiting_time / n;
    avg_turn_around_time = total_turn_around_time / n;
    printf("\nTotal waiting time = %d ms\n", total_waiting_time);
    printf("\nAverage Waiting Time = %d ms\n", avg_waiting_time);
    printf("\nTotal turn around time = %d ms\n", total_turn_around_time);
    printf("\nAverage Turn Around Time = %d ms\n", avg_turn_around_time);
    return 0;
}