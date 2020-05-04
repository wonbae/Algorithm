#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int n, select, min, tmp = 0;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    for(int i = 0; i < n - 1; i++){
        min = i;
        for(int j = i + 1; j < n; j++){
            if(v[j] < v[min]){
                 min = j;
            }
        }
        // swap(v[i], v[min]);
        tmp = v[i];
        v[i] = v[min];
        v[min] = tmp;
    }

    for(int i = 0; i < n; i++){
        cout<<v[i]<<" ";
    }

    return 0;
}