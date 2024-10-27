```py
from collections import deque
import numpy as np
import networkx as nx
import matplotlib.pyplot as plt


# 无向图
class unGraph:
    # 构造函数
    """
    vertices: 存放顶点信息
    n: 顶点数
    e: 边数
    """

    def __init__(self, vertices, n, e):
        self.vertex = vertices  # 存放顶点的数组
        self.vertexNum = n  # 图的顶点数
        self.edgeNum = e  # 图的边数
        self.edge = [[0] * n for _ in range(n)]  # 存放图中边的列表（邻接矩阵）
        self.visited = [0] * n  # 用于DFS的访问标记
        # 输入边的信息
        for _ in range(e):
            i, j = map(int, input().split())
            self.edge[i][j] = 1
            self.edge[j][i] = 1  # 无向图

        # 深度优先遍历
        def DFS(self, v):
            print(self.vertex[v], end=" ")
            self.visited[v] = 1
            for j in range(self.vertexNum):
                # 通过邻接矩阵找距当前顶点最近的(一般是按顺序的第一个)未被访问的顶点
                if self.edge[v][j] == 1 and self.visited[j] == 0:
                    self.DFTraverse(j)

        # 广度优先遍历
        def BFS(self, v):
            q = deque([v])  # 创建一个队列并将起始顶点加入队列
            print(self.vertex[v], end=" ")  # 打印起始顶点
            self.visited[v] = 1  # 标记为已访问

            while q:
                current = q.popleft()  # 从队列中取出一个顶点
                for j in range(self.vertexNum):
                    if self.edge[current][j] and not self.visited[j]:
                        # 如果当前顶点与 j 相连且 j 未被访问
                        print(self.vertex[j], end=" ")  # 打印顶点 j
                        self.visited[j] = 1  # 标记 j 为已访问
                        q.append(j)  # 将 j 加入队列


if __name__ == "__main__":
    graph = unGraph([1, 2, 3, 4, 5], 5, 8)
    A = np.array(graph.edge)
    G = nx.from_numpy_array(A)
    nx.draw(G, node_size=500, with_labels=True)
    plt.show()
```
![image](https://github.com/user-attachments/assets/db46aceb-b7a0-43bd-a26f-da4c83eb0e13)
