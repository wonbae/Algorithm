#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int psyDistance(const string& type1, const string& type2) {
    int distance = 0;
    for (int i = 0; i < 4; i++) {
        if (type1[i] != type2[i]) {
            distance++;
        }
    }
    return distance;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<string> mbti(n);
        for (int i = 0; i < n; i++) {
            cin >> mbti[i];
        }

        if(n > 32){
            cout<<0<<"\n";
        }else{

            int minDistance = 100;
            for (int i = 0; i < n-2; i++) {
                for (int j = i + 1; j < n-1; j++) {
                    for (int k = j + 1; k < n; k++) {
                        int distance = psyDistance(mbti[i], mbti[j]) +
                                    psyDistance(mbti[j], mbti[k]) +
                                    psyDistance(mbti[k], mbti[i]);
                        minDistance = min(minDistance, distance);
                    }
                }
            }

            cout << minDistance << "\n";
        }
    }

    return 0;
}
