class BIT {
    vector<int> tree;
    int n;

public:
    BIT(int size) {
        n = size + 5; // safe margin
        tree.assign(n, 0);
    }

    void add(int index, int value) {
        for (++index; index < n; index += index & -index)
            tree[index] += value;
    }

    int get(int index) {
        int res = 0;
        for (++index; index > 0; index -= index & -index)
            res += tree[index];
        return res;
    }

    int range(int l, int r) {
        return l > r ? 0 : get(r) - get(l - 1);
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());

        BIT bit(n);
        vector<vector<int>> occur(maxNum + 2);

        // Record occurrences for each number
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0)
                bit.add(i, 1);  // mark zeroes
            else
                occur[nums[i]].push_back(i);
        }

        int res = 0;

        for (int num = 1; num <= maxNum; ++num) {
            if (occur[num].empty()) continue;

            int pieces = 0;
            int prev = n;  // start from right to left

            // reverse direction
            for (int i = occur[num].size() - 1; i >= 0; --i) {
                int pos = occur[num][i];
                if (prev == n || bit.range(pos + 1, prev - 1) > 0) {
                    ++pieces;
                    prev = pos;
                }
            }

            // after processing, mark them as zero
            for (int p : occur[num])
                bit.add(p, 1);

            res += pieces;
        }

        return res;
    }
};
