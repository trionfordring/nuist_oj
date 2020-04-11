#include <iostream>
#include <cstring>
using namespace std;
const int maxn=10010;
int prime[maxn]={0},visit[maxn]={0},cnt=0,n;
void linearFilter(){
    memset(prime,0,n*sizeof(int));
    memset(visit,0,(n+10)*sizeof(int));
    cnt=0;
    for (int i = 2;i <= n; i++) {
        if (!visit[i])prime[cnt++] = i;
        for (int j = 0; j <cnt && i*prime[j] <= n; j++) {
            visit[i*prime[j]] = 1;
            if (i%prime[j]==0)break;
        }
    }
}
int main(){
    while(cin>>n){
        linearFilter();
        for(int i=cnt-1;i>0;i--){
            if(prime[i]-prime[i-1]==2){
                cout<<prime[i-1]<<" "<<prime[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
