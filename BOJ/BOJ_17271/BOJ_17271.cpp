#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int find_x(int p, int q, int r, int y){
    return (r - q*y)/p;
}

int find_y(int p, int q, int r, int x){
    return (r-p*x)/q;
}

int udist(pair<int, int> a, pair<int, int> b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

float pita(pair<int, int> a, pair<int, int> b){
    return sqrt(pow(abs(a.first - b.first),2) + pow(abs(a.second - b.second),2));
}

int main(){
    int ax, ay, bx, by;
    float p, q, r;
    cin>>ax>>ay>>bx>>by>>p>>q>>r;
    vector<pair<int, int> > v;
    
    int st = min(by, ay);
    int end = max(by, ay);
    int st2 = min(ax, bx);
    int end2 = max(ax, bx);

    for(int i = st; i <= end; i++){
        for(int j = st2; j <= end2; j++){
            if((p*i + q*j) == r){
                v.push_back(make_pair(i, j));
                cout<<"sival";
            }
        }
    }

    float ans = 0;

    ans = udist(make_pair(bx,by), v[0]) + udist(make_pair(ax,ay), v[1]) + pita(v[0], v[1]);
    cout<<ans;

    return 0;
}