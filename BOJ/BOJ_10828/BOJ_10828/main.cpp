//
//  main.cpp
//  BOJ_10828
//
//  Created by 김원배 on 13/01/2019.
//  Copyright © 2019 김원배. All rights reserved.
//

#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int main() {
    stack<int>s;
    int T;
    cin>>T;
    string command;
    int num;
    
    
    for(int i = 0; i < T; i++){
        cin>>command;
        if(command == "push"){
            cin>>num;
            s.push(num);
        }
        else if(command == "top"){
            if(s.empty()){
                cout<<-1<<endl;
            }else{
                cout<<s.top()<<endl;
            }
        }
        else if(command == "size"){
            cout<<s.size()<<endl;
        }
        else if(command == "pop"){
            if(s.empty()){
                cout<<-1<<endl;
            }else{
                
                cout<<s.top()<<endl;
                s.pop();
            }
        }
        else if(command == "size"){
            cout<<s.size()<<endl;
        }
        else if(command == "empty"){
            cout<<s.empty()<<endl;
        }
    }
    return 0;
}
