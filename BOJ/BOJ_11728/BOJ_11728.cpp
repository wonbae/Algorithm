#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m, p1 = 0, p2 = 0, p3 = 0;
    cin>>n>>m;
    // int a[1000001] = {0,}, b[1000001] = {0,}, c[1000001] = {0,};
    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(n+m);

    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < m; i++){
        cin>>b[i];
    }

    while(1){
        if(p1 >= n || p2 >= m) break;

        if(a[p1] > b[p2]){
            c[p3++] = b[p2++];
        }else if(a[p1] == b[p2]){
            c[p3++] = a[p1++];
        }else{
            c[p3++] = a[p1++];
        }
    }

    while(p1 < n) c[p3++] = a[p1++];
    while(p2 < m) c[p3++] = b[p2++];

    for(int i = 0; i < n+m; i++){
        cout<<c[i]<<" ";
    }

    return 0;
}