#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX
typedef pair<int, int> pii;

vector<pii> v;
map<pii, int> ma;

long long distance(pii a, pii b){
    int x = a.first;
    int y = a.second;
    int x2 = b.first;
    int y2 = b.second;

    return (long long)(x2 - x) * (x2 - x) + (long long)(y2 - y) * (y2 - y);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        int x, y;
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end());

    ma[make_pair(v[0].second, v[0].first)] = 0;
    ma[make_pair(v[1].second, v[1].first)] = 0;
    long long answer = distance(v[0], v[1]);

    int pos = 0;
    for(int i = 2; i < n; i++){
        while(pos < i){
            int dx = v[i].first - v[pos].first;

            if(pow(dx,2) <= answer) break;

            ma.erase(make_pair(v[pos].second, v[pos].first));
            pos++;
        }

        long long dis = sqrt(answer);

        auto left = ma.lower_bound(make_pair(v[i].second - dis, -INF));
        auto right = ma.upper_bound(make_pair(v[i].second + dis, INF));

        for(auto l = left; l != right; l++){
            answer = min(answer, distance(make_pair(l->first.second, l->first.first), v[i]));
        }

        ma[make_pair(v[i].second, v[i].first)] = 0;
    }

    cout<<answer<<"\n";


    return 0;
}