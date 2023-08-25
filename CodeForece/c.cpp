#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        // 다르면 눕혀봤자 대칭 아님
        if (a[1] != n) {
            cout << "NO" << '\n';
            continue;
        }

        // 옆으로 눕히는 부분
        vector<int> b;
        for (int i = n; i >= 1; i--) {
            while (b.size() < a[i]) {
                // index i를 삽입
                b.push_back(i);
            }
        }

        // for(int i = 0; i < b.size(); i++){
        //     cout<<b[i]<<" ";
        // }cout<<"\n";

        bool meow = true;
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i - 1]) {
                cout << "NO" << '\n';
                meow = false;
                break;
            }
        }
        if (meow) {
            cout << "YES" << '\n';
        }
    }
    return 0;
}