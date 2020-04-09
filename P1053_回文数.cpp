#include <iostream>
#include <string>

using namespace std;

int main(){
    string str;
    while(cin>>str){
        bool ans = true;
        for(int i=0;i<=str.size()/2;i++){
            if(str[i]!=str[str.size()-i-1]){
                ans=false;
                break;
            }
        }
        cout<<(ans?"yes":"no")<<endl;
    }
}