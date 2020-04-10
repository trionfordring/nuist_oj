#include <cstdio>

using namespace std;

/*   法一：dfs的方法实测wa

int n,a[12];
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
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)visd[i]=false;
        dfs(0,0);
    }
    return 0;
}

*/

