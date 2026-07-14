// Last updated: 15/07/2026, 04:04:11
1class Solution {
2public:
3    int calPoints(vector<string>& nums) {
4        vector<int>calc;
5
6        for(auto it:nums){
7            if(it=="+"){
8                int sum=calc.back()+calc[calc.size()-2];
9                calc.push_back(sum);
10            }
11            else if(it=="D")calc.push_back(calc.back()*2);
12            else if(it=="C")calc.pop_back();
13            else calc.push_back(stoi(it));
14        }
15
16        return accumulate(calc.begin(),calc.end(),0);
17        
18    }
19};