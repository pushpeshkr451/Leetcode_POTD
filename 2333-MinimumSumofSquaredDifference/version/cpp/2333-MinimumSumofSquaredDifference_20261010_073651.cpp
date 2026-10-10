// Last updated: 10/10/2026, 07:36:51
1class Solution{
2public:
3    long long minSumSquareDiff(vector<int>& arr1, vector<int>& arr2, int k1, int k2){
4        int n = arr1.size(), k = k1 + k2, diff=0, maxDiff=0;
5
6        unordered_map<int,int> freq;
7        for(int i=0; i<n; i++){
8            diff = abs(arr1[i] - arr2[i]);
9            freq[diff]++;
10            maxDiff = max(diff, maxDiff);
11        }
12        
13        while(maxDiff > 0 && k > 0){
14            if(freq.count(maxDiff)){
15                int mn = min(k, freq[maxDiff]);
16                k -= mn;
17                freq[maxDiff] -= mn;
18                freq[maxDiff-1] += mn;
19            }
20
21            maxDiff--;
22        }
23
24        long long res = 0;
25        for(auto it:freq)
26            res += (long long)it.first * it.first * it.second;
27
28        return res;
29    }
30};