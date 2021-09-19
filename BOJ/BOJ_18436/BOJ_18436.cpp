#include<iostream>
#include<cmath>
#include<limits.h>
#include<vector>
using namespace std;
typedef long long ll;

vector<ll> arr;
vector<ll> odd_seg;
vector<ll> even_seg;

ll odd_init(int node, int start, int end){  //홀수
    if(start == end)
        return odd_seg[node] = (arr[start] != 0 ? 1 : 0);
    int mid = start + (end - start) / 2;
    return odd_seg[node] = odd_init(node*2, start, mid) + 
                            odd_init(node*2+1, mid+1, end);
}


ll even_init(int node, int start, int end){     //짝수
    if(start == end)
        return even_seg[node] = (arr[start] == 0 ? 1 : 0);

    int mid = start + (end - start) / 2;
    return even_seg[node] = even_init(node*2, start, mid) + 
                            even_init(node*2+1, mid+1, end);
}


ll odd_update(int index, int value, int node, int start, int end){
    if(index < start || end < index){
        return odd_seg[node];
    }
    if(start==end)
        if(value % 2 == 1) {
            return odd_seg[node] = 1;
        }else{
            return odd_seg[node] = 0;
        }

    int mid = start + (end - start) / 2;
    ll lt = odd_update(index, value, node*2, start, mid);
    ll rt = odd_update(index, value, node*2+1, mid+1, end);
    
    return odd_seg[node] = lt+rt;
}


ll even_update(int index, int value, int node, int start, int end){
    if(index < start || end < index){
            return even_seg[node];
    }
    if(start==end)
        if(value % 2 == 0) {
            return even_seg[node] = 1;
        }else{
            return even_seg[node] = 0;
        }

    int mid = start + (end - start) / 2;
    ll lt = even_update(index, value, node*2, start, mid);
    ll rt = even_update(index, value, node*2+1, mid+1, end);
        
    return even_seg[node] = lt+rt;
}


ll query(int left, int right, int node, int start, int end, int evenodd){
    if(right < start || end < left)
        return 0;
    if(left <= start && end <= right){
        return (evenodd == 0 ? even_seg[node] : odd_seg[node]);
    }

    int mid = start + (end - start) / 2;
    ll lt = query(left, right, node*2, start, mid, evenodd);
    ll rt = query(left, right, node*2+1, mid+1, end, evenodd);
    return lt+rt;
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    int n,m;
    cin>>n;

    arr.resize(n);
    int treeSize = (1<<((int(ceil(log2(n))))+1));
    odd_seg.resize(treeSize);
    even_seg.resize(treeSize);

    for(int i = 0, num; i < n; i++){
        cin>>num;
        if(num%2 == 0){
            arr[i] = 0;
        }else{
            arr[i] = 1;
        }
    }

    odd_init(1, 0, n-1);
    even_init(1, 0, n-1);

    cin>>m;

    while(m--){
        int a, b, c;
        cin>>a>>b>>c;
        if(a == 1){
            odd_update(b-1, c, 1, 0, n-1);
            even_update(b-1, c, 1, 0, n-1);
        }else if(a == 2){
            cout<<query(b-1, c-1, 1, 0, n-1, 0)<<"\n";
        }else{
            cout<<query(b-1, c-1, 1, 0, n-1, 1)<<"\n";
        }
    }

    return 0;
}