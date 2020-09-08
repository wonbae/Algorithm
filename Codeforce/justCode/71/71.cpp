#include<iostream>
#include<queue>

using namespace std;

int ch[10001], d[3] = {-1, 1, 5};
int main(){
    freopen("input.txt", "rt", stdin);
    int s, e;
    queue<int> q;
    cin>>s>>e;

    q.push(s);
    ch[s] = 1;

    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i = 0; i < 3; i++){
            int nx = x + d[i];
            if(nx == e){
                cout<<ch[x]<<"\n";
                return 0;
            }
            if(ch[nx] == 0){
                ch[nx] = ch[x] + 1;
                q.push(nx);
            }
        }
    }
    return 0;
}