#include <iostream>
#include <cstring>
using namespace std;
int a[10][10],b[10][10],n;
void draw(int x,int y,int v){
    for(int i=0;i<8;i++){
        b[i][x]+=v;
        b[y][i]+=v;
        if(x-i>=0&&y-i>=0)b[y-i][x-i]+=v;
        if(x+i< 8&&y+i< 8)b[y+i][x+i]+=v;
        if(x-i>=0&&y+i< 8)b[y+i][x-i]+=v;
        if(x+i< 8&&y-i>=0)b[y-i][x+i]+=v;
    }
    // cout<<"("<<x<<","<<y<<") ["<<v<<"]"<<endl;
    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         cout<<b[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
int dfs(int i,int cnt){
    if(i==8){
        if(cnt==8-n)
            return 1;
        else return 0;
    }
    int n=0;
    for(int j=0;j<8;j++){
        if(a[i][j]){
            return dfs(i+1,cnt);
        }
        if(b[i][j]==0){
            draw(j,i,1);
            n+=dfs(i+1,cnt+1);
            draw(j,i,-1);
        }
    }
    return n;
}
int main(){
    while(cin>>a[0][0]){
        memset(b,0,sizeof(b));
        n=0;
        for(int i=1;i<8;i++)cin>>a[0][i];
        for(int i=1;i<8;i++)for(int j=0;j<8;j++)cin>>a[i][j];
        for(int i=0;i<8;i++)for(int j=0;j<8;j++)if(a[i][j])draw(j,i,1),n++;
        cout<<dfs(0,0)<<endl;
    }
    return 0;
}
