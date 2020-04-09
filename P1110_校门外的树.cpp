#include <iostream>
#include <cstring>
using namespace std;

int a[100100],n,k,l,r,cnt;
int main(){
    while(cin>>n>>k){
        memset(a,0,sizeof(int)*(n+10));
        a[0]=1;
        cnt=0;
        while(k--){
            cin>>l>>r;
            a[l]--,a[r+1]++;
        }
        if(a[0]==1)cnt++;
        for(int i=1;i<=n;i++){
            a[i]+=a[i-1];
            if(a[i]==1)cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
