#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    string s, t;
    cin >> s >> t;

    while(t.size() > s.size()){
        if(t.back() == 'A') t.pop_back();
        else{
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }

    if(s == t) cout<<1;
    else cout<<0;


    return 0;
}
