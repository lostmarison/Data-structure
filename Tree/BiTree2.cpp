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
    queue<TreeNode<T>*> q;  // 定义队列
    q.push(root);           // 根结点入队
    while (!q.empty()) {
        TreeNode<T>* node = q.front();  // 取出队列首元素
        q.pop();                        // 队列首元素出队
        // 如果该结点为叶结点
        if (node->left == nullptr && node->right == nullptr) {
            A.push_back(node->data);  // 叶结点入队
        } else {                      // 非叶节点，加入队列继续遍历
            if (node->left != nullptr) {  // 左孩子存在
                q.push(node->left);       // 左孩子入队
            }
            if (node->right != nullptr) {  // 右孩子存在
                q.push(node->right);       // 右孩子入队
            }
        }
    }
    return A;
}

/*6.编写算法把二叉树的叶结点按从左到右的顺序连成一个单链表，表头指针为first。
二叉树按二叉链表方式存储，链接时用叶结点的右指针域来存放单链表指针。*/
template <typename T>
TreeNode<T>* connectLeafNodes(TreeNode<T>* root) {
    if (root == nullptr) {
        return nullptr;
    }
    // 使用队列进行层次遍历
    queue<TreeNode<T>*> q;  // 定义队列
    q.push(root);           // 根结点入队

    TreeNode<T>* first = nullptr;  // 链表头指针
    TreeNode<T>* end = nullptr;    // 链表末尾指针

    while (!q.empty()) {
        TreeNode<T>* node = q.front();  // 取出队首元素
        q.pop();                        // 队列首元素出队
        // 如果该节点是叶节点
        if (node->left == nullptr && node->right == nullptr) {
            // 如果是第一个叶节点，则它也是链表的头
            if (first == nullptr) {
                first = node;
                end = node;
                // 叶节点的right指针用于连接链表，初始时设为nullptr（即不指向其他节点）
                end->right = nullptr;
            } else {  // 否则，将前一个叶节点的right指针指向当前叶节点

                end->right = node;
                end = node;
                // 更新链表的末尾节点的right指针为nullptr
                end->right = nullptr;
            }
        } else {
            // 非叶节点，加入队列继续遍历
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }

    return first;
}
