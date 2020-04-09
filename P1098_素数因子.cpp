#include <iostream>
using namespace std;
int a;//a储存的输入的数
int main(){
    while(cin>>a){
        //如果a是一个负数，可以直接输出一个负号，然后把a取绝对值
        if(a<0)a*=-1,cout<<"-";
        //这里使用i从2开始循环，如果a被i整除，就说明i是a的一个因子，直接输出之后让a/=i。
        //这样循环可以保证输出的数一定是由小到大，并且都是素数。（合数因子一定会先被前面的循环分解掉）
        //注意i自加的位置，由于可能会有多个相同的因子，如果一次循环找到了一个因子，i不能自加。
        for(int i=2;a!=1;){//i初始值为2，因为最小因子是2。循环结束的条件为a被除到了1（即为被完全分解了）
            if(a%i==0){//判断i是否为a的因子
                a/=i,cout<<i;
                if(a!=1)cout<<" ";
                else cout<<endl;
            }else i++;
        }
    }
    return 0;
}