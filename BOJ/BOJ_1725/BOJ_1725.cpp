#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;

vector<ll> seg;
vector<ll> arr;
int n, ans=0;


ll mini(ll a, ll b){
    if(a == -1) return b;
    if(b == -1) return a;
    return arr[a] <= arr[b] ? a : b;
}


ll init(int node, int start, int end){
    if(start == end)
        return seg[node] = start;

    int mid = start + (end - start) / 2;
    ll lt = init(node*2, start, mid);
    ll rt = init(node*2+1, mid+1, end);
    return seg[node] = mini(lt, rt);
}


ll query(int left, int right, int node, int start, int end){
    if(right < start || end < left)
        return -1;
    if(left <= start && end <= right)
        return seg[node];
    
    int mid = start + (end - start) / 2;
    return mini(query(left, right, node*2, start, mid), query(left, right, node*2+1, mid+1, end));
}


int devide(int start, int end){
    int mid = query(start, end, 1, 0, n-1);

    int area = arr[mid] * (end - start + 1);
    // cout<<"start : "<<start<<", end : "<<end<<", mid : "<<mid<<", area : "<<area<<"\n";
    ans = max(ans, area);
    
    if(start <= mid - 1){
        ans = max(devide(start, mid-1), ans);
    }
    if(mid + 1 <= end){
        ans = max(devide(mid+1, end), ans);
    }

    return ans;
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin>>n;

    int h = int(ceil(log2(n)));
    int treeSize = (1<<(h+1));
    seg.resize(treeSize);
    arr.resize(n);

    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    init(1, 0, n-1);
    cout<<devide(0, n-1)<<"\n";

    return 0;
}