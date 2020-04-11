#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1000010;
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
bool exist(int k,int l,int r){
    if(l>=r){
        return k==prime[l];
    }
    int mid = (l+r)/2;
    if(prime[mid]>k){
        return exist(k,l,mid-1);
    }else if(prime[mid]<k){
        return exist(k,mid+1,r);
    }else{
        return true;
    }
}
int main(){
    while (cin>>n){
        linearFilter();
        bool mk = false;
        for(int i=0;i<cnt;i++){
            if(n%prime[i]==0&&exist(n/prime[i],0,cnt-1)){
                mk=true;
                break;
            }
        }
        cout<<(mk?"Yes":"No")<<endl;
    }
    return 0;
}
