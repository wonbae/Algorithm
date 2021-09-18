#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

vector<int> seg;
vector<int> arr;


int init(int node, int start, int end){
    if(start == end){
        // cout<<"\n+++++++++++++\n";
        // cout<<"node : "<<node<<" , seg[node]: "<<seg[node]<<" === "<<arr[start]<<"\n";
        return seg[node] = arr[start];
    }

    int mid = (start + end) >> 1;
    int lt = init(node*2, start, mid);
    int rt = init(node*2+1, mid+1, end);

    return seg[node] = lt*rt;
}


int update(int node, int index, int value, int start, int end){
    if(index < start || end < index)
        return seg[node];

    if(start == end)
        return seg[node] = value;

    int mid = start + (end - start) / 2;
    int lt = update(node*2, index, value, start, mid);
    int rt = update(node*2+1, index, value, mid+1, end);
    return seg[node] = lt*rt;
}


int query(int node, int left, int right, int start, int end){
    if(right < start || end < left)
        return 1;
    if(left <= start && end <= right)
        return seg[node];
    int mid = start + (end - start) / 2;
    int lt = query(node*2, left, right, start, mid);
    int rt = query(node*2+1, left, right, mid+1, end);
    return lt*rt;
}

// void arrprint(int n){
//     cout<<"\n arr \n";
//     for(int i = 0; i < n; i++){
//         cout<<arr[i]<<", ";
//     }cout<<"\n";
// }

// void segprint(int s){
//     cout<<" seg \n";
//     for(int i = 1; i < s; i++){
//         cout<<seg[i]<<", ";
//     }cout<<"\n";
// }

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    while(!cin.eof()){
        int n,k;
        cin>>n>>k;

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

        // arrprint(n);

        init(1, 0, n-1);

        // cout<<"\ninit\n";
        // segprint(seg.size());

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

                // cout<<"\nupdate!\n";
                // segprint(seg.size());

            }else if(comand == 'P'){
                cin>>i>>j;
                int query_num = query(1, i-1, j-1, 0, n-1);
                if(query_num < 0){
                    ans += "-";
                }else if(query_num == 0){
                    ans += "0";
                }else if(query_num > 0){
                    ans += "+";
                }

                // cout<<"\nquery!!!\n";
                // segprint(seg.size());
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}