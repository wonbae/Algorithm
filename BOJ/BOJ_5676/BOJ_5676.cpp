#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
typedef long long ll;

vector<ll> seg;
vector<int> arr;


ll init(int node, int start, int end){
    if(start == end){
        return seg[node] = arr[start];
    }

    int mid = (start + end) >> 1;
    ll lt = init(node*2, start, mid);
    ll rt = init(node*2+1, mid+1, end);

    return seg[node] = lt*rt;
}


ll update(int node, int index, int value, int start, int end){
    if(index < start || end < index)
        return seg[node];

    if(start == end)
        return seg[node] = value;

    int mid = start + (end - start) / 2;
    ll lt = update(node*2, index, value, start, mid);
    ll rt = update(node*2+1, index, value, mid+1, end);
    return seg[node] = lt*rt;
}


ll query(int node, int left, int right, int start, int end){
    if(right < start || end < left)
        return 1;
    if(left <= start && end <= right)
        return seg[node];
    int mid = start + (end - start) / 2;
    ll lt = query(node*2, left, right, start, mid);
    ll rt = query(node*2+1, left, right, mid+1, end);
    return lt*rt;
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    int n,k;
    while(cin>>n>>k){
        int treeSize = (1<<((int(ceil(log2(n))))+1));
        seg.resize(treeSize);
        arr.resize(n);

        int input;
        for(int i = 0; i < n; i++){
            cin>>input;
            if(input < 0){
                arr[i] = -1;
            }else if(input == 0){
                arr[i] = 0;
            }else{
                arr[i] = 1;
            }
        }

        init(1, 0, n-1);

        string ans = "";

        while(k--){
            char comand;
            cin>>comand;

            int i, j, v;

            if(comand == 'C'){
                cin>>i>>v;

                if(v < 0){
                    update(1, i-1, -1, 0, n-1);
                }else if(v == 0){
                    update(1, i-1, 0, 0, n-1);
                }else if(v > 0){
                    update(1, i-1, 1, 0, n-1);
                }

            }else if(comand == 'P'){
                cin>>i>>j;
                ll query_num = query(1, i-1, j-1, 0, n-1);
                if(query_num < 0){
                    ans += "-";
                }else if(query_num == 0){
                    ans += "0";
                }else if(query_num > 0){
                    ans += "+";
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}