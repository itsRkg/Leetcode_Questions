class Solution {
    
    public boolean match(String s, String p, int i, int j, int[][] memo) {
        // If both string and pattern are fully matched
        if (i == s.length() && j == p.length()) {
            return true;
        }

        // If the string is fully matched, check if the remaining pattern consists of only '*'
        if (i == s.length()) {
            while (j < p.length() && p.charAt(j) == '*') {
                j++;
            }
            return j == p.length();
        }

        if(j== p.length())
            return false;
            
        // Return memoized result if already computed
        if (memo[i][j] != -1) {
            return memo[i][j] == 1;
        }

        boolean ans = false;

        // Case 1: If characters match or pattern has '?'
        if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '?') {
            ans = match(s, p, i + 1, j + 1, memo);
        }

        // Case 2: If pattern has '*'
        if (p.charAt(j) == '*') {
            // '*' matches zero characters
            ans = match(s, p, i, j + 1, memo);

            // '*' matches one or more characters
            for (int k = i; k < s.length() && !ans; k++) {
                ans |= match(s, p, k + 1, j + 1, memo);
            }
        }

        // Memoize the result
        memo[i][j] = ans ? 1 : 0;
        return ans;
    }

    public boolean isMatch(String s, String p) {
        // Initialize the memoization table
        int[][] memo = new int[s.length() + 1][p.length() + 1];
        for (int i = 0; i < memo.length; i++) {
            for (int j = 0; j < memo[0].length; j++) {
                memo[i][j] = -1;
            }
        }
        return match(s, p, 0, 0, memo);
    }
}
