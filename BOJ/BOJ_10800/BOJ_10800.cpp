#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct info{
    int idx, color, weight;
    bool operator<(const info &w){
        return weight<w.weight;
    }
};

// bool cmp(info &a, info &b){
//     if(a.weight == b.weight) return a.color < b.color;
//     return a.weight < b.weight;
// }

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n;
    cin>>n;
    vector<info> v(n);
    vector<int> colorSum(n);
    vector<int> ans(n);

    for(int i = 0; i < n; i++){
        cin>>v[i].color>>v[i].weight;
        v[i].idx = i;
    }

    sort(v.begin(), v.end());

    int prefixSum = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        while(v[i].weight > v[j].weight){
            // cout<<"["<<i<<"] : "<<v[i].weight<<", "<<v[j].weight<<"\n";
            prefixSum += v[j].weight;
            colorSum[v[j].color] += v[j].weight;
            j++;
        }
        
        ans[v[i].idx] = prefixSum - colorSum[v[i].color];
    }

    for(int i = 0; i < n; i++){
        cout<<ans[i]<<"\n";
    }

    return 0;
}