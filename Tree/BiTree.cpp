#include <iostream>
using namespace std;

/*
为了避免调用者访问BiTree类的私有成员root，在构造函数、析构函数以及遍历函数中调用了相应的私有函数
例如：在函数PreOrder()中调用了私有函数PreOrder(root)
*/

template <typename T> struct TreeNode {
    T data;
    TreeNode<T>*lchid, *rchild;
};

template <typename T> 
class BiTree {
public:
    BiTree() { root = Creat(); }          // 建立二叉树
    ~BiTree() { Release(root); }          // 释放各结点存储空间
    void PreOrder() { PreOrder(root); }   // 前序遍历二叉树
    void InOrder() { InOrder(root); }     // 中序遍历二叉树
    void PostOrder() { PostOrder(root); } // 后序遍历二叉树
    // void LevelOrder();//层序遍历二叉树
private:
    TreeNode<T>* Creat();            // 构造含函数调用
    void Release(TreeNode<T>* bt);   // 析构函数的调用
    TreeNode<T>* root;               // 指向根结点的头指针
    void PreOrder(TreeNode<T>* bt);  // 前序遍历函数调用
    void InOrder(TreeNode<T>* bt);   // 中序遍历函数调用
    void PostOrder(TreeNode<T>* bt); // 后序遍历函数调用
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
        bt->lchid = Creat();  // 递归建立左子树
        bt->rchild = Creat(); // 递归建立右子树
    }
    return bt;
}

template <typename T> 
void BiTree<T>::Release(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return;
    } else {
        Release(bt->lchid);
        Release(bt->rchild);
        delete bt;
    }
}

template <typename T> 
void BiTree<T>::PreOrder(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return;
    } else {
        cout << bt->data << "\t"; // 访问根结点的数据域
        PreOrder(bt->lchid);      // 前序递归遍历bt的左子树
        PreOrder(bt->rchild);     // 前序递归遍历bt的右子树
    }
}

template <typename T> 
void BiTree<T>::InOrder(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return;
    } else {
        InOrder(bt->lchid);       // 中序递归遍历bt的左子树
        cout << bt->data << "\t"; // 访问根结点的数据域
        InOrder(bt->rchild);      // 中序递归遍历bt的右子树
    }
}

template <typename T> 
void BiTree<T>::PostOrder(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return;
    } else {
        PostOrder(bt->lchid);     // 后序递归遍历bt的左子树
        PostOrder(bt->rchild);    // 后序递归遍历bt的右子树
        cout << bt->data << "\t"; // 访问根结点的数据域
    }
}

int main() {
    BiTree<char> tree;
    tree.PreOrder();
    cout << endl;
    tree.InOrder();
    cout << endl;
    tree.PostOrder();
    system("PAUSE");
    return 0;
}

/*
Input:
AB#D##C##

Output:
A B D C
B D A C
D B C A
*/
