#include<bits/stdc++.h>
using namespace std;

//https://open.kattis.com/problems/tritiling

//https://github.com/williamfiset/Algorithms/blob/master/src/main/java/com/williamfiset/algorithms/dp/examples/tilingdominoes/TilingDominoes.java

// private static int solution1(int n) {
//     int[][] dp = new int[n + 1][1 << 3];
//     dp[0][7] = 1;
//     for (int i = 1; i < n + 1; i++) {
//       // The number of empty states for this column is the number
//       // of full states in the previous column.
//       dp[i][0] += dp[i - 1][7];

//       dp[i][1] += dp[i - 1][6];

//       // State 2 doesn't contribute to the number of tilings
//       // dp[i][2] += dp[i-1][5];

//       dp[i][3] += dp[i - 1][7];
//       dp[i][3] += dp[i - 1][4];

//       dp[i][4] += dp[i - 1][3];

//       // State 5 doesn't contribute to the number of tilings
//       // dp[i][5] += dp[i-1][2];

//       dp[i][6] += dp[i - 1][7];
//       dp[i][6] += dp[i - 1][1];

//       dp[i][7] += dp[i - 1][3];
//       dp[i][7] += dp[i - 1][6];
//       dp[i][7] += dp[i - 1][0];
//     }
//     // printMatrix(dp);
//     return dp[n][7];
//   }