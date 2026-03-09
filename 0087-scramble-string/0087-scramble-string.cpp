class Solution {
public:
    unordered_map<string, bool> memo;

    bool solve(string s1, string s2) {
        if (s1 == s2) return true;

        string key = s1 + " " + s2;
        if (memo.count(key)) return memo[key];

        int n = s1.size();

        string a = s1, b = s2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a != b) return memo[key] = false;

        for (int k = 1; k < n; k++) {

            // no swap
            if (solve(s1.substr(0, k), s2.substr(0, k)) &&
                solve(s1.substr(k), s2.substr(k)))
                return memo[key] = true;

            // swap
            if (solve(s1.substr(0, k), s2.substr(n - k)) &&
                solve(s1.substr(k), s2.substr(0, n - k)))
                return memo[key] = true;
        }

        return memo[key] = false;
    }

    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }
};