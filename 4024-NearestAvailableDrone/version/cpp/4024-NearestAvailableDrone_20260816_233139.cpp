// Last updated: 16/08/2026, 23:31:39
1class Solution {
2public:
3    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
4        int n=drones.size();
5
6        int tx=target[0],ty=target[1];
7        int mi=INT_MAX,idx=-1;
8
9        for(int i=0;i<n;i++){
10            int a=drones[i][0],b=drones[i][1];
11
12            int range=drones[i][2];
13            int dist=abs(a-tx)+abs(b-ty);
14
15            if(dist<=range){
16                if(dist<mi){
17                    mi=dist;
18                    idx=i;
19                }
20            }
21        }
22
23        return idx;
24    }
25};