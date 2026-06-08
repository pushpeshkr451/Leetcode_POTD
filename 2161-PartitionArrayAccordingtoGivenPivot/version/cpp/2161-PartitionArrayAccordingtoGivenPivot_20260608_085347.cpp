// Last updated: 08/06/2026, 08:53:47
1class Solution {
2public:
3    vector<int> pivotArray(vector<int>& nums, int pivot) {
4        vector<int>less,high;
5        int count=0;
6        for(auto it:nums){
7            if(it<pivot)less.push_back(it);
8            else if(it>pivot) high.push_back(it);
9            if(it==pivot)count++;
10        }
11        while(count--)less.push_back(pivot);
12        for(auto it:high)less.push_back(it);
13        return less;
14    }
15};