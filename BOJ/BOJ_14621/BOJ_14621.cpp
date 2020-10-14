#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int unf[1001];

struct school{
    int u,v,w;
    school(int a, int b, int c){
        u = a;
        v = b;
        w = c;
    }
    bool operator<(const school& di) const{
        return w < di.w;
    }
};

int find(int v){
    if(v == unf[v]) return v;
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
    int n, m, u, v, d, cost = 0;
    char mw;
    cin>>n>>m;
    vector<bool> sex(n + 1);
    vector<school> sh;

    for(int i = 1; i <= n; i++){
        unf[i] = i;
        cin>>mw;
        if(mw == 'M'){
            sex[i] = true;
        }else{
            sex[i] = false;
        }
        
    }
    for(int i = 0; i < m; i++){
        cin>>u>>v>>d;
        sh.push_back(school(u, v, d));
    }

    sort(sh.begin(), sh.end());
    int cnt = 0;
    for(int i = 0; i < sh.size(); i++){
        if(sex[sh[i].u] == sex[sh[i].v]) continue;
        else{
            if(find(sh[i].u) != find(sh[i].v)){
                cnt++;
                cost += sh[i].w;
                Union(sh[i].u, sh[i].v);
            }
        }
    }
    if(cnt == n - 1) cout<<cost<<"\n";
    else cout<<-1<<"\n";
    return 0;
}