#include<bits/stdc++.h>
using namespace std;

bool visited[10000];

int D(int num) {
    return (2 * num) % 10000;
}

int S(int num) {
    if (num - 1 < 0) return 9999;
    return num - 1;
}

int L(int num) {
    return (num % 1000) * 10 + (num / 1000);
}

int R(int num) {
    return (num / 10) + ((num % 10) * 1000);
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    
    int t;
    cin>>t;

    while(t--){
        int a, b;
        string orders = "";

        cin>>a>>b;

        queue<pair<int, string> > q; 
        
        memset(visited, false, sizeof(visited));

        q.push({a, ""});
        visited[a] = true;

        while(!q.empty()){
            int now = q.front().first;
            string ops = q.front().second;
            q.pop();

            // cout<<now<<"\t"<<ops<<"\n";


            if(now == b){
                cout<<ops<<"\n";
                break;
            }

            
            int nextD = D(now);
            int nextS = S(now);
            int nextL = L(now);
            int nextR = R(now);

            if(!visited[nextD]){
                q.push({nextD, ops+'D'});
                visited[nextD] = true;
            }
            if(!visited[nextS]){
                q.push({nextS, ops+'S'});
                visited[nextS] = true;
            }
            if(!visited[nextL]){
                q.push({nextL, ops+'L'});
                visited[nextL] = true;
            }
            if(!visited[nextR]){
                q.push({nextR, ops+'R'});
                visited[nextR] = true;
            }
            
        }

        // cout<<orders<<"\n";
    }

    return 0;
}