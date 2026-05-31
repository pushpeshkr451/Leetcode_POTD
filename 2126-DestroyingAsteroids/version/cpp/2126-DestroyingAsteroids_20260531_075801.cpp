// Last updated: 31/05/2026, 07:58:01
1class Solution {
2public:
3    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
4        sort(asteroids.begin(),asteroids.end());
5        long long m = mass;
6        for(int i=0;i<asteroids.size();i++){
7            if(m<asteroids[i]) return false;
8            m += asteroids[i];
9        }
10        return true;
11    }
12};