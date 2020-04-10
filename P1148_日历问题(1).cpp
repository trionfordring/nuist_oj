#include <string>
#include <cstdio>
using namespace std;

int a,year,month,day,mo[]={31,29,31,30,31,30,31,31,30,31,30,31};
string weekend[]={"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
void nextMoth(){
    month++;
    if(month>12){
        year++;
        month-=12;
        if(year%4==0&&(year%400==0||year%100!=0))mo[1]=29;
        else mo[1]=28;
    }
}
void nextDay(){
    day++;
    if(day>mo[month-1]){
        day-=mo[month-1];
        nextMoth();
    }
}
int main(){
    while(scanf("%d",&a),a!=-1){
        year=2000,month=1,day=1,mo[1]=29;
        for(int i=0;i<a;i++){
            nextDay();
        }
        printf("%4d-%02d-%02d %s\n",year,month,day,weekend[a%7].c_str());
    }
    return 0;
}