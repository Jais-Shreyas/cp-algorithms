#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Computes the Longest Increasing Subsequence (LIS) of an array.
 */
class LIS
{
public:
  /**
   * @brief Finds and returns the actual elements of the Longest Increasing Subsequence.
   * @param v The input vector of integers.
   * @return A vector containing the elements of the LIS in their original order.
   */
  vector<int> getLIS(const vector<int> &v)
  {
    int n = v.size();
    // reverse(v.begin(), v.end());
    vector<int> lis;
    vector<int> index(n);
    for (int i = n - 1; i >= 0; i--)
    {
      if (lis.empty() || lis.back() > v[i])
      {
        lis.push_back(v[i]);
        index[i] = lis.size() - 1;
      }
      else
      {
        auto ind = lower_bound(lis.begin(), lis.end(), v[i], greater<>());
        *ind = v[i];
        index[i] = ind - lis.begin();
      }
    }
    int lisLen = lis.size();
    vector<int> LIS;
    int prev = lisLen - 1;
    for (int i = n - 1; i >= 0; i--)
    {
      if (index[i] == prev)
      {
        LIS.push_back(v[n - i - 1]);
        prev--;
      }
    }

    return LIS;
  }
};
