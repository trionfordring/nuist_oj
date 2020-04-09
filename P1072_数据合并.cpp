#include <iostream>
#include <algorithm>
using namespace std;
int m,n,a[200];
int main(){
    while(cin>>m>>n){
        for(int i=0;i<m+n;i++)cin>>a[i];
        sort(a,a+m+n);
        for(int i=0;i<m+n;i++)cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}