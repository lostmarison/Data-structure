![1](https://github.com/user-attachments/assets/2b9c84b4-710e-4930-99d2-c9988ecaf80b)
DFS:2 1 5 6 3 4 7 8 (“不撞南墙不回头”)  
BFS:2 1 6 5 3 7 4 8 (一层一层看，先进的先看下一层)
```c++
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class Mgraph {
   public:
    Mgraph(vector<T> a, int n, int e);  // 构造函数
    ~Mgraph() {}
    void DFTraverse(int v);
    void DFS(vector<vector<int>> edge);
    void BFTraverse(int v);

   private:
    vector<T> vertex;          // 存放图中顶点的数组
    vector<vector<int>> edge;  // 存放图中边的数组（邻接矩阵）
    int vertexNum, edgeNum;    // 图的顶点数和边数
    vector<int> visited;       // 用于DFS的访问标记
};

// 建立一个含有n个顶点e条边的图，顶点信息由a给出，边的信息由键盘输入，建立无向图
template <typename T>
Mgraph<T>::Mgraph(vector<T> a, int n, int e)
    : vertex(a),
      vertexNum(n),
      edgeNum(e),
      edge(n, vector<int>(n, 0)),
      visited(n, 0) {
    int i, j;
    for (int k = 0; k < edgeNum; ++k) {
        cin >> i >> j;
        edge[i][j] = 1;
        edge[j][i] = 1;  // 无向图
    }
}

// 深度优先遍历
template <typename T>
void Mgraph<T>::DFTraverse(int v) {
    cout << vertex[v] << " ";  // 输出当前顶点
    visited[v] = 1;            // 当前顶点已被访问
    for (int j = 0; j < vertexNum; ++j) {
        // 通过邻接矩阵找距当前顶点最近的(一般是按顺序的第一个)未被访问的顶点
        if (edge[v][j] == 1 && visited[j] == 0) {
            // 找到第一个就递归下一个
            DFTraverse(j);
        }
    }
}

// 广度优先遍历
template <typename T>
void Mgraph<T>::BFTraverse(int v) {
    queue<int> q;                 // 创建队列
    cout << vertex[v] << " ";     // 输出当前顶点
    visited[v] = 1;               // 当前顶点已被访问
    q.push(v);                    // 当前顶点入队
    while (!q.empty()) {          // 当队列非空时
        int current = q.front();  // 记录当前顶带点
        q.pop();                  // 队头元素出队
        for (int j = 0; j < vertexNum; ++j) {
            // 通过邻接矩阵找与当前结点相邻的“一层”顶点，先被访问顶点先进行“下一层”访问
            // 全部找到才去找下一层
            if (edge[current][j] && visited[j] == 0) {
                cout << vertex[j] << " ";
                visited[j] = 1;
                q.push(j);
            }
        }
    }
}
```
