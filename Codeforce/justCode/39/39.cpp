#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int n, n2;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    cin>>n2;
    vector<int> v2(n2);
    vector<int> res(n + n2);

    for(int i = 0; i < n2; i++){
        cin>>v2[i];
    }

    int size = n + n2;
    int l = 0, r = 0, p = 0;
    while(1){
        if(l >= n && r >= n2) break;

        if(v[l] > v2[r]){
            res[p++] = v2[r++];
        }else if(v[l] == v2[r]){
            res[p++] = v[l++];
        }else{
            res[p++] = v[l++];
        }
    }

    while(l < n) res[p++] = v[l++];
    while(r < n2) res[p++] = v2[r++];

    for(int i = 0; i < size; i++){
        cout<<res[i]<<" ";
    }
    


    return 0;
}