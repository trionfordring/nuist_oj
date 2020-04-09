#include <cstdio>
#include <algorithm>
using namespace std;

int a[2][1010],n;
int main(){
    while (scanf("%d%d",&n,&a[0][0])!=EOF){
        for(int i=1;i<n;i++){
            for(int k=0;k<=i;k++){
                scanf("%d",&a[i%2][k]);
            }
            a[i%2][0]+=a[(i-1)%2][0],a[i%2][i]+=a[(i-1)%2][i-1];
            for(int k=1;k<i;k++)a[i%2][k]+=min(a[(i-1)%2][k-1],a[(i-1)%2][k]);
        }
        int ans=a[(n+1)%2][0];
        for(int i=1;i<n;i++)ans=min(ans,a[(n+1)%2][i]);
        printf("%d\n",ans);
    }
    return 0;
}