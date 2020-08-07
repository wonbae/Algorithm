#include<iostream>
#include<math.h>
#include<stack>
using namespace std;

int main(){
    int n, k, res = 0;
    stack<int> st;
    cin>>n>>k;
    char str[20] = "0123456789ABCDEF";

    while(n > 0){
        st.push(n % k);
        n = n / k;
    }

    while(!st.empty()){
        cout<<str[st.top()];
        st.pop();
    }

    return 0;
}