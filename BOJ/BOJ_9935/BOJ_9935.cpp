#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    
    string str;
    string boom;
    cin>>str>>boom;

    int strlen = str.length();
    int boomlen = boom.length();
    int matchcount = 0;
    stack<pair<char, int> > st;
    char answer[1000001];

    for(int i = 0; i < strlen; i++){
        if(str[i] == boom[matchcount]){
            matchcount++;
        }else if(str[i] == boom[0]){
            matchcount = 1;
        }else{
            matchcount = 0;
        }
        st.push(make_pair(str[i], matchcount));
        if(matchcount == boomlen){
            for(int i = 0; i < boomlen; i++){
                st.pop();
            }
            if(!st.empty()){
                matchcount = st.top().second;
            }else{
                matchcount = 0;
            }
        }
    }

    int stack_size = st.size();

    if(stack_size == 0){
        cout<<"FRULA";
        return 0;
    }

    for(int i = stack_size-1; i >= 0; i--){
        answer[i] = st.top().first;
        st.pop();
    }

    cout<<answer<<"\n";

    return 0;
}