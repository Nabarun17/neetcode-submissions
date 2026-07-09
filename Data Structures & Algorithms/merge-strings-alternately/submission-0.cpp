class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";

        int l=0;int r=0;

        while(l<word1.size()&&r<word2.size()){
            ans=ans+word1[l];
            ans=ans+word2[r];
            l++;
            r++;
        }
        while(l<word1.size()){
            ans=ans+word1[l];
            l++;

        }
        while(r<word2.size()){
            ans=ans+word2[r];
            r++;

        }
        return ans;
    }
};