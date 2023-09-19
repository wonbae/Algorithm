#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    long long swaps = 0;
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            swaps += (mid - i + 1); // 중요: 역순으로 정렬된 경우 Swap 횟수를 더합니다.
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int p = left; p <= right; ++p) {
        arr[p] = temp[p];
    }

    return swaps;
}

int counts = 0;
long long mergeSort(vector<int>& arr, vector<int>& temp, int left, int right) {
    long long swaps = 0;
    
    if (left < right) {
        int mid = (left + right) / 2;
        swaps += mergeSort(arr, temp, left, mid);
        swaps += mergeSort(arr, temp, mid + 1, right);
        swaps += merge(arr, temp, left, mid, right);
    }
    // cout<<"left: "<<left<<", right: "<<right<<" swap: "<<swaps<<"\n";
    return swaps;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
    
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> temp(N);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long swapCount = mergeSort(A, temp, 0, N - 1);
    cout << swapCount << endl;

    return 0;
}
