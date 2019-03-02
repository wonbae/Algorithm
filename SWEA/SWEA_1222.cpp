#include <iostream>
#include <stack>
 
using namespace std;
 
int main(void) {
    int Len;
    char temp;
    string input;
 
 
    for(int tc = 1; tc <= 10; tc++) {
        string postfix = "";
 
        cin >> Len;
        cin >> input;
 
        for(int i = 0; i < Len; i++) {
            if(input.at(i) == '+') {
                postfix += input.at(++i);
                postfix += '+';
            } else {
                postfix += input.at(i);
            }
        }
        // cout<<"postfix : "<< postfix<<endl;
 
        int answer = 0;
        for(int i = 0; i < Len; i++) {
            if(postfix.at(i) != '+'){
                
                // cout<<"what : ["<<i<<"] "<<(postfix.at(i) - '0')<<endl; //ASCII '0' -> 48
                // cout<<"none : ["<<i<<"] "<<postfix.at(i)<<endl;
                // cout<<"======================== "<<endl;
                answer += (postfix.at(i) - '0');
            }
        }
 
        cout << "#" << tc << " " << answer << endl;
    }
 
    return 0;
}
