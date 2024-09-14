class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(const string& s, int i, int j, vector<vector<int>>& memo) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (memo[i][j] != -1) return memo[i][j];
        
        long long ans;
        if (s[i] == s[j]) {
            // Find the next and previous occurrence of the same character
            int low = i + 1, high = j - 1;
            while (low <= high && s[low] != s[i]) low++;
            while (low <= high && s[high] != s[i]) high--;
            
            if (low > high) {
                // No matching characters inside
                ans = (2LL * solve(s, i+1, j-1, memo) + 2) % MOD;
            } else if (low == high) {
                // One matching character inside
                ans = (2LL * solve(s, i+1, j-1, memo) + 1) % MOD;
            } else {
                // Two or more matching characters inside
                ans = (2LL * solve(s, i+1, j-1, memo) - solve(s, low+1, high-1, memo) + MOD) % MOD;
            }
        } else {
            ans = solve(s, i+1, j, memo);
            ans = (ans + solve(s, i, j-1, memo)) % MOD;
            ans = (ans - solve(s, i+1, j-1, memo) + MOD) % MOD;
        }
        
        memo[i][j] = ans;
        return memo[i][j];
    }

    int countPalindromicSubsequences(string s) {
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solve(s, 0, n-1, memo);
    }
};
