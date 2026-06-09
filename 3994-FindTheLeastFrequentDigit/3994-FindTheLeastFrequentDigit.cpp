// Last updated: 09/06/2026, 19:44:45
class Solution {
public:
    int getLeastFrequentDigit(int n) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        unordered_map<int,int>mp;
        while(n>0){
            int p=n%10;
            n/=10;
            mp[p]++;
        }
        for(auto it:mp){
            pq.push({it.second,it.first});
        }
        return pq.top().second;
    }
};