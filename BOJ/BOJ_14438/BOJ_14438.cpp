#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<limits.h>

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
    return seg[node] = min(lt, rt);
}

long long update(int index, int value, int node, int start, int end){
    if(index < start || end < index)
        return seg[node];
    if(start == end)
        return seg[node] = value;
    int mid = start + (end - start) / 2;
    long long lt = update(index, value, node*2, start, mid);
    long long rt = update(index, value, node*2+1, mid+1, end);
    return seg[node] = min(lt, rt);
}


long long query(int left, int right, int node, int start, int end){
    if(right < start || end < left)
        return INT_MAX;
    if(left <= start && end <= right){
        return seg[node];
    }
    int mid = start + (end - start) / 2;
    long long lt = query(left, right, node*2, start, mid);
    long long rt = query(left, right, node*2+1, mid+1, end);
    return min(lt, rt);
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m;
    cin>>n;

    int treesize = (1<<((int(ceil(log2(n))))+1));
    seg.resize(treesize);
    arr.resize(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    init(1, 0, n-1);

    cin>>m;
    for(int i = 0; i < m; i++){
        long long a, b, c;
        cin>>a>>b>>c;
        if(a == 1){
            update(b-1, c, 1, 0, n-1);
        }else{
            cout<<query(b-1, c-1, 1, 0, n-1)<<"\n";
        }
    }

    return 0;
}