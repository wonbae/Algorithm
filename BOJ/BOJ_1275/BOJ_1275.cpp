#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<cmath>
using namespace std;

vector<long long> seg;
vector<long long> arr;

long long init(int node, int start, int end){
    if(start == end){
        return seg[node] = arr[start];
    }
    int mid = start + (end - start) / 2;
    long long lt = init(node*2, start, mid);
    long long rt = init(node*2+1, mid+1, end);
    return seg[node] = lt + rt;
}


long long query(int node, int left, int right, int start, int end){
    if(end < left || right < start)
        return 0;
    if(left <= start && end <= right)
        return seg[node];
    int mid = start + (end - start) / 2;
    return query(node*2, left, right, start, mid) +
            query(node*2+1, left, right, mid+1, end);
}

void update(int node, int index, long long value, int start, int end){
    if(index < start || end < index){
        return ;
    }

    seg[node] += value;

    if(start != end){
        int mid = start + (end - start) / 2;
        update(node*2, index, value, start, mid);
        update(node*2+1, index, value, mid+1, end);
    }
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n, q;
    cin>>n>>q;

    int t = int(ceil(log2(n)));
    int treeSize = (1<<(t+1));

    seg.resize(treeSize);
    arr.resize(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    init(1, 0, n-1);

    long long a, b, c, d;
    for(int i = 0; i < q; i++){
        cin>>a>>b>>c>>d;
        if(a<b){
            cout<<query(1, a-1, b-1, 0, n-1)<<"\n";
        }else{
            cout<<query(1, b-1, a-1, 0, n-1)<<"\n";
        }

        long long diff = d - arr[c-1];
        arr[c-1] = d;

        update(1, c-1, diff, 0, n-1);
    }
    return 0;
}