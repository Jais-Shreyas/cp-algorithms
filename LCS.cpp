#include <bits/stdc++.h>
using namespace std;

/**
* @brief Computes the LCS length and the string.
* 
* @param a First string.
* @param b Second string.
*/
class LCS
{
  int LCSLen = -1;
  string LCSString;
public:
  LCS(const string &a, const string &b)
  {
    int n = a.length();
    int m = b.length();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (a[i] == b[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
        else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
      }
    }

    LCSLen = dp[n][m];
    string LCSString;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
      if (a[i - 1] == b[j - 1]) LCSString += (a[i - 1]), i--, j--;
      else if (dp[i - 1][j] > dp[i][j - 1]) i--;
      else j--;
    }
    reverse(LCSString.begin(), LCSString.end());
  }
  int getLCSLength() const { return LCSLen; }
  string getLCSString() const { return LCSString; }
};
