#include <cstdio>

using namespace std;

int n       //n储存了当前的问题
,total=0    //已经解决了多少个问题（就是开头的case total：）  
,arr[]={2,3,5,7,11,13,17,19,23,29,31}//储存了1-32的所有素数的表，便于后面对于素数的判断
,ans[100];  //储存答案
bool visd[100]; //储存当前所有数的状态（是否被使用到了）

//这个函数的作用就是判断k是否是素数
bool is(int k){
    for(int i=0;i<11;i++){
        if(k==arr[i]) return true;
    }
    return false;
}

//核心算法
void search(int i,int num){//i代表当前是第i个数，num指当前数的值
    //标记当前的数已经被使用过了
    visd[num]=true;
    //保存答案的数组
    ans[i]=num;

    //递归的边界判断部分
    //当i=n-1时，说明已经到了最后一个数了
    if(i==n-1){
        //判断最后一个数能否和第一个数加起来是素数
        if(is(ans[i]+ans[0])){
            //如果是，则说明一组答案已经出现
            for(int k=0;k<n;k++)printf("%d ",ans[k]);
            printf("\n");
        }
        //到达递归边界
        return;
    }

    //****
    //递归的核心部分
    //从1开始判断每个数是否被用过，如果未被用过，则看看能否和当前数加起来是素数
    for(int k=1;k<=n;k++){
        if(!visd[k]&&is(k+num)){
            //如果两个条件都满足，则尝试一下以此继续搜索
            search(i+1,k);
            //****
            //下一句是状态的回归，返回search调用之前的状态（也就是k没有被用到的状态）
            visd[k]=false;
            //继续遍历
        }
    }
}

int main(){
    while(total++,scanf("%d",&n)!=EOF){
        printf("Case %d:\n",total);
        //先把visd数组置为false
        for(int i=1;i<=n;i++)visd[i]=false;
        //根据题意，以1为开头搜索
        //当前的数是第0个，数值为1
        search(0,1);
        //运行到这一行，已经解决当前的问题了
        //按照题目的暗示，输出一个换行
        printf("\n");
    }
    return 0;
}