#include<stdio.h>
#include<string.h>

int main() {
    char p[10][5];
    int at[10], bt[10], ct[10], tat[10], wt[10], rt[10], i, j, temp = 0, n;
    float awt = 0, atat = 0;

    printf("Enter The Number of Processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Times and Burst Times for Each Process:\n");
    for(i = 0; i < n; i++) {
        at[i] = bt[i] = ct[i] = tat[i] = wt[i] = rt[i] = 0;
        printf("AT & BT for P%d: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        snprintf(p[i], sizeof(p[i]), "P%d", i + 1);
    }

    // Sorting processes according to AT
    for(i = 0; i < n; i++) {
        for(j = 0; j < (n - i - 1); j++) {
            if(at[j] > at[j+1]) {
                temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;

                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;

                char tempID[5];
                strcpy(tempID, p[j]);
                strcpy(p[j], p[j+1]);
                strcpy(p[j+1], tempID);
            }
        }
    }

    // Calculating CT
    ct[0] = at[0] + bt[0];
    for(i = 1; i < n; i++) {
        temp = 0;
        if(ct[i-1] < at[i]) {
            temp = at[i] - ct[i-1];
        }
        ct[i] = ct[i-1] + bt[i] + temp;
    }

    // Sorting results based on process IDs
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(p[j], p[j + 1]) > 0) {
                char tempID[5];
                strcpy(tempID, p[j]);
                strcpy(p[j], p[j + 1]);
                strcpy(p[j + 1], tempID);

                temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = ct[j];
                ct[j] = ct[j + 1];
                ct[j + 1] = temp;

                temp = tat[j];
                tat[j] = tat[j + 1];
                tat[j + 1] = temp;

                temp = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = temp;

                temp = rt[j];
                rt[j] = rt[j + 1];
                rt[j + 1] = temp;
            }
        }
    }

    // Calculating TAT, WT, and RT
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\tRT\n");
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = wt[i]; // RT is same as WT
        printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
        atat += tat[i];
        awt += wt[i];
    }

    // Calculating average TAT and average AT
    atat /= n;
    awt /= n;
    printf("\nAverage Turnaround Time: %.2f", atat);
    printf("\nAverage Waiting Time: %.2f\n", awt);

    return 0;
}

