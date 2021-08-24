#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL);
    int T;

    cin>>T;

    while(T--){
        string command;
        cin>>command;

        int N;
        cin>>N;

        string numbers;
        cin>>numbers;

        deque<int> dq;
        string tmp = "";

        for(int i = 0; i < numbers.size(); i++){
            if(numbers[i] == '[') continue;
            else if(numbers[i] >= '0' && numbers[i] <= '9'){
                tmp+=numbers[i];
            }else if(numbers[i] == ',' || numbers[i] == ']'){
                if(!tmp.empty()){
                    dq.push_back(stoi(tmp));
                    tmp.clear();
                }
            }
        }

        bool flag = true;
        bool empty_numbers = false;
            
        for(int i = 0; i < command.size(); i++){
            if(command[i] == 'R'){
                    flag = !flag;
                }else{
                    if(!dq.empty()){
                        if(flag){
                            dq.pop_front();
                        }else{
                            dq.pop_back();
                        }
                    }else{
                        empty_numbers = true;
                        cout<<"error\n";
                        break;
                    }
                }
            }

            if(!empty_numbers){
                cout<<"[";
                if(flag){
                    while(!dq.empty()){
                        cout<<dq.front();
                        dq.pop_front();
                        if(!dq.empty()){
                            cout<<",";
                        }
                    }
                }else{
                    while(!dq.empty()){
                        cout<<dq.back();
                        dq.pop_back();
                        if(!dq.empty()){
                            cout<<",";
                        }
                    }
                }
                cout<<"]\n";
            }
        }
    
    return 0;
}