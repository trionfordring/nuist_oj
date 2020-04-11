#include <iostream>

using namespace std;
string a,b;
int main(){
    while(cin>>a>>b){
        int idx=0;
        for(int i=0;i<a.size();i++){
            if(a[i]>a[idx])idx=i;
        }
        cout<<a.substr(0,idx+1)<<b<<a.substr(idx+1)<<endl;
    }
    return 0;
}
