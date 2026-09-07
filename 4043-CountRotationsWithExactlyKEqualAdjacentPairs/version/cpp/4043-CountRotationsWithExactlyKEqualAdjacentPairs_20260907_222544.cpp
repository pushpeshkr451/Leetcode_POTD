// Last updated: 07/09/2026, 22:25:44
1class Solution {
2public:
3    int countRotations(string s, int k) {
4        int n=s.size();
5        string temp=s+s;
6
7        int ans=0;
8
9        for(int i=0;i<n;i++){
10            int cnt=0;
11            for(int j=i+1;j<i+n;j++){
12                if(temp[j]==temp[j-1])cnt++;
13            }
14            if(cnt==k)ans++;
15        }
16
17
18        return ans;
19    }
20};