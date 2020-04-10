#include <iostream>
#include <string>
using namespace std;
string add(string& a,string& b){
    int overflow = 0,i,k=0;
    char buf[210],ans[210];
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
int main(){
    string a,b;
    while(cin>>a>>b){
        cout<<add(a,b)<<endl;
    }
    return 0;
}
