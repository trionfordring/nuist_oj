#include <iostream>
#include <string>
using namespace std;
/*
UTC (Coordinated Universal Time), 定义为 UTC
GMT(Greenwich Mean Time), 定义为 UTC
BST (British Summer Time), 定义为 UTC+1 hour
IST (Irish Summer Time), 定义为 UTC+1 hour
WET (Western Europe Time), 定义为 UTC
WEST (Western Europe Summer Time), 定义为 UTC+1 hour
CET (Central Europe Time), 定义为 UTC+1 hour
CEST (Central Europe Summer Time), 定义为 UTC+2 hours
EET (Eastern Europe Time), 定义为 UTC+2 hours
EEST (Eastern Europe Summer Time), 定义为 UTC+3 hours
MSK (Moscow Time), 定义为 UTC+3 hours
MSD (Moscow Summer Time), 定义为 UTC+4 hours
AST (Atlantic Standard Time), 定义为 UTC-4 hours
ADT (Atlantic Daylight Time), 定义为 UTC-3 hours
NST (Newfoundland Standard Time), 定义为 UTC-3.5 hours
NDT (Newfoundland Daylight Time), 定义为 UTC-2.5 hours
EST (Eastern Standard Time), 定义为 UTC-5 hours
EDT (Eastern Daylight Saving Time), 定义为 UTC-4 hours
CST (Central Standard Time), 定义为 UTC-6 hours
CDT (Central Daylight Saving Time), 定义为 UTC-5 hours
MST (Mountain Standard Time), 定义为 UTC-7 hours
MDT (Mountain Daylight Saving Time), 定义为 UTC-6 hours
PST (Pacific Standard Time), 定义为 UTC-8 hours
PDT (Pacific Daylight Saving Time), 定义为 UTC-7 hours
HST (Hawaiian Standard Time), 定义为 UTC-10 hours
AKST (Alaska Standard Time), 定义为 UTC-9 hours
AKDT (Alaska Standard Daylight Saving Time), 定义为 UTC-8 hours
AEST (Australian Eastern Standard Time), 定义为 UTC+10 hours
AEDT (Australian Eastern Daylight Time), 定义为 UTC+11 hours
ACST (Australian Central Standard Time), 定义为 UTC+9.5 hours
ACDT (Australian Central Daylight Time), 定义为 UTC+10.5 hours
AWST (Australian Western Standard Time), 定义为 UTC+8 hours
*/
struct Region{
    string name;
    float offset;
} region[32]={
    {"UTC",0},{"GMT",0},{"BST",1},{"IST",1},
    {"WET",0},{"WEST",1},{"CET",1},{"CEST",2},
    {"EET",2},{"EEST",3},{"MSK",3},{"MSD",4},
    {"AST",-4},{"ADT",-3},{"NST",-3.5},{"NDT",-2.5},
    {"EST",-5},{"EDT",-4},{"CST",-6},{"CDT",-5},
    {"MST",-7},{"MDT",-6},{"PST",-8},{"PDT",-7},
    {"HST",-10},{"AKST",-9},{"AKDT",-8},{"AEST",10},
    {"AEDT",11},{"ACST",9.5},{"ACDT",10.5},{"AWST",8}
};
Region toRegion(string& str){
    for(int i=0;i<32;i++){
        if(str==region[i].name){
            return region[i];
        }
    }
    return region[0];
}
string a;
Region fromRegion,targetRegion;
int main(){
    int total,hour,minute;
    cin>>total;
    while(total--){
        cin>>a;
        if(a[0]=='n'){
            hour=12,minute=0;
        }else if(a[0]=='m'){
            hour=24,minute=0;
        }else{
            hour=0,minute=0;
            int i=0;
            while(a[i]!=':'){
                hour*=10;
                hour+=a[i]-'0';
                i++;
            }
            for(i++;i<a.size();i++){
                minute*=10;
                minute+=a[i]-'0';
            }
            cin>>a;
            if(hour==12)hour-=12;
            if(a[0]=='p'){
                hour+=12;
            }
        }
        cin>>a;
        fromRegion=toRegion(a);
        cin>>a;
        targetRegion=toRegion(a);
        float offset = targetRegion.offset-fromRegion.offset;
        hour+=(int)offset;
        if((offset-(int)offset)<0.6&&(offset-(int)offset)>0.4){
            minute+=30;
            hour+=minute/60;
            minute%=60;
        }
        hour%=24;
        if(hour==12&&minute==0){
            cout<<"noon"<<endl;
        }else if(hour==0&&minute==0){
            cout<<"midnight"<<endl;
        }else{
            bool mor = true;
            if(hour>=12){
                hour-=12;
                mor=false;
            }
            if(hour==0)hour=12;
            cout<<hour<<":"<<minute<<" "<<(mor?"a.m.":"p.m.")<<endl;
        }
    }
    return 0;
}
