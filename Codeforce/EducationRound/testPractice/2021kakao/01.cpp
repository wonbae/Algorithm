#include <string>
#include <vector>

#include <iostream>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";
    string str = new_id;
    
    // int len = new_id.length();
    int dot_cnt = 0;
    char sc[] = "~!@#$%^&*()=+[{]}:?,<>";
    
    for(int i = 0; i < str.length(); i++){
        // 1.대문자 -> 소문자
        if(str[i] >= 65 && str[i] <= 90){
            str[i] = str[i] + 32;
        }
    }
    cout<<"1: "<<str<<"\n";
    
    for(int i = 0; i < str.length(); i++){
        // 2.문자 제거
        if((str[i] >= 97 && str[i] <= 122) || 
           (str[i] >= 48 && str[i] <= 57) || 
           (str[i] == '-') || (str[i] == '_') || (str[i] == '.')){
            continue;
        }else{
            for(int j = 0; j < 22; j++){
                if(sc[j] == str[i]){
                    // cout<<"\n"<<"erase : "<<str[i]<<"\n";
                    str.erase(std::find(str.begin(), str.end(), sc[j]));   
                    // cout<<str<<"\n";
                }
            }
        }   
    }
    cout<<"2: "<<str<<"\n";
    
    // 3.마침표 치환
    bool flag = false;
    int first = 0, cnt = 1;
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '.'){
            first = i;
            for(int j = i + 1; j < str.length(); j++){
                if(str[j] == '.'){
                    cnt++;
                    flag = true;
                    
                }else{
                    if(flag){
                        // cout<<first<<", "<<cnt<<"\n";
                        str.replace(first, cnt, ".");
                        cnt = 1;
                        flag = false;
                        break;    
                    }else{
                        break;
                    }
                }
            }
            if(flag){
                str.replace(first, cnt, ".");
            }
        }
    }
    cout<<"3: "<<str<<"\n";
    
    if(str[0] == '.'){
        str.erase(0,1);
    }
    if(str[str.length() - 1] == '.'){
        str.erase(str.length() - 1, 1);
    }
    cout<<"4: "<<str<<"\n";
    
    if(str.empty()){
        // str.append("a");
        str+="a";
    }
    cout<<"5: "<<str<<"\n";
    
    if(str.length() >= 16){
        int ll = str.length() - 15;
        str.erase(15, ll);
        if(str[str.length() - 1] == '.'){
            str.erase(str.length() - 1, 1);
        }
    }
    cout<<"6: "<<str<<"\n";
    
    if(str.length() <= 2){
        while(str.length() < 3){
            str += str[str.length()-1];
        }
    }
    cout<<"7: "<<str<<"\n";
    answer = str;
    return answer;
}