#include <iostream>

using namespace std;
int n,k,a[10000];
int main(){
    while(cin>>n>>k){
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cout<<a[(i+k)%n]<<endl;
    }
    return 0;
}