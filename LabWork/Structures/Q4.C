#include<stdio.h>
typedef struct time{
    int hr;
    int min;
    int sec;
}Time;

Time start_time,end_time;

int main(){
    int startTime,endTime;
    printf("Enter start time");
    scanf("%d %d %d",&start_time.hr,&start_time.min,&start_time.sec);
    printf("Enter end time");
    scanf("%d %d %d",&end_time.hr,&end_time.min,&end_time.sec);
    startTime=start_time.hr*3600+start_time.min*60+start_time.sec;
    endTime=end_time.hr*3600+end_time.min*60+end_time.sec;

    while(startTime!=endTime){
        printf("GOOD DAY\n");
        startTime++;
    }
    return 0;
}