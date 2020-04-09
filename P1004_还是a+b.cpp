#include <iostream>
#include <string>
using namespace std;
string add(string a,string b){
    int bit_a,bit_b,overflow=0;
    string ans;
    for(int i=1;i<=a.length();i++,overflow/=10){
        if(b.length()>=i)bit_b = b[b.length()-i]-'0';
        else bit_b = 0;
        bit_a = a[a.length()-i]-'0',overflow+=bit_a+bit_b,ans=(char)(overflow%10+'0')+ans;
    }
    if(overflow!=0)ans=(char)(overflow+'0')+ans;
    return ans;
}
int main(){
    string a,b;
    while(cin>>a>>b)cout<<(a.length()>b.length()?add(a,b):add(b,a))<<endl;
    return 0;
}