//Two Pointer
#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int n, n2, p1 = 0, p2 = 0, p3 = 0;
    cin>>n;
    vector<int> a(n), c;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    cin>>n2;
    vector<int> b(n2);
    for(int i = 0; i < n2; i++){
        cin>>b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    while(p1 < n && p2 < n2){
        if(a[p1] == b[p2]){
            // c[p3++] = a[p1];
            c.push_back(a[p1]);
        }else if(a[p1] < b[p2]){
            p1++;
        }else{
            p2++;
        }
    }

    for(int i = 0; i < c.size(); i++){
        cout<<c[i]<<" ";
    }

    return 0;
}