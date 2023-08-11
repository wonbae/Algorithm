#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

bool can_fit(ll w, ll h, ll n, ll board_size) {
    ll cols = board_size / w;
    ll rows = board_size / h;

    return cols * rows >= n;
}

ll binary_search(ll w, ll h, ll n) {
    ll left = 1;
    ll right = max(w, h) * n;

    ll result = 0;

    while (left <= right) {
        ll mid = (left + right) / 2;
        if (can_fit(w, h, n, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    ll w, h, n;
    cin >> w >> h >> n;

    ll min_board_size = binary_search(w, h, n);
    cout << min_board_size << endl;

    return 0;
}
