#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int N, M, S, D;
int weight[505];         // 每个城市的救援队数量
int graph[505][505];     // 邻接矩阵存储道路长度
int dist[505];           // S 到各点的最短距离
int w[505];              // S 到各点能召集的最大救援队数
int num[505];            // S 到各点的最短路径条数
int pre[505];            // 存储路径前驱节点
bool visited[505];       // 标记是否已访问

void dijkstra(int s) {
    for(int i = 0; i < N; i++){
        dist[i] = INF;
    }
    dist[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for (int i = 0; i < N; i++) {
        int u = -1, min_d = INF;
        // 找到当前未访问的距离最小的点
        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[j] < min_d) {
                u = j;
                min_d = dist[j];
            }
        }
        if (u == -1) break;
        visited[u] = true;
        for (int v = 0; v < N; v++) {
            if (!visited[v] && graph[u][v] != INF) {
                if (dist[u] + graph[u][v] < dist[v]) {
                    // 发现更短路径
                    dist[v] = dist[u] + graph[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                    pre[v] = u;
                } else if (dist[u] + graph[u][v] == dist[v]) {
                    // 发现等长路径
                    num[v] += num[u];
                    if (w[u] + weight[v] > w[v]) {
                        w[v] = w[u] + weight[v];
                        pre[v] = u;
                    }
                }
            }
        }
    }
}
// 递归打印路径
void printPath(int v) {
    if (v == S) {
        cout << v;
        return;
    }
    printPath(pre[v]);
    cout << " " << v;
}
int main() {
    cin >> N >> M >> S >> D;
    for (int i = 0; i < N; i++){
        cin >> weight[i];
    }
    // 初始化图
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            graph[i][j] = INF;
        }
    }
    for (int i = 0; i < M; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        graph[u][v] = graph[v][u] = l;
    }
    dijkstra(S);
    cout << num[D] << " " << w[D] << endl;
    printPath(D);
    cout << endl;
    return 0;
}