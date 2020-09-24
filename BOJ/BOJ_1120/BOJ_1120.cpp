#include<iostream>
using namespace std;

int main(){
    int cnt = 0, mini = 2147000000;
    string a, b;
    cin>>a>>b;

    for(int i = 0; i <= b.length() - a.length(); i++){
        cnt = 0;
        for(int j = 0; j < a.length(); j++){
            if(a[j] != b[j + i]) cnt++;
        }
        if(mini > cnt) mini = cnt;
    }
    cout<<mini<<"\n";
    return 0;
}