// Last updated: 19/09/2026, 15:33:55
1class Solution {
2public:
3    bool checkOverlap(int radius, int xc, int yc, int x1, int y1, int x2, int y2) {
4        int px = max(x1, min(xc, x2));
5        int py = max(y1, min(yc, y2));
6
7        int disx = px - xc;
8        int disy = py - yc;
9
10        int dis = disx*disx + disy*disy;
11        
12        return dis <= radius * radius;
13    }
14};