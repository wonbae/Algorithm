#include<bits/stdc++.h>
using namespace std;
#define SIZE 51

typedef pair<int, int> pii;

vector<pii> home;
vector<pii> chicken;
vector<int> v;
int N, M;   //N <= 50, M <= 13
int ans = 1e9;

int getAbs(int a){
    return a > 0 ? a : -a;
}

int getMin(int a, int b){
    if(a == b) return a;
    return a > b ? b : a;
}

int getDist(){
    int sum = 0;

    for(int i = 0; i < home.size(); i++){
        int dist = 987654321;
        for(int j = 0; j < v.size(); j++){
            int ncr_v = v[j];
            dist = getMin(dist, getAbs(home[i].first - chicken[ncr_v].first) + getAbs(home[i].second - chicken[ncr_v].second));
        }
        sum += dist;
    }

    return sum;
}

void nCr(int idx, int cnt){
    if(cnt == M){
        ans = getMin(ans, getDist());
        return;
    }

    for(int i = idx; i < chicken.size(); i++){
        v.push_back(i);
        nCr(i + 1, cnt + 1);
        v.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin>>N>>M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int input;
            cin>>input;
            if(input == 1) home.push_back(make_pair(i, j));    //home
            if(input == 2) chicken.push_back(make_pair(i, j));    //chicken
        }
    }
    
    nCr(0, 0);

    cout<<ans<<"\n";

    return 0;
}