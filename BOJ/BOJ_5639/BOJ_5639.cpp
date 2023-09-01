#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 전위 순회를 이용하여 트리를 생성
TreeNode* preorderToTree(vector<int>& preorder, int& idx, int maxValue) {
    if (idx >= int(preorder.size()) || preorder[idx] > maxValue) {
        return NULL;
    }
    
    TreeNode* root = new TreeNode(preorder[idx++]);
    root->left = preorderToTree(preorder, idx, root->val);
    root->right = preorderToTree(preorder, idx, maxValue);
    
    return root;
}


void postOrders(TreeNode* root){
    if(root == NULL) return ;

    postOrders(root->left);
    postOrders(root->right);
    cout<<root->val<<"\n";
    
}

int main(){
    vector<int> preOrders;

    int a;
    while(cin>>a){
        preOrders.push_back(a);
    }

    int idx = 0;
    TreeNode* root = preorderToTree(preOrders, idx, INT_MAX);

    postOrders(root);

    return 0;
}