#include<iostream>
#include<stack>
#include<string>
using namespace std;

int postfix(string str) {
    string post;
    stack <char> tmp;
    stack <int> calc;
    for (int i = 0; i < str.length(); i++) {//convert
        if (str[i] - 48 >= 0 && str[i] - 48 <= 9) post += str[i];//출력
        else {
            if (str[i] == '+') {
                if (tmp.empty()) {
                    tmp.push(str[i]); continue;
                }
                if (tmp.top() == '+' || tmp.top() == '*') {
                    while (tmp.top() == '+' || tmp.top() == '*') {
                        post += tmp.top();
                        tmp.pop();
                        if (tmp.empty()) break;
                    }
                }
                tmp.push(str[i]);
            }
            else if (str[i] == '*') tmp.push(str[i]);
        }
    }
    while (!tmp.empty()) { post += tmp.top(); tmp.pop(); }

    for (int i = 0; i < post.length(); i++) {//calc
        int op1, op2;
        if (post[i] - '0' >= 0 && post[i] - '0' <= 9) calc.push(post[i] - '0');
        else {
            if (post[i] == '+') {
                op1 = calc.top(); 
                calc.pop();
                op2 = calc.top(); 
                calc.pop();
                calc.push(op2 + op1);
            }
            else if (post[i] == '*') {
                op1 = calc.top(); 
                calc.pop();
                op2 = calc.top(); 
                calc.pop();
                calc.push(op2 * op1);
            }
        }
    }
    int answer = calc.top();
    return answer;
}

int main() {
    for (int t = 1; t <= 10; t++) {
        int len;
        string str;
        cin >> len;
        cin >> str;
        cout << "#" << t << ' ' << postfix(str) << endl;
    }
    return 0;
}