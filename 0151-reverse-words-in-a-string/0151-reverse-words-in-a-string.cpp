class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans="";
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++){
            string res="";
            while (i<n && s[i]!=' '){
                res+=s[i];
                i++;
            }
            reverse(res.begin(),res.end());
            if(res.size()>0) ans+=" "+res;
        }
        return ans.substr(1);
    }
};