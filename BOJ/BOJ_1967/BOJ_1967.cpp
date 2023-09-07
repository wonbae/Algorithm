#include<bits/stdc++.h>
using namespace std;

// Structure to represent an edge in the tree
struct Edge {
    int child;
    int weight;

    Edge(int c, int w) : child(c), weight(w) {}
};

// Structure to represent a node in the tree
struct TreeNode {
    vector<Edge> children;
};

// Function to perform a depth-first search and find the farthest node from the given source node
pair<int, int> dfs(const vector<TreeNode>& tree, int node, int parent) {
    int farthestNode = node;
    int maxDistance = 0;

    for (const Edge& edge : tree[node].children) {
        int child = edge.child;
        if (child == parent) {
            continue; // Skip the parent node
        }

        pair<int, int> result = dfs(tree, child, node);
        int distance = result.first + edge.weight;

        if (distance > maxDistance) {
            maxDistance = distance;
            farthestNode = result.second;
        }
    }

    return {maxDistance, farthestNode};
}

int main() {
    int n;
    cin >> n;

    vector<TreeNode> tree(n + 1);

    // Read edge information and build the tree
    for (int i = 1; i < n; i++) {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].children.emplace_back(child, weight);
        tree[child].children.emplace_back(parent, weight);
    }

    // Find the farthest node from an arbitrary node (node 1 in this case)
    pair<int, int> result1 = dfs(tree, 1, 0);

    // Find the farthest node from the farthest node found above
    pair<int, int> result2 = dfs(tree, result1.second, 0);

    // The diameter of the tree is the maximum distance found in the second DFS
    cout << result2.first << endl;

    return 0;
}

