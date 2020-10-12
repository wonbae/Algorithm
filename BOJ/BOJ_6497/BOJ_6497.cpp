// Kruskal - 212ms
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int unf[200001];

struct edge{
    int ss;
    int ee;
    int val;
    edge(int a, int b, int c){
        ss = a;
        ee = b;
        val = c;
    }
    bool operator<(const edge& w) const{
        return val < w.val;
    }
};

int find(int v){
    if(unf[v] == v) return v;
    return unf[v] = find(unf[v]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);
    if(a != b) unf[a] = b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, x, y, z;

    while(1){
        cin>>n>>m;
        if(n == 0 && m == 0) break;

        for(int i = 0; i <= n; i++){
            unf[i] = i;
        }

        vector<edge> v;
        int sum = 0;

        for(int i = 0; i < m; i++){
            cin>>x>>y>>z;
            sum += z;
            v.push_back(edge(x, y, z));
        }

        sort(v.begin(), v.end());

        int cost = 0;
        for(int i = 0; i < v.size(); i++){
            if(find(v[i].ss) != find(v[i].ee)){
                cost += v[i].val;
                Union(v[i].ss, v[i].ee);
            }
        }

        cout<<sum - cost<<"\n";
    }

    return 0;
}

// //Prim - 404ms
// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;

// struct edge{
//     int ee;
//     int val;
//     edge(int a, int b){
//         ee = a;
//         val = b;
//     }
//     bool operator<(const edge& w) const{
//         return val > w.val;
//     }
// };

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     int n, m, x, y, z;

//     while(1){
//         cin>>n>>m;
//         if(n == 0 && m == 0) return 0;

//         vector<pair<int, int> > v[200001];
//         priority_queue<edge> pq;
//         int ch[200001] = {0,};
//         int sum = 0;

//         for(int i = 0; i < m; i++){
//             cin>>x>>y>>z;
//             sum += z;
//             v[x].push_back(make_pair(y, z));
//             v[y].push_back(make_pair(x, z));
//         }

//         int cost = 0;
//         pq.push(edge(0, 0));
//         while(!pq.empty()){
//             int now = pq.top().ee;
//             int value = pq.top().val;
//             pq.pop();

//             if(ch[now] == 0){
//                 cost += value;
//                 ch[now] = 1;
//                 for(int i = 0; i < v[now].size(); i++){
//                     pq.push(edge(v[now][i].first, v[now][i].second));
//                 }
//             }
//         }
//         cout<<sum - cost<<"\n";
//     }
//     return 0;
// }