#include <cstdio>

using namespace std;

int d,year,month,day,month_day[]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    while(scanf("%d",&d)!=EOF){
        year=2007,month=10,day=10+d;
        while(day>month_day[month-1]){
            day-=month_day[month-1],month++;
            if(month>12){
                year++,month=1;
                if(year%4==0) month_day[1]=29; else month_day[1]=28;
            }
        }
        printf("%04d-%02d-%02d\n",year,month,day);
    }
}