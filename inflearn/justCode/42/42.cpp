//Binary search
#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int n, m, mid, st = 0, end = 0;

    cin>>n>>m;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    sort(v.begin(), v.end());
    end = n - 1;
    
    while(st <= end){
        mid = (st + end) / 2;

        if(v[mid] == m){
            cout<<mid + 1<<"\n"; 
            break;
        }
        else if(v[mid] > m){
            end = mid - 1;
        }else{
            st = mid + 1;
        }
    }

    return 0;
}