#include <iostream>
#include <vector>
using namespace std;

class LazyPropagationSegmentTree {
public:
    LazyPropagationSegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0); // Initialize the lazy array with zeros
        build(arr, 0, 0, n - 1); // Build the segment tree
    }

    // Update the range [ql, qr] by adding delta
    void update(int ql, int qr, int delta) {
        updateUtil(0, 0, n - 1, ql, qr, delta);
    }

    // Query the range [ql, qr]
    int query(int ql, int qr) {
        return queryUtil(0, 0, n - 1, ql, qr);
    }

private:
    vector<int> tree, lazy;
    int n;

    // Build the segment tree
    void build(vector<int>& arr, int node, int left, int right) {
        if (left == right) {
            tree[node] = arr[left];
        } else {
            int mid = left + (right - left) / 2;
            build(arr, 2 * node + 1, left, mid);
            build(arr, 2 * node + 2, mid + 1, right);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    // Propagate the lazy value down to child nodes
    void propagate(int node, int left, int right) {
        if (lazy[node] != 0) {
            tree[node] += lazy[node] * (right - left + 1);

            if (left != right) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }

            lazy[node] = 0;
        }
    }

    // Update the range [ql, qr] by adding delta
    void updateUtil(int node, int left, int right, int ql, int qr, int delta) {
        propagate(node, left, right);

        if (qr < left || right < ql) {
            return;
        }

        if (ql <= left && right <= qr) {
            tree[node] += delta * (right - left + 1);

            if (left != right) {
                lazy[2 * node + 1] += delta;
                lazy[2 * node + 2] += delta;
            }
            return;
        }

        int mid = left + (right - left) / 2;
        updateUtil(2 * node + 1, left, mid, ql, qr, delta);
        updateUtil(2 * node + 2, mid + 1, right, ql, qr, delta);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // Query the range [ql, qr]
    int queryUtil(int node, int left, int right, int ql, int qr) {
        propagate(node, left, right);

        if (qr < left || right < ql) {
            return 0;
        }

        if (ql <= left && right <= qr) {
            return tree[node];
        }

        int mid = left + (right - left) / 2;
        int left_sum = queryUtil(2 * node + 1, left, mid, ql, qr);
        int right_sum = queryUtil(2 * node + 2, mid + 1, right, ql, qr);
        return left_sum + right_sum;
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    LazyPropagationSegmentTree seg_tree(arr);

    cout << seg_tree.query(1, 3) << endl;  // Output: 15 (Sum in range [1, 3])

    seg_tree.update(1, 3, 2);  // Update range [1, 3] by adding 2

    cout << seg_tree.query(1, 3) << endl;  // Output: 21 (Updated sum in range [1, 3])

    return 0;
}
