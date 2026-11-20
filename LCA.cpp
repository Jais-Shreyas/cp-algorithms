#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Binary Lifting implementation for Lowest Common Ancestor (LCA).
 * 
 * @param tree Adjacency list representation of the tree.
 * @param root Root vertex of the tree.
 *
 * @note parent[j][v] stores the 2^j-th ancestor of vertex v.
 *       A value of -1 indicates that the ancestor does not exist.
 * 
 */
class LCA
{
  int n;
  int LOG;
  vector<vector<int>> parent;
  vector<int> depth;
public:
  LCA(vector<vector<int>> &tree, int root)
  {
    n = tree.size();
    LOG = __lg(n) + 1;
    depth.resize(n);
    parent.resize(LOG, vector<int> (n, -1));

    queue<array<int, 2>> q;
    q.push({root, -1});

    while (!q.empty())
    {
      auto [u, p] = q.front();
      q.pop();
      for (auto &v : tree[u])
      {
        if (v != p)
        {
          parent[0][v] = u;
          depth[v] = depth[u] + 1;
          q.push({v, u});
        }
      }
    }

    for (int j = 1; j < LOG; j++)
    {
      for (int i = 0; i < n; i++)
      {
        if (parent[j - 1][i] != -1)
        {
          parent[j][i] = parent[j - 1][parent[j - 1][i]];
        }
      }
    }
  }

  int lca(int a, int b)
  {
    if (depth[a] < depth[b]) swap(a, b);
    int diff = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++)
    {
      if ((diff >> i) & 1) a = parent[i][a];
    }
    if (a == b) return a;
    for (int i = LOG - 1; i >= 0; i--)
    {
      if (parent[i][a] == parent[i][b]) continue;
      a = parent[i][a], b = parent[i][b];
    }
    return parent[0][a];
  }
};

int main()
{
  vector<vector<int>> tree = {
    {1, 2},
    {0, 3, 4},
    {0},
    {1},
    {1}
  };
  LCA lca(tree, 0);
  cout << lca.lca(3, 4) << '\n';
}