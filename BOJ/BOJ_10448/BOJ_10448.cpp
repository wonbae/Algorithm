#include<iostream>
using namespace std;
#define endl '\n'

int arr[45];
 
bool cal(int K) {
    for (int a = 0; a < 44; a++) {
        for (int b = 0; b < 44; b++) {
            for (int c = 0; c < 44; c++) {
                if (arr[a] + arr[b] + arr[c] == K) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int T, K;
    cin >> T;

    for (int i = 1; i < 45; i++) {
        arr[i-1] = (i*(i+1)) / 2;
    }
     
    for (int i = 0; i < T; i++) {
        cin >> K;
        if (cal(K))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    
    return 0;    
}