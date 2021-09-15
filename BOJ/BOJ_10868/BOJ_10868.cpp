#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

vector<long long> segTree;

int min(long long a, long long b){
    return a > b ? b : a;
}


long long init(vector<long long> &arr, int node, int start, int end){
    if(start == end){
        segTree[node] = arr[start];
        return segTree[node];
    }

    int mid = start + (end - start)/2;

    return segTree[node] = min(init(arr, node*2, start, mid), init(arr, node*2+1, mid+1, end));
}


long long RangeMinimumQuery(int node, int nodeLeft, int nodeRight, int left, int right){
    if(right < nodeLeft || nodeRight < left) return INT_MAX;

    if(left <= nodeLeft && nodeRight <= right) return segTree[node];
    
    int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
    return min(RangeMinimumQuery(node*2, nodeLeft, mid, left, right), 
                RangeMinimumQuery(node*2+1, mid+1, nodeRight, left, right));
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<long long> arr(n+1);

    int t = int(ceil(log2(n)));
    int treeSize = (1<<(t+1));

    segTree.resize(treeSize);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    init(arr, 1, 0, n-1);

    long long l,r;
    for(int i = 0; i < m; i++){
        cin>>l>>r;
        cout<<RangeMinimumQuery(1, 0, n-1, l-1, r-1)<<"\n";
    }
    return 0;
}