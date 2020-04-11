#include <iostream>

using namespace std;

int main(){
    int n;
    while(cin>>n){
        long long ans=1;
        while(n-->1)ans++,ans*=2;
        cout<<ans<<endl;
    }
    return 0;
}
