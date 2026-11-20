#include <bits/stdc++.h>
using namespace std;

/**
* @brief Initialises an empty DSU.
* 
* @param n The total number of nodes in the graph/tree.
*/
class DSU
{
  vector<int> size, parent;

public:
  DSU(int n)
  {
    size.resize(n + 1, 1), parent.resize(n + 1);   // parent does not store ultimate parent
    iota(parent.begin(), parent.end(), 0);
  }

  int findParent(int n)
  {
    if (n == parent[n]) return n;
    return parent[n] = findParent(parent[n]);
  }
  
  bool unite(int u, int v)
  {
    int pu = findParent(u), pv = findParent(v);
    if (pu == pv) return false;
    if (size[pu] < size[pv]) swap(pu, pv);
    // pu is larger than pv
    // add smaller to larger
    parent[pv] = pu;
    size[pu] += size[pv];
    return true;
  }

  int getSize(int n)
  {
    return size[findParent(n)];
  }
};
