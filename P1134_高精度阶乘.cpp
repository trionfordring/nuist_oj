#include <iostream>
#include <sstream>
using namespace std;
string add(string a,string b){
    int overflow = 0,i,k=0;
    char buf[3001],ans[3001];
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
string moveLeft(string a,int v){
    while(v--)a+="0";
    return a;
}
string mutiply(string a,int b){
    if(b==0)return "0";
    int overflow = 0,i,k=0;
    char buf[3001],ans[3001];
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
string factorial(int n){
    string ans="1";
    for(int i=2;i<=n;i++){
        ans=mutiply(ans,toString(i));
    }
    return ans;
}
int main(){
    int n;
    while(cin>>n){
        cout<<factorial(n)<<endl;
    }
    return 0;
}
