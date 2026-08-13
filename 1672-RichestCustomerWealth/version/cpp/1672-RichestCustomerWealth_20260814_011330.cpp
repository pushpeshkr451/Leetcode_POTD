// Last updated: 14/08/2026, 01:13:30
1// The API isBadVersion is defined for you.
2// bool isBadVersion(int version);
3
4class Solution {
5public:
6    int firstBadVersion(int n) {
7        int lo=0,hi=n;
8
9        while(lo<=hi){
10            int mid=lo+(hi-lo)/2;
11
12            if(isBadVersion(mid)){
13                hi=mid-1;
14            }
15            else lo=mid+1;
16        }
17
18        return lo;
19    }
20};