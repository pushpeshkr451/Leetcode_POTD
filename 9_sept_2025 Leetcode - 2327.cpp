Leetcode - 2327. Number of People Aware of a Secret

class Solution {
public:

    // in this question , we have to find at last how many person get know about
    // the secret so we have to make the array of size n initialise it with 0
    // and after that ae start filling the array with i + delay upto i + forget
    // means from where person get start tellling the secret until it forget it
    // and at last count the total number of person who know the secret
    
    const int mod = 1e9 + 7;
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> ans(n, 0);

        ans[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i + delay; j < n && j < i + forget; j++) {
                ans[j] += (ans[i]) % mod;
            }
        }

        long long total = 0;
        int j = n - 1;
        while (forget--) {
            total += (ans[j--]) % mod;
        }

        return total % mod;
    }
};
