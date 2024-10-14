#include <deque>
#include <iostream>
using namespace std;

template <typename T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode(T x) : data(x), left(nullptr), right(nullptr) {}
};

template <typename T>
class BiTree {
   public:
    BiTree() { root = Creat(); }           // 建立二叉树
    ~BiTree() { Release(root); }           // 释放各结点存储空间
    void PreOrder() { PreOrder(root); }    // 前序遍历二叉树
    void InOrder() { InOrder(root); }      // 中序遍历二叉树
    void PostOrder() { PostOrder(root); }  // 后序遍历二叉树
    void LevelOrder();                     // 层序遍历二叉树
   private:
    TreeNode<T>* Creat();             // 构造含函数调用
    void Release(TreeNode<T>* bt);    // 析构函数的调用
    TreeNode<T>* root;                // 指向根结点的头指针
    void PreOrder(TreeNode<T>* bt);   // 前序遍历函数调用
    void InOrder(TreeNode<T>* bt);    // 中序遍历函数调用
    void PostOrder(TreeNode<T>* bt);  // 后序遍历函数调用
};

template <typename T>
TreeNode<T>* BiTree<T>::Creat() {
    TreeNode<T>* bt;
    char ch;
    cin >> ch;
    if (ch == '#') {
        bt = nullptr;
    } else {
        bt = new TreeNode<T>;
        bt->data = ch;
        bt->left = Creat();   // 递归建立左子树
        bt->right = Creat();  // 递归建立右子树
    }
    return bt;
}

template <typename T>
void BiTree<T>::Release(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return;
    } else {
        Release(bt->left);
        Release(bt->right);
        delete bt;
    }
}

template <typename T>
void BiTree<T>::PreOrder(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return;
    } else {
        cout << bt->data << "\t";  // 访问根结点的数据域
        PreOrder(bt->left);        // 前序递归遍历bt的左子树
        PreOrder(bt->right);       // 前序递归遍历bt的右子树
    }
}

template <typename T>
void BiTree<T>::InOrder(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return;
    } else {
        InOrder(bt->left);         // 中序递归遍历bt的左子树
        cout << bt->data << "\t";  // 访问根结点的数据域
        InOrder(bt->right);        // 中序递归遍历bt的右子树
    }
}

template <typename T>
void BiTree<T>::PostOrder(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return;
    } else {
        PostOrder(bt->left);       // 后序递归遍历bt的左子树
        PostOrder(bt->right);      // 后序递归遍历bt的右子树
        cout << bt->data << "\t";  // 访问根结点的数据域
    }
}

template <typename T>
void BiTree<T>::LevelOrder() {
    if (root == nullptr) {
        return;
    }
    deque<TreeNode<T>*> dq;
    dq.push_back(root);  // 根指针入队
    while (!dq.empty()) {
        TreeNode<T>* node = dq.front();  // 取出队列首元素
        cout << node->data << "\t";      // 访问当前节点数据
        dq.pop_front();                  // 队列首元素出队
        // 左子节点若存在，则入队
        if (node->left != nullptr) {
            dq.push_back(node->left);
        }
        // 右子节点若存在，则入队
        if (node->right != nullptr) {
            dq.push_back(node->right);
        }
    }
}
