//Bruote force
#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int n, cnt = 0;
    cin>>n;
    vector<int> v(n);
    vector<int> v2(n, 1);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(v[i] < v[j]){
                v2[i]++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<v2[i]<<" ";
    }


    return 0;
}