#include<stdio.h>
#include<string.h>

int main() {
    char p[10][5];
    int bt[10], ct[10], tat[10], wt[10], rt[10], i, j, temp = 0, n;
    float awt = 0, atat = 0;

    printf("Enter The Number of Processes: ");
    scanf("%d", &n);

    printf("Enter Burst Times for Each Process:\n");
    for(i = 0; i < n; i++) {
        printf("BT for P%d: ", i + 1);
        scanf("%d", &bt[i]);
        snprintf(p[i], sizeof(p[i]), "P%d", i + 1);
    }

    // Calculating CT
    ct[0] = bt[0];
    for(i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];
    }

    // Calculating TAT, WT, and RT
    printf("\nP\tBT\tCT\tTAT\tWT\tRT\n");
    for(i = 0; i < n; i++) {
        tat[i] = ct[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = wt[i]; // Response time is same as waiting time
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", p[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
        atat += tat[i];
        awt += wt[i];
    }

    // Calculating average TAT and average WT
    atat /= n;
    awt /= n;
    printf("\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);

    return 0;
}

