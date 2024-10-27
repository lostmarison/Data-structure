#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Mgraph {
   public:
    Mgraph(vector<T> a, int n, int e);  // 构造函数
    ~Mgraph() {}
    void DFTraverse(int v);

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

template <typename T>
void Mgraph<T>::DFTraverse(int v) {
    cout << vertex[v] << " ";
    visited[v] = 1;
    for (int j = 0; j < vertexNum; ++j) {
        // 如果邻接矩阵中的值为1且没有被遍历过
        if (edge[v][j] == 1 && visited[j] == 0) {
            DFTraverse(j);
        }
    }
}

int main() {
    vector<char> ch = {'A', 'B', 'C', 'D', 'E'};
    Mgraph<char> MG(ch, 5, 8);  // 假设只有4条边作为示例
    cout << "DFS traversal starting from vertex 0 (A): ";
    MG.DFTraverse(0);
    cout << endl;

    system("pause");
    return 0;
}
