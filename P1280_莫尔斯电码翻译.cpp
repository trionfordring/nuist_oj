#include <iostream>
#include <string>
using namespace std;
string list[]={
    ".-","-...","-.-.","-..",".","..-.",
    "--.","....","..",".---","-.-",".-..",
    "--","-.","---",".--.","--.-",".-.",
    "...","-","..-","...-",".--","-..-",
    "-.--","--..",".----","..---","...--",
    "....-",".....","-....","--...","---..",
    "----.","-----"
};
string to(char a){
    int ans;
    switch (a){
        case 'A': case 'a': ans=0;break;
        case 'B': case 'b': ans=1;break;
        case 'C': case 'c': ans=2;break;
        case 'D': case 'd': ans=3;break;
        case 'E': case 'e': ans=4;break;
        case 'F': case 'f': ans=5;break;
        case 'G': case 'g': ans=6;break;
        case 'H': case 'h': ans=7;break;
        case 'I': case 'i': ans=8;break;
        case 'J': case 'j': ans=9;break;
        case 'K': case 'k': ans=10;break;
        case 'L': case 'l': ans=11;break;
        case 'M': case 'm': ans=12;break;
        case 'N': case 'n': ans=13;break;
        case 'O': case 'o': ans=14;break;
        case 'P': case 'p': ans=15;break;
        case 'Q': case 'q': ans=16;break;
        case 'R': case 'r': ans=17;break;
        case 'S': case 's': ans=18;break;
        case 'T': case 't': ans=19;break;
        case 'U': case 'u': ans=20;break;
        case 'V': case 'v': ans=21;break;
        case 'W': case 'w': ans=22;break;
        case 'X': case 'x': ans=23;break;
        case 'Y': case 'y': ans=24;break;
        case 'Z': case 'z': ans=25;break;
        case '0':ans=26;break;
        case '1':ans=27;break;
        case '2':ans=28;break;
        case '3':ans=29;break;
        case '4':ans=30;break;
        case '5':ans=31;break;
        case '6':ans=32;break;
        case '7':ans=33;break;
        case '8':ans=34;break;
        case '9':ans=35;break;
    default:
        break;
    }
    return list[ans];
}
int main(){
    string a;
    while(cin>>a){
        for(int i=0;i<a.size()-1;i++){
            cout<<to(a[i])<<"===";
        }
        cout<<to(a[a.size()-1])<<endl;
    }
    return 0;
}
