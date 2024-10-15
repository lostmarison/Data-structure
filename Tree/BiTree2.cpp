#include <vector>
#include "BiTree1.cpp"

// 1.统计二叉树中结点的个数
template <typename T>
int countTreeNodes(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return 0;
    }
    return countTreeNodes(bt->lchild) + countTreeNodes(bt->rchilid) + 1;
}
/*
int count1 = 0; // 全局变量
int countTreeNodes(TreeNode* bt) {
    if (bt != nullptr) {
        ++count1;
        countTreeNodes(bt->lchild);
        countTreeNodes(bt->rchilid);
    }
}
*/

// 2.计算二叉树中所有结点值之和
template <typename T>
int sumTreeNodeVal(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return 0;
    }
    return sumTreeNodeVal(bt->lchild) + sumTreeNodeVal(bt->rchilid) + bt->data;
}
/*
int sum = 0;
void sumTreeNodesVal(TreeNode* bt) {
    if (bt != nullptr) {
        sum += bt->data;
        countNodes(bt->lchild);
        countNodes(bt->rchilid);
    }
}
*/

// 3.计算二叉树中叶结点的个数
template <typename T>
int countLeafNodes(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return 0;
    }
    if (bt->lchild == nullptr && bt->rchilid == nullptr) {
        return 1;
    }
    return countLeafNodes(bt->lchild) + countLeafNodes(bt->rchilid);
}
/*
int count2 = 0;
void countLeafNodes(TreeNode* bt) {
    if (bt == nullptr) {
        return;
    }
    if (bt->lchild == nullptr && bt->rchilid == nullptr) {
        ++count2;
    }
    countLeafNodes(bt->lchild);
    countLeafNodes(bt->rchilid);
}
*/

// 4.交换二叉树中所有结点的左右子树
template <typename T>
void swapSubTree(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return;
    }
    // 交换左右子树
    TreeNode<int>* temp = bt->lchild;
    bt->lchild = bt->rchilid;
    bt->rchilid = temp;
    // 递归遍历
    swapSubTree(bt->lchild);
    swapSubTree(bt->rchilid);
}

// 5.已知一棵二叉树采用二叉链表方式存储，编写算法按从左到右的顺序把叶结点的值存放到数组A[]中
// 注意：前序/中序/后序遍历都不影响叶结点的相对位置
template <typename T>
vector<T> A;  // 全局变量
template <typename T>
void addLeafNodes(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return;
    }
    if (bt->lchild == nullptr && bt->rchilid == nullptr) {
        A.push_back(bt->data);
    }
    addLeafNodes(bt->lchild);
    addLeafNodes(bt->rchilid);
}
/*
template <typename T>
vector<T> addLeafNodes(TreeNode<T>* bt) {
    vector<T> A;
    if (bt == nullptr) {
        return A;
    }
    // 使用队列进行层次遍历
    queue<TreeNode<T>*> q;  // 定义队列
    q.push(bt);             // 根结点入队
    while (!q.empty()) {
        TreeNode<T>* node = q.front();  // 取出队列首元素
        q.pop();                        // 队列首元素出队
        // 如果该结点为叶结点
        if (node->lchild == nullptr && node->rchilid == nullptr) {
            A.push_back(node->data);  // 叶结点入队
        } else {                      // 非叶节点，加入队列继续遍历
            if (node->lchild != nullptr) {  // 左孩子存在
                q.push(node->lchild);       // 左孩子入队
            }
            if (node->rchilid != nullptr) {  // 右孩子存在
                q.push(node->rchilid);       // 右孩子入队
            }
        }
    }
    return A;
}
*/

/*6.编写算法把二叉树的叶结点按从左到右的顺序连成一个单链表，表头指针为first。
二叉树按二叉链表方式存储，链接时用叶结点的右指针域来存放单链表指针。*/
template <typename T>
TreeNode<T>* first = nullptr;  // 全局变量
template <typename T>          // 全局变量
TreeNode<T>* p = nullptr;
template <typename T>
void connectLeafNodes(TreeNode<T>* bt) {
    if (bt == nullptr) {
        return;
    }
    if (bt->lchild == nullptr && bt->rchilid == nullptr) {
        if (first == nullptr) {
            first = p;
            p = bt;
        } else {
            p->rchilid = bt;
            p = p->rchilid;
        }
    }
    connectLeafNodes(bt->lchild);
    connectLeafNodes(bt->rchilid);
}
