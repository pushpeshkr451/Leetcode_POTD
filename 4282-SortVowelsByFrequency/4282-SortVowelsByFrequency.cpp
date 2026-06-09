// Last updated: 09/06/2026, 19:42:42
class Solution {
public:
    int get(char c){
        if(c=='a')return 0;
        if(c=='e')return 1;
        if(c=='i')return 2;
        if(c=='o')return 3;
        return 4;
    }
    string sortVowels(string s) {
        int n=s.size();

        vector<int>freq(5,0),first(5,-1);

        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u'){
                int id=get(s[i]);
                freq[id]++;
                if(first[id]==-1)first[id]=i;
            }
        }

        vector<pair<pair<int,int>,char>>v;

        string vow="aeiou";

        for(int i=0;i<5;i++){
            if(freq[i]){
                v.push_back({{-freq[i],first[i]},vow[i]});
            }
        }

        sort(v.begin(),v.end());

        string t="";
        for(auto &x:v){
            int cnt=-x.first.first;
            char ch=x.second;
            while(cnt--)t+=ch;
        }

        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                s[i]=t[j++];
            }
        }

        return s;
        
    }
};