#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int unf[100001];

struct planet{
    int x;
    int y;
    int z;
    int num;
    planet(int a,int b, int c){
        x = a;
        y = b;
        z = c;
    }
};

struct info{
    int u;
    int v;
    int w;
    info(int a, int b, int c){
        u = a;
        v = b;
        w = c;
    }
    bool operator<(const info& q) const{
        return w < q.w;
    }
};

bool ascx(planet a, planet b){
    return a.x < b.x;
}
bool ascy(planet a, planet b){
    return a.y < b.y;
}
bool ascz(planet a, planet b){
    return a.z < b.z;
}

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
    int n;
    int x,y,z, cost = 0;
    cin>>n;
    vector<planet> p;
    vector<info> ans;

    for(int i = 0; i < n; i++){
        cin>>x>>y>>z;
        p.push_back(planet(x, y, z));
        p[i].num = i;
        unf[i + 1] = i + 1;
    }

    sort(p.begin(), p.end(), ascx);
    for(int i = 0; i < n - 1; i++){
        ans.push_back(info(p[i].num, p[i + 1].num, abs(p[i].x - p[i+1].x)));
    }
    sort(p.begin(), p.end(), ascy);
    for(int i = 0; i < n - 1; i++){
        ans.push_back(info(p[i].num, p[i + 1].num, abs(p[i].y - p[i+1].y)));
    }
    sort(p.begin(), p.end(), ascz);
    for(int i = 0; i < n - 1; i++){
        ans.push_back(info(p[i].num, p[i + 1].num, abs(p[i].z - p[i+1].z)));
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
        if(find(ans[i].u) != find(ans[i].v)){
            Union(ans[i].u, ans[i].v);
            cost += ans[i].w;
        }
    }

    cout<<cost<<"\n";

    return 0;
}