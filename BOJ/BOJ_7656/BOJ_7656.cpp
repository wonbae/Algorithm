// #include<iostream>
// #include<string>
// #include<vector>
// #include<algorithm>
// #include<sstream>
// using namespace std;

// int main(){
//     ios_base::sync_with_stdio(0), cin.tie(NULL);
    
//     string input;
//     getline(cin, input);
    
//     bool flag = false;
//     string tmp;
//     vector<string> sv;
//     vector<string> x;

//     for(int i = 0; i < input.length(); i++){
//         if(input[i] >= 65 && input[i] <= 90){
//             flag = true;
//         }
//         if(flag){
//             if(input[i] == '?' || input[i] == '.'){
//                 tmp += '.';
//                 flag = false;
//                 sv.push_back(tmp);
//                 tmp="";
//             }else{
//                 tmp += input[i];
//             }
//         }
//     }

//     vector<string> sv2;

//     for(int i = 0; i < sv.size(); i++){
//         tmp = "";
//         flag = false;
//         for(int j = 0; j < sv[i].length(); j++){
//             tmp+=sv[i][j];
//             if(tmp == "What is "){
//                 flag = true;
//             }
//         }
//         if(flag){
//             sv2.push_back(tmp);
//         }
//     }

    
//     string stringBuffer;
//     bool flag2 = false;

//     for(auto a : sv2){
//         istringstream ss(a);
//         flag2 = false;
//         while(getline(ss, stringBuffer, ' ')){
//             if(stringBuffer == "What"){
//                 flag2 = true;
//                 x.push_back("Forty-two");
//                 continue;
//             }
//             if(flag2){
//                 x.push_back(stringBuffer);
//             }else{
                
//             }
            
//         }
//     }
    
//     string ans;

//     for(int i = 0; i < x.size(); i++){
//         if(x[i][x[i].length()-1] == '.'){
//             ans += x[i];
//             cout<<ans<<"\n";
//             ans = "";
//         }else{
//             ans += x[i] + " ";
//         }
//     }
//     return 0;
// }



// import sys

// strings = sys.stdin.readline().rstrip().split("What")
// for string in strings:
//     if '?' in string:
//         idx = string.find("?")
//         string = string[:idx+1]
//         string = string.replace("?", ".")
//         print(f"Forty-two{string}")

#include <iostream>
#include <string>
using namespace std;

string Q = "What";
string S = "Forty-two";

int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL);
    string input;
    getline(cin, input);
    
    string temp = "";
    for(int i = 0; i < input.size(); i++) {
        if(input[i] == '?') {
            temp += ".";
            cout << temp << "\n";
            temp = "";
        }
        else if (input[i] == '.') {
            temp = "";
        }
        else if (input[i] == ' ' && temp.size() == 0) {
            continue;
        }
        else {
            temp += input[i];
            if(temp == Q) {
                temp = S;
            }
        }
    }   
    return 0;
}