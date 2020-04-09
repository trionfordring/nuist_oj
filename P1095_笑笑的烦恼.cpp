#include <iostream>
#include <algorithm>
#include <iomanip>
#include <climits>
using namespace std;

int main(){
    long long n,cnt,maxScore,minScore,sum,a;
    cin>>n;
    while(n--){
        cnt=0,maxScore=LLONG_MIN,minScore=LLONG_MAX,sum=0;
        while(cin>>a,a!=-1)cnt++,sum+=a,maxScore=max(maxScore,a),minScore=min(minScore,a);
        double average = (double)sum/cnt;
        cout<<cnt<<endl<<maxScore<<endl<<minScore<<endl<<setprecision(1)<<fixed<<average<<endl;
    }
    return 0;
}