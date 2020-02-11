#include<bits/stdc++.h>
using namespace std;
#define SIZE 10000

// vector<int> dq;
deque<int> dq;
int T;

void dqprint(){
    for(int i = 0; i < dq.size(); i++){
        cout<<dq[i]<<" ";
    }
    cout<<endl;
}

void push_back(int num){
    dq.push_back(num);
}

void push_front(int num){
    dq.push_front(num);
}

int pop_back(){

    if(dq.empty()){
        return -1;
    }

    int b = dq.back();
    
    dq.pop_back();

    return b;
}

int pop_front(){
    int f = 0;
    if(dq.empty()){
        return -1;
    }else{
        f = dq.front();
        dq.pop_front();
        return f;
    }
   
}

int front(){
    if(dq.empty()){
        return -1;
    }

    return dq.front();
}

int back(){
    if(dq.empty()){
        return -1;
    }

    return dq.back();
}

int size(){
    // if(dq.size() == 0) return -1;
    return dq.size();
}

bool empty(){
    if(dq.size() == 0){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int T;
    string command = "";
    int num = 0;

    cin>>T;

    for(int i = 0 ; i < T; i++){
        cin>>command;

        if(command == "push_back"){
            cin>>num;
            push_back(num);
        }
        else if(command == "push_front"){
            cin>>num;
            push_front(num);
        }
        else if(command == "pop_back"){
            cout<<pop_back()<<"\n";
        }
        else if(command == "pop_front"){
            cout<<pop_front()<<"\n";
        }
        else if(command == "front"){
            cout<<front()<<"\n";
        }
        else if(command == "back"){
            cout<<back()<<"\n";
        }
        else if(command == "size"){
            cout<<size()<<"\n";
        }
        else if(command == "empty"){
            cout<<empty()<<"\n";
        }
    }



    return 0;
}