#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    string str;
    while(cin>>str,str!="ENDOFINPUT"){
        while(cin>>str,str!="END"){
            for(int i=0;i<str.size();i++){
                if(str[i]<='Z'&&str[i]>='A'){
                    str[i]-=5;
                    if(str[i]<'A')str[i]+=26;
                }
            }
            cout<<str<<" ";
        }
        cout<<endl;
    }
    return 0;
}
