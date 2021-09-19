#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;

vector<ll> seg;
vector<ll> arr;

ll update(int index, int value, int node, int start, int end){
    if(index < start || end < index)
        return seg[node];
    if(start == end)
        return seg[node] += value;
    int mid = start + (end - start) / 2;
    return seg[node] = update(index, value, node*2, start, mid) +
            update(index, value, node*2+1, mid+1, end);
}


ll query(int left, int right, int node, int start, int end){
    if(right < start || end < left)
        return 0;
    if(left <= start && end <= right)
        return seg[node];
    int mid = start + (end - start) / 2;
    return query(left, right, node*2, start, mid) + 
            query(left, right, node*2+1, mid+1, end);
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, q;
    cin>>n>>q;

    int treeSize = (1<<((int(ceil(log2(n))))+1));
    seg.resize(treeSize, 0);
    arr.resize(n, 0);

    while(q--){
        int a, b;
        ll c;

        cin>>a>>b>>c;
        if(a == 1){
            update(b-1, c, 1, 0, n-1);
        }else{
            cout<<query(b-1, c-1, 1, 0, n-1)<<"\n";
        }
    }

    return 0;
}