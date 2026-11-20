#include <bits/stdc++.h>
using namespace std;

/**
* @brief Constructs and builds a Segment Tree.
* 
* @param arr The input vector to build the tree from.
* @param fun The associative function for merging nodes (e.g., sum, min, max).
* @param id The identity element for the operation (e.g., 0 for sum, INF for min).
*/
template<typename T>
class SegmentTree
{
  int n;
  vector<T> v;
  vector<T> seg;
  function<T(T, T)> func;
  T ide;
public:
  SegmentTree(vector<T>& arr, function<T(T, T)> fun, T id)
  {
    n = arr.size();
    v = arr;
    seg.resize(4 * n);
    func = fun;
    ide = id;
    build(0, 0, n);
  }

  void build(int x, int l, int r)
  {
    if (l + 1 == r)
    {
      seg[x] = v[l];
      return;
    }
    int mid = (l + r) / 2;
    build(2 * x + 1, l, mid);
    build(2 * x + 2, mid, r);
    seg[x] = func(seg[2 * x + 1], seg[2 * x + 2]);
  }

  T query(int l, int r)
  {
    return query(0, l, r, 0, n);
  }
  
  T query(int x, int l, int r, int L, int R)
  {
    if (R <= l || r <= L) return ide;
    if (l <= L && R <= r) return seg[x];
    int mid = (L + R) / 2;
    return func(query(2 * x + 1, l, r, L, mid), query(2 * x + 2, l, r, mid, R));
  }

  void update(int target, T val)
  {
    update(0, target, val, 0, n);
  }

  void update(int x, int target, T val, int L, int R)
  {
    if (L + 1 == R)
    {
      seg[x] = val;
      return;
    }
    int mid = (L + R) / 2;
    if (target < mid)
    {
      update(2 * x + 1, target, val, L, mid);
    }
    else
    {  
      update(2 * x + 2, target, val, mid, R);
    }
    seg[x] = func(seg[2 * x + 1], seg[2 * x + 2]);
  }
};
