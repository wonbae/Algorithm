//Two Pointer
#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int n, n2, n3, p1 = 0, p2 = 0, p3 = 0;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }

    cin>>n2;
    vector<int> b(n2);
    for(int i = 0; i < n2; i++){
        cin>>b[i];
    }
    
    n3 = n2 > n ? n2 : n;
    vector<int> c(n3);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    while(p1 < n && p2 < n2){
        if(a[p1] == b[p2]){
            // c.push_back(a[p1]);
            c[p3++] = a[p1++];
            p2++;
        }else if(a[p1] < b[p2]){
            p1++;
        }else{
            p2++;
        }
    }

    for(int i = 0; i < p3; i++){
        cout<<c[i]<<" ";
    }

    return 0;
}