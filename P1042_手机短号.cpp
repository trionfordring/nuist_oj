#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    while(cin>>str)cout<<6<<str.substr(str.size()-5)<<endl;
}