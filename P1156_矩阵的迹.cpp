#include <iostream>
#include <cstring>
using namespace std;
const int MOD = 9973;
const int N = 12;
int buf[N][N],ans[N][N],arr[N][N];
void multi(int a[][N],int b[][N], int n,int mod){
    memset(buf, 0, sizeof(buf));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                buf[i][j] += (a[i][k] * b[k][j]%mod),buf[i][j]%=mod;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = buf[i][j];
}
void fastPow(int a[][N],int n,int b,int mod){
    memset(ans,0,sizeof(ans));
    for(int i=0;i<n;i++)ans[i][i]=1;
    while(b){
        if(b&1)multi(ans,a,n,mod);
        multi(a,a,n,mod);
        b>>=1;
    }
}
int main(){
    int total;
    cin >> total;
    while (total--){
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin>>arr[i][j];
            }
        }
        fastPow(arr,n,k,MOD);
        int res=0;
        for(int i=0;i<n;i++){
            res+=ans[i][i];
            res%=MOD;
        }
        cout<<res<<endl;
    }
    return 0;
}
