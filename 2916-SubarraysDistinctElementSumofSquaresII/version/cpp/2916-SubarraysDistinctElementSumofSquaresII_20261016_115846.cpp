// Last updated: 16/10/2026, 11:58:46
1typedef long long int ll;
2const int MOD = 1e9+7;
3
4struct SegmentTree {    
5    vector<ll> lzy;
6    vector<ll> sum;
7    vector<ll> sqr;
8    int n;
9
10    SegmentTree (int _n) : n(_n) {
11        lzy.resize(4*n, 0);
12        sum.resize(4*n, 0);
13        sqr.resize(4*n, 0);
14    }
15    
16    void update_lzy(int l, int r, int i) {
17        if (l != r) {
18            lzy[i*2+1] += lzy[i];
19            lzy[i*2+2] += lzy[i];
20        }
21        ll gap = r-l+1;
22        ll new_sum = sum[i] + lzy[i]*gap;
23        ll new_sqr = sqr[i] + lzy[i]*sum[i]*2 + lzy[i]*lzy[i]*gap;
24        
25        sum[i] = new_sum % MOD;
26        sqr[i] = new_sqr % MOD;
27        lzy[i] = 0;
28    }
29    
30    void AddOne (int x, int y, int l = 0, int r = -1, int i = 0) {
31        if (r == -1) r += n;
32        update_lzy(l, r, i);
33        
34        if (r < x || l > y) return;
35        if (l >= x && r <= y) {
36            lzy[i] = 1;
37            return update_lzy(l, r, i);
38        }
39        
40        int m = (l+r) >> 1;
41        AddOne (x, y, l, m, i*2+1);
42        AddOne (x, y, m+1, r, i*2+2);
43        
44        sum[i] = (sum[i*2+1] + sum[i*2+2]) % MOD;
45        sqr[i] = (sqr[i*2+1] + sqr[i*2+2]) % MOD;
46    }    
47};
48
49class Solution {
50public:
51    int sumCounts(vector<int>& nums) {
52        int n = nums.size();
53        vector<int> last_pos(100001, -1);
54        
55        SegmentTree tree(n);
56        int ans = 0;
57        
58        for (int j = 0; j < n; j ++) {            
59            int st = last_pos[nums[j]] + 1, ed = j;
60            tree.AddOne(st, ed);
61            
62            ans = (ans + tree.sqr[0]) % MOD;
63            
64            last_pos[nums[j]] = j;
65        }
66        return ans;
67    }
68};