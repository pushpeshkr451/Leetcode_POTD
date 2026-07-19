// Last updated: 19/07/2026, 08:12:26
1class Solution {
2public:
3    vector<bool> transformStr(string s, vector<string>& strs) {
4        int n=s.size();
5
6        int tot=0;
7        vector<int>pre(n);
8
9        for(int i=0;i<n;i++){
10            if(s[i]=='0')tot++;
11            pre[i]=tot;
12        }
13
14        vector<bool>ans;
15
16        for(auto &t:strs){
17            int z=0,q=0;
18
19            for(auto c:t){
20                if(c=='0')z++;
21                else if(c=='?')q++;
22            }
23
24            int k=tot-z;
25            if(k<0 || k>q){
26                ans.push_back(false);
27                continue;
28            }
29
30            bool ok=true;
31            int curz=0,curq=0;
32
33            for(int i=0;i<n;i++){
34                if(t[i]=='0')curz++;
35                else if(t[i]=='?')curq++;
36
37                int mx=curz+min(curq,k);
38
39                if(mx<pre[i]){
40                    ok=false;
41                    break;
42                }
43            }
44            ans.push_back(ok);
45        }
46        return ans;
47    }
48};