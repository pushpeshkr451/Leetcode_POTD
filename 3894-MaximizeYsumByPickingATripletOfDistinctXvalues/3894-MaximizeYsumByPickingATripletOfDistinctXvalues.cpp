// Last updated: 09/06/2026, 19:45:31
class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        set<int>st(x.begin(),x.end());
        if(st.size()<3)return -1;
        int n=x.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
           mp[x[i]] = max(mp[x[i]], y[i]);
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        int c=0;
        int ans=0;
        while(c<3){
            c++;
            auto it=pq.top();
            pq.pop();
            ans+=it.first;
        }
        return ans;
    }
};