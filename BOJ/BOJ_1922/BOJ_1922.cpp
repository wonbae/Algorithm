//// Prim - 60ms
// #include <iostream>
// #include <queue>
// #include <vector>
// using namespace std;

// int ch[1001];

// struct edge{
//     int e;
//     int val;
//     edge(int a, int b){
//         e = a;
//         val = b;
//     }
//     bool operator<(const edge& w) const {
//         return val > w.val;
//     }
// };

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, m, a, b, c, cost = 0;
//     cin>>n>>m;
//     priority_queue<edge> pq;
//     vector<pair<int, int> > map[1001];
    

//     for(int i = 0; i < m; i++){
//         cin>>a>>b>>c;
//         map[a].push_back(make_pair(b, c));
//         map[b].push_back(make_pair(a, c));
//     }

//     pq.push(edge(1, 0));
//     while(!pq.empty()){
//         int ed = pq.top().e;
//         int val = pq.top().val;
//         pq.pop();

//         if(ch[ed] == 0){
//             ch[ed] = 1;
//             cost += val;
//             for(int i = 0; i < map[ed].size(); i++){
//                 pq.push(edge(map[ed][i].first, map[ed][i].second));
//             }
//         }
//     }
//     cout<<cost<<"\n";

//     return 0;
// }

//Kruskal - 32ms
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int unf[1001];

struct info{
    int s;
    int e;
    int val;
    info(int a, int b, int c){
        s = a;
        e = b;
        val = c;
    }
    bool operator<(const info& w) const {
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
    return ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b, c, cost = 0;
    cin>>n>>m;
    vector<info> v;

    for(int i = 1; i <= n; i++){
        unf[i] = i;
    }

    for(int i = 0; i < m; i++){
        cin>>a>>b>>c;
        v.push_back(info(a, b, c));
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < m; i++){
        int tmp = v[i].s;
        int tmp2 = v[i].e;
        if(find(tmp) != find(tmp2)){
            cost += v[i].val;
            Union(tmp, tmp2);
        }
    }
    cout<<cost<<"\n";
}