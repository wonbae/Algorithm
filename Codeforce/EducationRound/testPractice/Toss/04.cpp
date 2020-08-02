// stack, string
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// input : 우리 우리 우리 하나 우리 국민 삼성 농협 농협 농협 국민 저축

/* output : 
우리
우리
우리
하나 우리
우리 하나
국민 우리 하나
삼성 국민 우리 하나
농협 삼성 국민 우리 하나
농협 삼성 국민 우리 하나
농협 삼성 국민 우리 하나
국민 농협 삼성 우리 하나
저축 국민 농협 삼성 우리
*/

int main(){

    stack<string> recent;
    string input, tmp = "";
    vector<string> bank;

    getline(cin, input);
    
    for(int i = 0; i < input.length(); i++){
        if(input[i] == ' '){
            bank.push_back(tmp);
            tmp = "";
        }else{
            tmp += input[i];
        }
    }bank.push_back(tmp);

    for(int i = 0; i < bank.size(); i++){
        if(recent.empty()){

        }else{

        }
    }


    return 0;
}
// 모르겠다.. 