#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<long long> segTree;

long long init(vector<long long> &arr, int node, int start, int end){
    if(start == end){
        return segTree[node] = arr[start];
    }

    int mid = (start + end)/2;

    return segTree[node] = init(arr, node*2, start, mid) + init(arr, node*2+1, mid+1, end);
}


long long sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;

    if(left <= start && end <= right) return segTree[node];

    int mid = (start + end)/2;

    return sum(node*2, start, mid, left, right) + sum(node*2+1, mid+1, end, left, right);
}


void update(int node, int start, int end, int index, long long diff){
    if(index < start || index > end) return ;

    segTree[node] += diff;

    if(start != end){
        int mid = (start + end) / 2;
        update(node*2, start, mid, index, diff);
        update(node*2+1, mid+1, end, index, diff);
    }
}

int main(){
    ios_base::sync_with_stdio(0),cin.tie(NULL);

    int n, m, k;
    int a;
    long long b, c;
    cin>>n>>m>>k;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int h = (int)ceil(log2(n));
    int treeSize = (1<<(h+1));

    segTree.resize(treeSize);

    init(arr, 1, 0, n-1);

    for(int i = 0; i < m+k; i++){
        cin>>a>>b>>c;
        if(a == 1){ //update
            long long diff = c - arr[b-1];
            arr[b-1] = c;
            update(1, 0, n-1, b-1, diff);
        }
        else if(a == 2){   //sum
            cout<<sum(1, 0, n-1, b-1, c-1)<<"\n";
        }
    }

    return 0;
}