#include <bits/stdc++.h>

using namespace std;

// 使用 vector<vector<int>> 实现反向邻接表
// rev_adj[v] 存储的是所有指向 v 的点 (即原图中有 u->v，这里存 v->u)
vector<vector<int>> rev_adj;
vector<int> max_reachable; // 记录每个点能到达的最大值
vector<bool> visited; // 访问标记

// 深度优先搜索，从 start 点反向走
void dfs(int u, int target_max) {
    visited[u] = true;
    max_reachable[u] = target_max;

    for (int v : rev_adj[u]) {
        if (!visited[v]) {
            dfs(v, target_max);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    // 初始化反向邻接表
    rev_adj.assign(n + 1, vector<int>());
    max_reachable.assign(n + 1, 0);
    visited.assign(n + 1, false);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        // 反向建边：原图 u -> v，反向图记录 v -> u
        // 这样当我们从 v 出发时，能找到所有能走到 v 的点
        rev_adj[v].push_back(u); 
    }
    
    // 核心逻辑：从最大的点 N 开始倒序遍历
    // 因为题目要求“能到达的最大值”，从大到小搜，第一次搜到某个点时，
    // 当前的 i 就是它能到达的最大值。
    for (int i = n; i >= 1; --i) {
        if (!visited[i]) {
            dfs(i, i); // 从 i 出发在反向图中搜，路径上所有点的最大可达值都是 i
        }
    }

    for(int i = 1; i <= n; ++i) {
        cout << max_reachable[i] << " ";
    }
    cout << endl;

    return 0;
}
