#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
typedef long long ll;

int main(){
    fastio;
    int n;
    cin>>n;

    queue<int> q;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    while(q.size() != 1){
        q.pop();
        int num = q.front();
        q.pop();
        q.push(num);
    }    
    cout<<q.front();
    return 0;
}