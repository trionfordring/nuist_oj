#include <cstdio>
#include <algorithm>
using namespace std;
int n,a[12];
/*
visd标志数组的方法被这题ban了
bool visd[12];
void dfs(int i,int cnt){
    a[cnt]=i;
    if(cnt==n){
        for(int j=1;j<=n;j++)printf("%d",a[j]);
        printf("\n");
        return;
    }
    visd[i]=true;
    for(int i=1;i<=n;i++){
        if(!visd[i]){
            dfs(i,cnt+1);
        }
    }
    visd[i]=false;
}
*/
void dfs(int i){
    if(i==n){
        for(int j=1;j<=n;j++)printf("%d",a[j]);
        printf("\n");
        return;
    }
    for(int j=i;j<=n;j++){
        swap(a[i],a[j]);
        dfs(i+1);
        swap(a[i],a[j]);
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)a[i]=i;
        dfs(1);
    }
    return 0;
}
