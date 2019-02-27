#include <iostream>
#include <stack>

using namespace std;


int main() {

    int T;
    string test;
    string tmp;
    
    for(int k=0; k<10 ; k++) {
        test = "";
        tmp = "";
        T=0;
        stack<string> stack;

        cin>>T;
        cin >> test;
        
        for (int i = 0; i < T; i++) {
            tmp = test[i];
            if (tmp == ")" || tmp == "]" || tmp == ">" || tmp == "}") {
                if (stack.empty()) {
                    cout <<"#"<<k+1<<"hi" << endl;
                    break;
                }
                else {
                    if ((stack.top() == "(" && tmp == ")") || (stack.top() == "[" && tmp == "]") ||
                        (stack.top() == "<" && tmp == ">") || (stack.top() == "{" && tmp == "}")) {
                        stack.pop();

                    } else {
                        break;
                    }
                }
            } else {
                stack.push(tmp);

            }

        }
        if (stack.empty()) {
            cout <<"#"<<k+1<<" 1" << endl;
        } else {
            cout <<"#"<<k+1<<" "<<"0" << endl;
        }
    }
    return 0;
}

// #include <iostream>
// #include <stack>
// using namespace std;

// int main(){
//     int T;
//     for(int tc = 1; tc < 10; tc++){
//         cin>>T;






//         cout<<"#"<<tc<<" "<<endl;
//     }



//     return 0;
// }