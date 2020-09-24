#include<iostream>
using namespace std;

int main(){
    string input;
    int num = 0, ans = 0;
    int flag = 1;
    
    cin>>input;

    for(int i = 0; i < input.length(); i++){
        if(input[i] == '-' || input[i] == '+'){
            if(input[i] == '-'){
                flag = -1;
                ans += num;
                num = 0;
            }else if(input[i] == '+'){
                ans += num;
                num = 0;
            }
        }else{
            num = (flag * (input[i] - '0')) + (num * 10);
        }
    }
    ans += num;
    cout<<ans<<"\n";

    return 0;
}