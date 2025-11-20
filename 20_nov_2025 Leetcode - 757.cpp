class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        if(intervals.size()==1)return 2;
        vector<int>a,b;

        for(auto it:intervals){
            a.push_back(it[0]);
            b.push_back(it[1]);
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int ans=2;
        int aft=a[1],pre=b[0];
        int i=1,j=0;
        while(i<a.size() && j<b.size()){
            if(aft==pre){
                ans++;
                aft=max(aft,a[i++]);
                pre=min(pre,b[j++]);
            }
            else if(aft>pre){
                ans+=2;
                aft=max(aft,a[i++]);
                pre=max(pre,b[j++]);
            }
            else{
                aft=max(aft,a[i++]);
                pre=max(pre,b[j++]);
            }
        }
        return ans;
    }
};
