#include <iostream>

using namespace std;
long long gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    int a,b,n;
    cin>>n;
    while(n--){
        cin>>a>>b;
        cout<<a/gcd(a,b)*b<<endl;
    }
    return 0;
}
