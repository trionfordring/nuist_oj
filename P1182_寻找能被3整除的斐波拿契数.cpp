#include <iostream>

using namespace std;
int main(){
    int n;
    while(cin>>n)cout<<(n%8==2||n%8==6?"yes":"no")<<endl;
    return 0;
}
