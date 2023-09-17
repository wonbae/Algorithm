#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
typedef long long ll;

class lazyPropateSegmentTree{
public:
    lazyPropateSegmentTree(vector<ll>& arr){
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
        build(arr, 0, 0, n-1);
    }

    void update(ll ql, ll qr, ll delta){
        updateUtill(0, 0, n - 1, ql, qr, delta);
    }

    ll query(ll index){
        return queryUtill(0, 0, n - 1, index);
    }

private:
    vector<ll> tree, lazy;
    ll n;

    void build(vector<ll>& arr, ll node, ll left, ll right){
        if(left == right){
            tree[node] = arr[left];
        }else{
            ll mid = left + (right - left) / 2;
            build(arr, 2 * node + 1, left, mid);
            build(arr, 2 * node + 2, mid + 1, right);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void propagate(ll node, ll left, ll right){
        if(lazy[node] != 0){
            tree[node] += lazy[node] * (right - left + 1);

            if(left != right){
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    void updateUtill(ll node, ll left, ll right, ll ql, ll qr, ll delta){
        propagate(node, left, right);

        if(qr < left || right < ql) return;

        if(ql <= left && right <= qr){
            tree[node] += delta * (right - left + 1);

            if(left != right){
                lazy[2 * node + 1] += delta;
                lazy[2 * node + 2] += delta;
            }
            return;
        }

        ll mid = left + (right - left) / 2;
        updateUtill(2 * node + 1, left, mid, ql, qr, delta);
        updateUtill(2 * node + 2, mid + 1, right, ql, qr, delta);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    ll queryUtill(ll node, ll left, ll right, ll index){
        propagate(node, left, right);

        if(index < left || right < index) return 0;

        if(index <= left && right <= index){
            return tree[node];
        }

        ll mid = left + (right - left) / 2;
        ll left_sum = queryUtill(2 * node + 1, left, mid, index);
        ll right_sum = queryUtill(2 * node + 2, mid + 1, right, index);
        return left_sum + right_sum;
    }
};

int main(){
    fastio;
    ll n, m;
    cin>>n;

    vector<ll> v(n+1);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    lazyPropateSegmentTree segtree(v);

    cin>>m;

    for(int i = 0; i < m; i++){
        ll oper;
        cin>>oper;

        if(oper == 1){
            ll left, right, k;
            cin>>left>>right>>k;
            segtree.update(left - 1, right - 1, k);
        }else{
            ll x;
            cin>>x;
            cout<<segtree.query(x - 1)<<"\n";
        }
    }


    return 0;
}