#include <iostream>
#include <string>
using namespace std;
string sub(string& a,string& b){
    int overflow = 0,i,k=0;
    char buf[210],ans[210];
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
int main(){
    string a,b;
    while(cin>>a>>b){
        cout<<sub(a,b)<<endl;
    }
    return 0;
}
