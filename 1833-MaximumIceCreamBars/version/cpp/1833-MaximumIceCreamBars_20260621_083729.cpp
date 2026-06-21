// Last updated: 21/06/2026, 08:37:29
1class Solution {
2public:
3    int maxIceCream(vector<int>& costs, int coins) {
4        // 1. Find the maximum cost to define the range
5        int max_cost = 0;
6        for (int cost : costs) {
7            if (cost > max_cost) max_cost = cost;
8        }
9        
10        // 2. Create frequency array (Counting Sort)
11        vector<int> counts(max_cost + 1, 0);
12        for (int cost : costs) {
13            counts[cost]++;
14        }
15        
16        int total_bars = 0;
17        
18        // 3. Greedily buy from cheapest to most expensive
19        for (int price = 1; price <= max_cost; ++price) {
20            if (counts[price] == 0) continue;
21            
22            // If we can't afford even one, we stop
23            if (coins < price) break;
24            
25            // Buy as many as we can afford at this price
26            int can_buy = min(counts[price], coins / price);
27            
28            // Update coins and total count
29            coins -= (long long)can_buy * price;
30            total_bars += can_buy;
31        }
32        
33        return total_bars;
34    }
35};