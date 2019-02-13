//
//  main.cpp
//  BOJ_2504
//
//  Created by 김원배 on 13/01/2019.
//  Copyright © 2019 김원배. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <stack>
using namespace std;


int main() {
    stack<char>st;
    char input[33];
    int tmp=1;
    int sum=0;
    
    scanf("%s",input+1);
    
    for(int i = 1; input[i] ; i++){
        switch (input[i]){
            case '(':
                tmp *=2;
                st.push('(');
                break;
            case '[':
                tmp*=3;
                st.push('[');
                break;
                
            case ')':
                if(input[i-1]=='('){
                    sum+=tmp;
                }
                if(st.empty()){
                    cout<<"0";
                    
                }
                if(st.top()=='('){
                    st.pop();
                }
                tmp /= 2;
                break;
                
            case ']':
                if(input[i-1]=='['){
                    sum+=tmp;
                }
                if(st.empty()){
                    cout<<"0";
                    
                }
                if(st.top()=='['){
                    st.pop();
                }
                tmp /= 3;
                break;
            default:
                break;
        }
        
    }
    cout<<(st.empty() ? sum : 0);
    
    return 0;
}
