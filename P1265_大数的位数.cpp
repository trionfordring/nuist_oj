#include <iostream>
#include <cmath>
using namespace std;

const double e = 2.71828182845;
const double pi = 3.1415926;
int main(void){
    int n,ans,total;
    cin>>total;
    while(total--){
        cin>>n;
        cout<<1+(int)(log10(2*pi*n)/2+n*log10(n/e))<<endl;
    }
    return 0;
}