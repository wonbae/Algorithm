// // Find
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    
//     int N, M;
//     cin >> N >> M;

//     string S;
//     cin >> S;

//     string ioi = "I";
//     for(int i = 0; i < N; i++){
//         ioi += "OI";
//     }

//     int pos = 0;
//     int cnt = 0;

//     while(pos < S.length() - ioi.length() + 1){
//         auto found = S.find(ioi, pos);
//         if(found != string::npos){
//             // cout<<S.substr(found, ioi.length())<<"\n";
//             cnt++;
//             pos = found + 1;
//         }else{
//             break;
//         }
//     }

//     cout<<cnt<<"\n";

//     return 0;
// }


// // Sliding Window
// #include <iostream>
// #include <string>
// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

//     int N, M;
//     cin >> N >> M;

//     string ioi = "I";
//     for(int i = 0; i < N; i++){
//         ioi += "OI";
//     }
    

//     string S;
//     cin >> S;

//     int count = 0;
//     int windowSize = 2 * N + 1;

//     // Create the initial window
//     string window = S.substr(0, windowSize);
//     // cout<<window<<"\n";
//     // Count occurrences of the pattern
//     for (int i = 0; i <= S.length() - windowSize; i++) {
//         if (window == ioi) {
//             count++;
//         }
        
//         // Slide the window
//         window = window.substr(1) + S[i + windowSize];
//         // cout<<window<<"\n";
//     }

//     cout << count << endl;

//     return 0;
// }


#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int left = 0, right = 0;
    int cnt = 0;

    while (right < m) {
        if (s[right] == 'I' && s[right + 1] == 'O' && s[right + 2] == 'I') {
            right += 2;
            if (right - left == 2 * n) {
                cnt++;
                left += 2;
            }
        } else {
            right++;
            left = right;
        }
    }

    cout << cnt << endl;

    return 0;
}

