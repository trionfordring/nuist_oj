#include <iostream>
#include <algorithm>
using namespace std;
int n,a,b,c,i;
int main(){
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        if(a>b)swap(a,b);
        if(a>c)swap(a,c);
        for(i=a;i>1;i--){
            if(a%i==0&&b%i==0&&c%i==0)break;
        }
        cout<<i<<endl;
    }
    return 0;
}