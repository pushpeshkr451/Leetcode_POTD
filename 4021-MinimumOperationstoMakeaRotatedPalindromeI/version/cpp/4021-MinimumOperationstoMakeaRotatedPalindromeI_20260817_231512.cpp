// Last updated: 17/08/2026, 23:15:12
1class Solution {
2public:
3    int minOperations(string s) {
4
5        int n = s.size() ;
6        int ans = INT_MAX ;
7
8        for ( int r = 0 ; r < n ; r++ ) {
9
10            int ops = r ;
11
12            for ( int i = 0 ; i < n/2 ; i++ ) {
13
14                char left = s[(i+r)%n] ;
15                char right = s[(n-1-i+r)%n] ;
16
17                int f1 = (right-left+26) % 26 ;
18                int f2 = (left-right+26) % 26 ;
19
20                ops += min( f1 , f2 ) ;
21                
22            }
23
24            ans = min( ans , ops ) ;
25            
26        }
27
28        return ans ;
29        
30    }
31};