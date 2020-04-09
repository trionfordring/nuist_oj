#include <iostream>
#include <string>

using namespace std;

string maxLen="",minLen="",buf;
int main(){
    while(cin>>buf){
        if(minLen.size()==0)minLen=buf;
        if(buf.size()>maxLen.size())maxLen=buf;
        if(buf.size()<minLen.size())minLen=buf;
    }
    cout<<maxLen<<"\n"<<minLen<<endl;
    return 0;
}