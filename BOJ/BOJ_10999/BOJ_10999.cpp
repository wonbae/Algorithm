#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

vector<ll> arr;
vector<ll> seg;
vector<ll> lazy;


ll init(int node, int start, int end){
    if(start == end){
        return seg[node] = arr[start];
    }

    int mid = start + (end - start) / 2;
    return seg[node] = init(node*2, start, mid) 
                        + init(node*2+1, mid+1, end);
}


void update_lazy(int node, int start, int end){
    if(lazy[node] != 0){
        seg[node] += ((ll)(end - start + 1) * lazy[node]);

        if(start != end){
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }

        lazy[node] = 0;
    }
}


void update(int left, int right, ll value, int node, int start, int end){
    update_lazy(node, start, end);

    if(right < start || end < left)
        return ;

    if(left <= start && end <= right){
        seg[node] += (ll)(end - start + 1) * value;
        if(start != end){
            lazy[node*2] += value;
            lazy[node*2+1] += value;
        }
        return ;
    }

    int mid = start + (end - start) / 2;
    update(left, right, value, node*2, start, mid);
    update(left, right, value, node*2+1, mid+1, end);
    seg[node] = seg[node*2] + seg[node*2+1];
}


ll query(int left, int right, int node, int start, int end){
    update_lazy(node, start, end);

    if(right < start || end < left)
        return 0;
    if(left <= start && end <= right)
        return seg[node];

    int mid = start + (end - start) / 2;
    return query(left, right, node*2, start, mid) + 
            query(left, right, node*2+1, mid+1, end);
}


int main(){
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    
    int n, m, k;
    cin>>n>>m>>k;

    int t = int(ceil(log2(n)));
    int treeSize = (1<<(t+1));

    seg.resize(treeSize);
    lazy.resize(treeSize);
    arr.resize(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    init(1, 0, n-1);

    for(int i = 0; i < m+k; i++){
        int a, b, c;
        ll d;

        cin>>a;
        if(a == 1){
            cin>>b>>c>>d;
            update(b-1, c-1, d, 1, 0, n-1);
        }else{
            cin>>b>>c;
            cout<<query(b-1, c-1, 1, 0, n-1)<<"\n";
        }
    }
    return 0;
}