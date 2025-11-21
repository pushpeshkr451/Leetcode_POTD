class Solution {
public:
    int countPalindromicSubsequence(string s) {
        
        vector<pair<int,int>>lett(26,{-1,-1});

        for(int i=0;i<s.size();i++){
            int ind = s[i]-'a';
            if(lett[ind].first==-1) lett[ind].first = i;
            lett[ind].second = i;
        }
        
        int ans = 0;

        for(int i=0;i<26;i++){
            int left = lett[i].first;
            int right = lett[i].second;

            if(left==-1) continue;

            unordered_set<char>st;
            for(int j = left+1;j<right;j++) st.insert(s[j]);

            ans +=st.size();
        }

        return ans;
    }
};
