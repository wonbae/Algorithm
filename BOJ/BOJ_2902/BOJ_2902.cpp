#include <iostream>
using namespace std;

int main(){
    string str;
    string tmp;
    cin>>str;

    for(int i = 0; i < str.length(); i++){
        if(str[i] >= 65 && str[i] <= 90){
            tmp += str[i];
        }
    }
    cout<<tmp<<"\n";

    return 0;
}