#include<iostream>
#include<queue>
using namespace std;

int Q[100], front = -1, back = -1, ch[10];
vector<int> map[10];

int main(){
    freopen("input.txt", "rt", stdin);
    int i, a, b, x;
    for(i = 1; i <= 6; i++){
        cin>>a>>b;
        map[a].push_back(b);
        map[b].push_back(a);
    }    
    Q[++back] = 1;
    ch[1] = 1;
    while(front<back){
        x=Q[++front];
        cout<<x;
        for(i = 0; i < map[x].size(); i++){
            if(ch[map[x][i]==0]){
                Q[++back]=map[x][i];
            }
        }
    }
    return 0;
}


// #include<iostream>
// #include<queue>
// using namespace std;

// int main(){
//     freopen("input.txt", "rt", stdin);
//     int ch[10] = {0,}, a, b;
//     queue<int> q;

//     for(int i = 0; i < 6; i++){
//         cin>>a>>b;
//         if(ch[a] == 0){
//             q.push(a);
//             ch[a] = 1;
//         }
//         if(ch[b] == 0){
//             q.push(b);
//             ch[b] = 1;
//         }
//     }

//     while(!q.empty()){
//         cout<<q.front()<<" ";
//         q.pop();
//     }
//     return 0;
// }