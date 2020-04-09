#include <iostream>

using namespace std;

int f(int n){
    if(n==1){
        return 0;
    }
    return 1+(n&1?f((3*n+1)/2):f(n/2));
}
int main(){
    int n;
    while(cin>>n)cout<<f(n)<<endl;
    return 0;
}