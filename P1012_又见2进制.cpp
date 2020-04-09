#include <cstdio>
int count(int a){
    if(a<2)return a;
    return count(a/2)+a%2;
}
int main(){
    int a,n;
    scanf("%d",&n);
    while(n--&&scanf("%d",&a)!=EOF)printf("%d\n",count(a));
    return 0;
}