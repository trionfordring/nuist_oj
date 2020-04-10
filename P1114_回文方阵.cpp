#include <iostream>

using namespace std;
int a[1000][1000],n,dir[4][2]={{0,1},{-1,0},{0,-1},{1,0}};
void draw(int i,int x,int y,int d){
    a[y][x]=i;
    if(i==n*n)return;
    int next_x = x+dir[d][0],next_y = y+dir[d][1];
    if(a[next_y][next_x]!=0||next_y>n||next_x>n||next_x<1||next_y<1)d++,d%=4;
    draw(i+1,x+dir[d][0],y+dir[d][1],d);
}
int main(){
    while(cin>>n){
        for(int i=0;i<=n+1;i++)for(int j=0;j<=n+1;j++){
            a[i][j]=0;
        }
        draw(1,n,1,0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
