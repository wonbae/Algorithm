#include<iostream>
#include<cmath>
#include<vector>
#include<limits.h>
using namespace std;
typedef long long ll;

vector<ll> arr;
vector<ll> seg;

ll min_index(ll a, ll b){
    if(a == INT_MAX) return b;
    if(b == INT_MAX) return a;
    return arr[a] <= arr[b] ? a : b;
}


ll init(int node, int start, int end){
    if(start == end)
        return seg[node] = start;
    int mid = start + (end - start) / 2;
    return seg[node] = min_index(init(node*2, start, mid), init(node*2+1, mid+1, end));
}


ll update(int index, int value, int node, int start, int end){
    if(index < start || end < index || start == end)
        return seg[node];
    int mid = start + (end - start) / 2;
    return seg[node] = min_index(update(index, value, node*2, start, mid), update(index, value, node*2+1, mid+1, end));
}


ll query(int left, int right, int node, int start, int end){
    if(right < start || end < left)
        return INT_MAX;
    if(left <= start && end <= right)
        return seg[node];
    int mid = start + (end - start) / 2;
    return min_index(query(left, right, node*2, start, mid), query(left, right, node*2+1, mid+1, end));
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n,m;
    cin>>n;
    arr.resize(n);
    int treeSize = (1<<((int(ceil(log2(n))))+1));
    seg.resize(treeSize);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    init(1, 0, n-1);

    cin>>m;
    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        if(a == 2){
            cout<<query(b-1, c-1, 1, 0, n-1)+1<<"\n";
        }else{
            arr[b-1] = c;
            update(b-1, c, 1, 0, n-1);
        }
    }

    return 0;
}