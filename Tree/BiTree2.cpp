#include <vector>
#include "BiTree1.cpp"

// 1.统计二叉树中结点的个数
template <typename T>
int countTreeNodes(TreeNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    return countTreeNodes(root->left) + countTreeNodes(root->right) + 1;
}

// 2.计算二叉树中所有结点值之和
template <typename T>
int sumTreeNodes(TreeNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    return sumTreeNodes(root->left) + sumTreeNodes(root->right) + root->data;
}

// 3.计算二叉树中叶结点的个数
template <typename T>
int countLeafNodes(TreeNode<T>* root) {
    if (root == nullptr) {
        return 0;
    }
    if (root->left == nullptr && root->right == nullptr) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// 4.交换二叉树中所有结点的左右子树
template <typename T>
void swapSubTree(TreeNode<T>* root) {
    if (root == nullptr) {
        return;
    }
    // 交换左右子树
    TreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;
    // 递归遍历
    swapSubTree(root->left);
    swapSubTree(root->right);
}

// 5.已知一棵二叉树采用二叉链表方式存储，编写算法按从左到右的顺序把叶结点的值存放到数组A[]中
template <typename T>
vector<T> addLeafNodes(TreeNode<T>* root) {
    vector<T> A;
    if (root == nullptr) {
        return A;
    }
    // 使用队列进行层次遍历
    queue<TreeNode<T>*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode<T>* node = q.front();
        q.pop();
        if (node->left == nullptr && node->right == nullptr) {
            A.push_back(node->data);
        } else {
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }
    return A;
}
