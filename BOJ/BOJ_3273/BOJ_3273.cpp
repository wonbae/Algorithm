#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n, x, lt = 0, rt, cnt = 0;
    cin>>n;
    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin>>v[i];
    }

    cin>>x;

    sort(v.begin(), v.end());

    rt = n-1;
    while(lt < rt){
        if(v[lt] + v[rt] == x){
            cnt++;
            lt++, rt--;
        }
        if(v[lt] + v[rt] > x){
            rt--;
        }else if(v[lt] + v[rt] < x){
            lt++;
        }
    }

    cout<<cnt<<"\n";


    return 0;
}