// Last updated: 28/06/2026, 07:48:24
1class Solution {
2public:
3    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
4        sort(arr.begin(), arr.end());
5        
6        int n=arr.size();
7        arr[0]=1;
8        for(int i=1; i<n ; i++){
9            if (arr[i]-arr[i-1]>1)
10                arr[i]=arr[i-1]+1;
11        }
12        return arr.back();
13    }
14};