#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int arr[8];
    bool asc = true;
    bool dec = true;
    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < 7; i++) {
        if (arr[i] > arr[i + 1]) asc = false;
        if (arr[i] < arr[i + 1]) dec = false;
    }
    if (asc) cout << "ascending";
    else if (dec) cout << "descending";
    else cout << "mixed";

    return 0;
}