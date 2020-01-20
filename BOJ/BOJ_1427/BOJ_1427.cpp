#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int numbers[10] = {0,};
    string str;

    cin>>str;

    int len = str.length();

    for(int i = 0; i < len; i++){
        numbers[str[i] - 48]++;
    }

    for(int i = 9; i >= 0; i--){
        if(numbers[i] > 0){
            for(int j = 0; j < numbers[i]; j++){
                cout<<i;
            }
        }
    }
    cout<<"\n";

    return 0;
}