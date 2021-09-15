#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define MOD 1000000007;

vector<long long> segTree;

int abs(int a){
    return a < 0 ? (-1)*a : a;
}

long long multi(long long a, long long b){
    return (a * b) % MOD;
}


long long init(vector<int> &arr, int node, int start, int end){
    if(start == end){
        return segTree[node] = arr[start];
    }

    long long mid = (start + (end - start) / 2);
    return segTree[node] = multi(init(arr, node*2, start, mid), init(arr, node*2+1, mid+1, end));

}


long long update(int index, int newValue, int node, int nodeLeft, int nodeRight){
    if(index < nodeLeft || nodeRight < index)
        return segTree[node];

    if(nodeLeft == nodeRight)
        return segTree[node] = newValue;

    long long mid = nodeLeft + (nodeRight - nodeLeft) / 2;
    return segTree[node] = multi(update(index, newValue, node*2, nodeLeft, mid), update(index, newValue, node*2+1, mid+1, nodeRight));

}


long long multi_query(int node, int nodeLeft, int nodeRight, int left, int right){
    if(right < nodeLeft || nodeRight < left)
        return 1;

    if(left <= nodeLeft && nodeRight <= right)
        return segTree[node];

    long long mid = nodeLeft + (nodeRight - nodeLeft) / 2;
    return multi(multi_query(node*2, nodeLeft, mid, left, right), multi_query(node*2+1, mid+1, nodeRight, left, right));
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;
    vector<int> arr(n);

    int t = int(ceil(log2(n)));
    int treeSize = (1<<(t+1));
    segTree.resize(treeSize);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int a, b, c;

    init(arr, 1, 0, n-1);

    for(int i = 0; i < m+k; i++){
        cin>>a>>b>>c;
        if(a == 1){
            update(b-1, c, 1, 0, n-1);
        }else if(a == 2){
            cout<<multi_query(1, 0, n-1, b-1, c-1)<<"\n";
        }
    }

    return 0;
}