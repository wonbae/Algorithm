#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int n, p = 0, input;
    string str = "";
    stack<int> st;
    cin>>n;
    vector<int> v(n);
    for(int i = 1; i <= n; i++){
        v[i - 1] = i;
    }

    for(int i = 0; i < n; i++){

        cin>>input;
        st.push(input);
        str += "P";

        while(v[p] == st.top()){
            st.pop();
            str += "O";
            p++;
            if(st.empty()) break;
        }
    }

    if(!st.empty()) cout<<"impossible";
    else cout<<str<<"\n";

    return 0;
}