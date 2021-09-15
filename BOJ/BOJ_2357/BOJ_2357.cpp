#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<limits.h>
using namespace std;

vector<long long> MinsegTree;
vector<long long> MaxsegTree;

long long init(vector<int> &arr, int node, int start, int end, bool flag){
    if(start == end){
        if(flag){
            return MaxsegTree[node] = arr[start];
        }else{
            return MinsegTree[node] = arr[start];
        }
    }

    int mid = start + (start - end) / 2;

    if(flag){
        return MaxsegTree[node] = max(init(arr, node*2, start, mid, true), init(arr, node*2+1, mid+1, end, true));
    }
    return MinsegTree[node] = min(init(arr, node*2, start, mid, false), init(arr, node*2+1, mid+1, end, false));
    
}


long long MinMaxQuery(int left, int right, int nodeLeft, int nodeRight, int node, bool flag){
    if(right < nodeLeft || nodeRight < left){
        return (flag == 0 ? INT_MAX : INT_MIN);
    }
    if(left <= nodeLeft && nodeRight <= right)
        return (flag == 0 ? MinsegTree[node] : MaxsegTree[node]);
    
    int mid = nodeLeft + (nodeRight - nodeLeft) / 2;
    
    long long lt = MinMaxQuery(left, right, nodeLeft, mid, node*2, flag);
    long long rt = MinMaxQuery(left, right, mid+1, nodeRight, node*2+1, flag);
    return (flag == 0 ? min(lt, rt) : max(lt, rt));
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    
    int n, m;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int h = int(ceil(log2(n)));
    int treesize = (1<<(h+1));
    MinsegTree.resize(treesize);
    MaxsegTree.resize(treesize);

    init(arr, 1, 0, n-1, 0);
    init(arr, 1, 0, n-1, 1);

    for(int i = 0, a, b; i < m; i++){
        cin>>a>>b;
        cout<<MinMaxQuery(a-1, b-1, 0, n-1, 1, 0)<<" "<<MinMaxQuery(a-1, b-1, 0, n-1, 1, 1)<<"\n";
    }
    return 0;
}