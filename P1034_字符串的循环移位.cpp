#include <iostream>
#include <string>

using namespace std;

int main(){
    int k;
    string str;
    while(cin>>k>>str)cout<<str.substr(k%str.size())<<str.substr(0,k%str.size())<<endl;
}