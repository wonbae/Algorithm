// #include<bits/stdc++.h>
// using namespace std;

// // Define the structure for a binary tree node
// struct TreeNode {
//     int data;
//     int weight;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int val, int w) : data(val), weight(w), left(nullptr), right(nullptr) {}
// };

// // Function to insert an edge (parent-child relationship with weight) into the binary tree
// void insertEdge(TreeNode* root, int parent, int child, int weight) {
//     if (root == nullptr) {
//         return;
//     }
    
//     if (root->data == parent) {
//         if (root->left == nullptr) {
//             root->left = new TreeNode(child, weight);
//         } else {
//             root->right = new TreeNode(child, weight);
//         }
//     } else {
//         insertEdge(root->left, parent, child, weight);
//         insertEdge(root->right, parent, child, weight);
//     }
// }


// // Function to print the binary tree using an in-order traversal
// void printTree(TreeNode* root, int depth = 0) {
//     if (root != nullptr) {
//         printTree(root->right, depth + 1);
//         for (int i = 0; i < depth; i++) {
//             std::cout << "  "; // Indent to visualize the tree structure
//         }
//         std::cout << root->data << std::endl;
//         printTree(root->left, depth + 1);
//     }
// }


// int longestPath(TreeNode* root){
//     int tmp = 0;
//     if(root->left == nullptr || root->right == nullptr)
//         return root->weight;

//     int lsum = (root->weight + longestPath(root->left));
//     int rsum = (root->weight + longestPath(root->right));
//     tmp = max(tmp, lsum + rsum);
//     return tmp;

// }

// int main(){
//     int n;
//     cin>>n;

//     TreeNode* root = new TreeNode(1, 0);
//     int parent, child, weight;

//     for(int i = 0; i < n-1; i++){
//         cin>>parent>>child>>weight;

//         insertEdge(root, parent, child, weight);
//     }

//     // printTree(root);

//     int ans = longestPath(root);
//     cout<<ans<<"\n";
// }

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// // Structure to represent an edge in the tree
// struct Edge {
//     int child;
//     int weight;

//     Edge(int c, int w) : child(c), weight(w) {}
// };

// // Structure to represent a node in the tree
// struct TreeNode {
//     vector<Edge> children;
// };

// // Function to perform a depth-first search and find the farthest node from the given source node
// pair<int, int> dfs(const vector<TreeNode>& tree, int node, int parent) {
//     int farthestNode = node;
//     int maxDistance = 0;

//     for (const Edge& edge : tree[node].children) {
//         int child = edge.child;
//         if (child == parent) {
//             continue; // Skip the parent node
//         }

//         pair<int, int> result = dfs(tree, child, node);
//         int distance = result.first + edge.weight;

//         if (distance > maxDistance) {
//             maxDistance = distance;
//             farthestNode = result.second;
//         }
//     }

//     return {maxDistance, farthestNode};
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<TreeNode> tree(n + 1);

//     // Read edge information and build the tree
//     for (int i = 1; i < n; i++) {
//         int parent, child, weight;
//         cin >> parent >> child >> weight;
//         tree[parent].children.emplace_back(child, weight);
//         tree[child].children.emplace_back(parent, weight);
//     }

//     // Find the farthest node from an arbitrary node (node 1 in this case)
//     pair<int, int> result1 = dfs(tree, 1, 0);

//     // Find the farthest node from the farthest node found above
//     pair<int, int> result2 = dfs(tree, result1.second, 0);

//     // The diameter of the tree is the maximum distance found in the second DFS
//     cout << result2.first << endl;

//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;

// // Define the structure for a binary tree node
// struct TreeNode {
//     int data;
//     TreeNode* left;
//     TreeNode* right;
//     int weight;

//     TreeNode(int val, int w) : data(val), left(nullptr), right(nullptr), weight(w) {}
// };

// // Function to insert an edge (parent-child relationship with weight) into the binary tree
// void insertEdge(TreeNode* root, int parent, int child, int weight) {
//     if (root == nullptr) {
//         return;
//     }

//     if (root->data == parent) {
//         if (root->left == nullptr) {
//             root->left = new TreeNode(child, weight);
//         } else {
//             root->right = new TreeNode(child, weight);
//         }
//     } else {
//         insertEdge(root->left, parent, child, weight);
//         insertEdge(root->right, parent, child, weight);
//     }
// }

// // Function to find the longest path from a node to any leaf node, considering edge weights
// int longestPath(TreeNode* root, int& treeDiameter) {
//     if (root == nullptr) {
//         return 0;
//     }

//     int leftHeight = longestPath(root->left, treeDiameter);
//     int rightHeight = longestPath(root->right, treeDiameter);

//     // Update the global maximum diameter by considering the edge weight
//     treeDiameter = max(treeDiameter, leftHeight + rightHeight);

//     return max(leftHeight, rightHeight) + root->weight;
// }

// int main() {
//     int n;
//     cin >> n;

//     TreeNode* root = new TreeNode(1, 0);
//     int parent, child, weight;

//     for (int i = 0; i < n - 1; i++) {
//         cin >> parent >> child >> weight;
//         insertEdge(root, parent, child, weight);
//     }

//     int treeDiameter = 0;
//     longestPath(root, treeDiameter);
//     cout << treeDiameter << endl;

//     return 0;
// }




#include <iostream>
#include <vector>
using namespace std;

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    int weight;

    TreeNode(int val, int w) : data(val), left(nullptr), right(nullptr), weight(w) {}
};

// Function to insert an edge (parent-child relationship with weight) into the binary tree
void insertEdge(TreeNode* root, int parent, int child, int weight) {
    if (root == nullptr) {
        return;
    }

    if (root->data == parent) {
        if (root->left == nullptr) {
            root->left = new TreeNode(child, weight);
        } else {
            root->right = new TreeNode(child, weight);
        }
    } else {
        insertEdge(root->left, parent, child, weight);
        insertEdge(root->right, parent, child, weight);
    }
}

// Function to find the longest path from a node to any leaf node, considering edge weights
int longestPath(TreeNode* root, int& treeDiameter, int& rootOfDiameter) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = longestPath(root->left, treeDiameter, rootOfDiameter);
    int rightHeight = longestPath(root->right, treeDiameter, rootOfDiameter);

    // Calculate the maximum path passing through the current root node, considering edge weights
    int maxPathIncludingRoot = leftHeight + rightHeight + root->weight;

    // Update the maximum path through root if it's greater
    if (maxPathIncludingRoot > treeDiameter) {
        treeDiameter = maxPathIncludingRoot;
        rootOfDiameter = root->weight;
    }

    // Return the maximum height of the subtree rooted at this node, considering edge weights
    return max(leftHeight, rightHeight) + root->weight;
}

int main() {
    int n;
    cin >> n;

    TreeNode* root = new TreeNode(1, 0);
    int parent, child, weight;

    for (int i = 0; i < n - 1; i++) {
        cin >> parent >> child >> weight;
        insertEdge(root, parent, child, weight);
    }

    int treeDiameter = 0;
    int rootOfDiameter = 1; // Initialize with the root node number
    longestPath(root, treeDiameter, rootOfDiameter);
    cout << treeDiameter - rootOfDiameter;

    return 0;
}
