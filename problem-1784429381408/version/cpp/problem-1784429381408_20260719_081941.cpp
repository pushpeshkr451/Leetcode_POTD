// Last updated: 19/07/2026, 08:19:41
1class Solution {
2public:
3    string shift(string &s){
4        int n=s.size();
5
6        if(n<=1)return s;
7
8        int i=0,j=1,k=0;
9
10        while(i<n && j<n && k<n){
11            char a=s[(i+k)%n];
12            char b=s[(j+k)%n];
13
14            if(a==b)k++;
15            else if(a>b){
16                i=i+k+1;
17                if(i==j)i++;
18                k=0;
19            }
20            else{
21                j=j+k+1;
22                if(i==j)j++;
23                k=0;
24            }
25        }
26        int st=min(i,j);
27
28        return s.substr(st)+s.substr(0,st);
29    }
30    int minimumGroups(vector<string>& words) {
31        vector<string>v;
32
33        for(auto &w:words){
34            string e,o;
35
36            for(int i=0;i<w.size();i++){
37                if(i&1)o+=w[i];
38                else e+=w[i];
39            }
40            v.push_back(shift(e)+"#"+shift(o));
41        }
42
43        sort(v.begin(),v.end());
44
45        int ans=0;
46        for(int i=0;i<v.size();i++){
47            if(i==0||v[i]!=v[i-1])ans++;
48        }
49
50        return ans;
51    }
52};