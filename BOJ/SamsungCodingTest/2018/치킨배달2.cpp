#include <iostream>
#include <stack>
#include <stdlib.h>
#include <vector>

using namespace std;

int visited[10][10]={0,};
int map[10][10] = {0,};
stack<int> st;

void DFS(int i, int j, int n, int m){
    int dis = 0;
    for(int k = 0; k < n; k++){
        for(int l = 0; l < n; l++){
            if(map[k][l] == 2){
                dis = abs(k-i) + abs(l-j);
                cout<<"dis : "<<dis<<", ";
                if(st.empty()){
                    st.push(dis);
                }else{
                    if(st.top() > dis){
                        st.pop();
                        st.push(dis);
                    }
                }
                
            }
        }
    }
}

void input(int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin>>map[i][j];
        }
    }
}

void stackclear(){
    while(!st.empty()){
        st.pop();
    }
}

int main(){    
    ios::ios_base::sync_with_stdio(false);
    int N = 0, M = 0;
    vector<int> sum;
    int res = 0;

    cin>>N>>M;

    memset(map,0,sizeof(N));

    input(N);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] == 1){
                stackclear();
                DFS(i,j,N,M);
                sum.push_back(st.top());
                cout<<"st.top : "<<st.top()<<endl;
                st.pop();
            }
        }
    }

    // sort(sum.begin(), sum.end());

    for(int i = 0; i <= M; i++){
        cout<<"sum : "<<sum[i]<<",";
        res += sum[i];
    }

    cout<<res<<endl;

    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout<<map[i][j];
    //     }
    //     cout<<endl;
    // }

    return 0;
}