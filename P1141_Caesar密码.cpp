#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string str;
    while (getline(cin,str), str != "ENDOFINPUT"){
        getline(cin,str);
        for (int i = 0; i < str.size(); i++){
            if (str[i] <= 'Z' && str[i] >= 'A'){
                str[i] -= 5;
                if (str[i] < 'A')
                    str[i] += 26;
            }
        }
        cout << str << endl;
        getline(cin,str);
    }
    return 0;
}
