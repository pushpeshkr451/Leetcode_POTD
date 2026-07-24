// Last updated: 24/07/2026, 22:24:35
1class Solution {
2public:
3    bool lemonadeChange(vector<int>& bills) {
4        int n=bills.size();
5
6        int a=0,b=0;
7
8        for(int i=0;i<n;i++){
9            if(bills[i]==5)a++;
10            else if(bills[i]==10){
11                if(a>0)a--;
12                else return false;
13                b++;
14            }
15            else{
16                if(b>0 && a>0){
17                    a--;
18                    b--;
19                }
20                else if(a>2)a-=3;
21                else return false;
22            }
23        }
24        return true;
25    }
26};