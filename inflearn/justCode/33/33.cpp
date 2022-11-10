#include<iostream>
#include<vector>
using namespace std;

bool desc(int a, int b){
    return a > b ? a : b;
}
int main(){
    freopen("input.txt", "rt", stdin);
    int n, cnt = 0;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end(), desc);

    for(int i = 0; i < n - 1; i++){
        if(cnt == 2){
            cout<<v[i];
            break;
        }
        if(v[i] == v[i + 1]){
            continue;
        }else{
            cnt++;
        }
    }

    return 0;
}