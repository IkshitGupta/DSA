#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int dp[2][20001];
int n;
int solve(int i, int j, vector<vector<int> > &A){
    if (i >= 2 || i < 0) return 0;
    if (j >= n) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max({A[i][j] + solve(i, j + 2, A), solve(i + 1, j, A), solve(i, j + 1, A)});
}
int adjacent(vector<vector<int> > &A) {
    n = A[0].size();
    memset(dp, -1, sizeof(dp));
    return solve(0, 0, A);
}
int main(){
    vector<vector<int> > A = {{74, 37, 82, 1},{66, 38, 16, 1}};
    cout << adjacent(A);
    cout << 1;
    return 0;
}