#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    string first = "";
    first = phone_book[0];
    int len = first.length();
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < phone_book.size() - 1; i++){
        if(phone_book[i] == phone_book[i+1].substr(0, phone_book[i].size())){
            answer = false;
            return false;
        }
    }
//     for(int i = 1; i < phone_book.size(); i++){
//         string tmp = "";
//         for(int j = 0; j < len; j++){
//             tmp+=phone_book[i][j];
//             if(first == tmp){
//                 answer = false;
//                 return answer;
//             }
//         }
        
//     }
    
    return answer;
}
