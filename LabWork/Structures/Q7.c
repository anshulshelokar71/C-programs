#include <stdio.h>
typedef struct time{
    int hr;
    int min;
    int sec;
}Time;

Time t1,t2;

int main(){
    int tm1,tm2,add_t,sub_t;
    t1.hr=10;
    t1.min=20;
    t1.sec=50;
    tm1=t1.hr*3600+t1.min*60+t1.sec;
    t2.hr=5;
    t2.min=30;
    t2.sec=40;
    tm2=t2.hr*3600+t2.min*60+t2.sec;
    add_t=tm1+tm2;
    sub_t=tm1-tm2;
    printf("%dhrs%dmin%dsec\n",add_t/3600,(add_t/60)%60,add_t%60);
    printf("%dhrs%dmin%dsec",sub_t/3600,(sub_t/60)%60,sub_t%60);
    return 0;
}