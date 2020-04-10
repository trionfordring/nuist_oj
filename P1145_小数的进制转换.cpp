#include <iostream>
#include <sstream>
using namespace std;
string add(string a,string b){
    int overflow = 0,i,k=0;
    char buf[3010],ans[3010];
    for(i=0;i<a.size()||i<b.size();i++){
        int av = i<a.size()?a[a.size()-i-1]-'0':0,bv = i<b.size()?b[b.size()-i-1]-'0':0;
        buf[i]=(av+bv+overflow)%10+'0';
        overflow = (av+bv+overflow)/10;
    }
    if(overflow!=0)ans[k++]=overflow+'0';
    for(i--;i>=0;i--){
        ans[k++]=buf[i];
    }
    ans[k]='\0';
    return string(ans);
}
string sub(string a,string b){
    int overflow = 0,i,k=0;
    char buf[3010],ans[3010];
    for(i=0;i<a.size();i++){
        int av = i<a.size()?a[a.size()-i-1]-'0':0,bv = i<b.size()?b[b.size()-i-1]-'0':0;
        int v = av-bv+overflow;
        if(v<0)overflow=-1,v+=10;
        else overflow=0;
        buf[i]=v+'0';
    }
    i--;
    while(buf[i]=='0')i--;
    for(;i>=0;i--){
        ans[k++]=buf[i];
    }
    ans[k]='\0';
    return string(ans);
}
string moveLeft(string a,int v){
    if(a[0]=='0')return "0";
    while(v--)a+="0";
    return a;
}
string mutiply(string a,int b){
    if(b==0)return "0";
    int overflow = 0,i,k=0;
    char buf[3010],ans[3010];
    for(i=0;i<a.size();i++){
        int av = i<a.size()?a[a.size()-i-1]-'0':0;
        overflow+=av*b;
        buf[i]=overflow%10+'0';
        overflow/=10;
    }
    if(overflow!=0)ans[k++]=overflow+'0';
    for(i--;i>=0;i--){
        ans[k++]=buf[i];
    }
    ans[k]='\0';
    return string(ans);
}
string mutiply(string a,string b){
    string ans="0";
    int idx=0;
    for(int i=b.size()-1;i>=0;i--)ans=add(ans,moveLeft(mutiply(a,b[i]-'0'),idx++));
    return ans;
}
string toString(int a){
    stringstream ss;
    ss<<a;
    return ss.str();
}
//比较高精度整数大小
//返回-1 0 1 分别表示a 小于/等于/大于 b
int compare(string a,string b){
    if(a.size()>b.size())return 1;
    if(a.size()<b.size())return -1;
    for(int i=0;i<a.size();i++){
        if(a[i]>b[i]){
            return 1;
        }
        if(a[i]<b[i]){
            return -1;
        }
    }
    return 0;
}
string division(string a,string b){
    char buf[3010],cnt=2;
    a=moveLeft(a,1);
    buf[0]='0',buf[1]='.';
    while(a[0]!='0'){
        int num=0;
        while(compare(a,b)>=0){
            a=sub(a,b);
            num++;
        }
        buf[cnt++]=num+'0';
        a=moveLeft(a,1);
    }
    buf[cnt]='\0';
    return string(buf);
}
string oct2dec(string a){
    string bottom = "1";
    string num = "0";
    for(int i=a.size()-1;a[i]!='.';i--){
        num=add(num,mutiply(bottom,a[i]-'0'));
        bottom=mutiply(bottom,8);
    }
    return division(num,bottom);
}
int main(){
    string a;
    while(cin>>a){
        cout<<a<<"[8]="<<oct2dec(a)<<"[10]"<<endl;
    }
    return 0;
}
