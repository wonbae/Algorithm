#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_finish(const vector<int>& packets, int K, int S, int target_time) {
    long long total_division_sum = 0;
    int current_sum = 0;
    int divisions = 0;

    for (int packet : packets) {
        current_sum += packet;
        if (current_sum > target_time * S) {
            // cout<<"cs: "<<current_sum<<"\n";
            current_sum = packet;
            divisions++;
        }
    }

    divisions++;
    
    return divisions <= K;
}

int main() {
    int N, K, S;
    cin >> N >> K >> S;

    vector<int> packets(N);
    for (int i = 0; i < N; ++i) {
        cin >> packets[i];
    }

    int left = 1, right = N * 10000;
    int result = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (can_finish(packets, K, S, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}
