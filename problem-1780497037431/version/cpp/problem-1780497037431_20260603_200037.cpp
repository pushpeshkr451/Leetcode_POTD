// Last updated: 03/06/2026, 20:00:37
1class Solution {
2public:
3    int earliestFinishTime(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
4        int n=a.size(),m=c.size();
5        vector<pair<int,int>>land(n),water(m);
6        for(int i=0;i<n;i++)land[i]={a[i],b[i]};
7        for(int j=0;j<m;j++)water[j]={c[j],d[j]};
8
9        sort(land.begin(),land.end());
10        sort(water.begin(),water.end());
11
12        vector<int>as(n),bs(n),ls(n);
13
14        for(int i=0;i<n;i++){
15            as[i]=land[i].first;
16            bs[i]=land[i].second;
17            ls[i]=as[i]+bs[i];
18        }
19
20        vector<int>cs(m),ds(m),ws(m);
21        for(int j=0;j<m;j++){
22            cs[j]=water[j].first;
23            ds[j]=water[j].second;
24            ws[j]=cs[j]+ds[j];
25        }
26
27        vector<int>pre(n),suf(n);
28
29        pre[0]=bs[0];
30        for(int i=1;i<n;i++){
31            pre[i]=min(pre[i-1],bs[i]);
32        }
33
34        suf[n-1]=ls[n-1];
35        for(int i=n-2;i>=0;i--){
36            suf[i]=min(suf[i+1],ls[i]);
37        }
38
39        vector<int>prea(m),sufa(m);
40        prea[0]=ds[0];
41        for(int j=1;j<m;j++)prea[j]=min(prea[j-1],ds[j]);
42        sufa[m-1]=ws[m-1];
43        for(int j=m-2;j>=0;j--)sufa[j]=min(sufa[j+1],ws[j]);
44
45        int inf=1000000000;
46        int ans=inf;
47
48        for(int i=0;i<n;i++){
49            int li=ls[i];
50            int idx=upper_bound(cs.begin(),cs.end(),li)-cs.begin()-1;
51            int v1=idx>=0?li+prea[idx]:inf;
52            int idx2=upper_bound(cs.begin(),cs.end(),li)-cs.begin();
53            int v2=idx2<m?sufa[idx2]:inf;
54            ans=min(ans,min(v1,v2));
55        }
56
57        for(int j=0;j<m;j++){
58            int wj=ws[j];
59            int idx=upper_bound(as.begin(),as.end(),wj)-as.begin()-1;
60            int v1=idx>=0?wj+pre[idx]:inf;
61            int idx2=upper_bound(as.begin(),as.end(),wj)-as.begin();
62            int v2=idx2<n?suf[idx2]:inf;
63            ans=min(ans,min(v1,v2));
64            
65        }
66        return ans;
67    }
68};