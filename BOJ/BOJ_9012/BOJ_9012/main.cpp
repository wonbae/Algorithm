//
//  main.cpp
//  BOJ_9012
//
//  Created by 김원배 on 13/01/2019.
//  Copyright © 2019 김원배. All rights reserved.
//

#include<iostream>
#include <string.h>
#include <stack>
using namespace std;
int main(){
    int T;
    cin>>T;
    
    string str;
    int Len = 0;
    stack<char> s;
    
    for(int i = 0; i < T; i++){
        cin>>str;
        int count = 0;
        Len = int(str.length());
        
        for(int j = 0; j < Len; j++){
            
            if(str[j]=='('){
                count++;
            }
            else{
                if(s.empty()){
                    
                    count--;
                }
                else{
                    
                    count--;
                }
                if(count<0){
                    break;
                }
            }
        }
        if(count == 0){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
