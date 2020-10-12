#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;
typedef double dd;
typedef pair<dd, pair<int, int> > pii;

int unf[101];

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
    cin.tie(NULL), cout.tie(NULL);

    int n;
    dd a, b;
    cin>>n;
    vector<pair<dd, dd> > v;
    priority_queue< pii, vector<pii>, greater<pii> > pq;

    for(int i = 0; i < n; i++){
        cin>>a>>b;
        v.push_back(make_pair(a, b));
    }

    for(int i = 1; i <= n; i++){
        unf[i] = i;
    }

    for(int i = 0; i < v.size() - 1; i++){
        for(int j = i + 1; j < v.size(); j++){
            dd val = sqrt(pow((v[i].first - v[j].first), 2) + pow((v[i].second - v[j].second), 2));     
            pq.push(make_pair(val, make_pair(i, j)));
        }
    }

    int cnt = 0;
    dd cost = 0;
    while(!pq.empty()){
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        dd num = pq.top().first;
        pq.pop();

        if(find(unf[x]) != find(unf[y])){
            cost += num;
            cnt++;
            Union(x, y);
            if(cnt == n - 1) break;
        }
    }

    cout<<fixed<<setprecision(2)<<cost<<"\n";
    return 0;
}