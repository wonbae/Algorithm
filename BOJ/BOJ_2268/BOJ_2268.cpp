#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;

vector<ll> seg;
vector<ll> arr;

long long init(int node, int start, int end){
    if(start == end){
        return seg[node] = arr[start];
    }
    int mid = start + (end - start) / 2;

    return seg[node] = init(node*2, start, mid) + 
                        init(node*2+1, mid+1, end);
}


long long update(int index, int value, int node, int start, int end){
    if(index < start || end < index)
        return seg[node];
    if(start == end){
        return seg[node] = value;
    }
    int mid = start + (end - start) / 2;

    return seg[node] = update(index, value, node*2, start, mid) + 
                        update(index, value, node*2+1, mid+1, end);
}


long long query(int left, int right, int node, int start, int end){
    if(right < start || end < left)
        return 0;
    if(left <= start && end <= right)
        return seg[node];
    int mid = start + (end - start) / 2;

    return query(left, right, node*2, start, mid) + 
            query(left, right, node*2+1, mid+1, end);
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    arr.resize(n, 0);
    int treeSize = (1<<((int(ceil(log2(n))))+1));
    seg.resize(treeSize);

    init(1, 0, n-1);

    for(int i = 0; i < m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(a == 0){
            if(b < c)
                cout<<query(b-1, c-1, 1, 0, n-1)<<"\n";
            else
                cout<<query(c-1, b-1, 1, 0, n-1)<<"\n";
        }else{
            update(b-1, c, 1, 0, n-1);
        }
    }


    return 0;
}