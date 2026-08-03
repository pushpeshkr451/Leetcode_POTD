// Last updated: 03/08/2026, 14:34:05
1class Solution {
2public:
3    int countValidPrefixes(string s) {
4        int n=s.size();
5
6        int ans=0;
7        int cnt0=0,cnt1=0;
8
9        for(int i=0;i<n;i++){
10            if(s[i]=='0')cnt0++;
11            else cnt1++;
12
13            if((cnt0%2==1 || cnt1%2==1) and abs(cnt0-cnt1)<=1){
14                cout<<cnt0<<" "<<cnt1<<" ";
15                cout<<endl;
16                ans++;
17            }
18            else if(cnt0==cnt1)ans++;
19        }
20        return ans;
21    }
22};