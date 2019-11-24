#include <bits/stdc++.h>
using namespace std;

int main(){
    stack<int> st;

    int T,num;
    cin>>T;

    for(int i = 0; i < T; i++){
        cin>>num;
        
        if(num == 0){
            st.pop();
        }else{
            st.push(num);
        }
    }

    int sum = 0;
    while(!st.empty()){
        sum += st.top();
        st.pop();
    }

    cout<<sum<<"\n";

    return 0;
}