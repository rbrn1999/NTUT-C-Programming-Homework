#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 999

typedef struct _job {
    int machine;
    int timeCost;
} job;

typedef struct _work {
    int jobCount;
    job *jobs;
    int progress;
    int time;
} work;

int max(int a, int b) {
    return a>b?a:b;
}


int main() {
    int machineCount, workCount;
    int totalJob = 0;
    scanf("%d%d", &machineCount, &workCount);
    int *machinesTime = (int *) malloc(machineCount * sizeof(int));
    work works[workCount];
    for(int i=0; i<machineCount; i++)
        machinesTime[i] = 0;
        
    for (int i=0; i<workCount; i++) {
        works[i].progress = 0;
        works[i].time = 0;
        works[i].jobs = (job *) malloc(100 * sizeof(job));
        scanf("%d", &works[i].jobCount);
        totalJob += works[i].jobCount;
        for (int j=0; j<works[i].jobCount; j++) {
            scanf("%d%d", &works[i].jobs[j].machine, &works[i].jobs[j].timeCost);
        }
    }
    
    for (int i=0; i<totalJob; i++) {
        int time[workCount];
        int target = 0;
        for (int j=0; j<workCount; j++) {
            if (works[j].progress < works[j].jobCount) {
                time[j] = works[j].jobs[works[j].progress].timeCost + max(works[j].time, machinesTime[works[j].jobs[works[j].progress].machine]);
            } else {
                time[j] = N;
            }
            if (time[j] < time[target]) {
                target = j;
            }
        }
        int cost = works[target].jobs[works[target].progress].timeCost;
        machinesTime[works[target].jobs[works[target].progress].machine] = cost + max(machinesTime[works[target].jobs[works[target].progress].machine], works[target].time);
        works[target].time = machinesTime[works[target].jobs[works[target].progress].machine];
        works[target].progress++;
    }
    int totalTime = 0;
    for (int i=0; i<workCount; i++) {
        totalTime += works[i].time;
    }
    printf("%d\n", totalTime);
    return 0;
}
