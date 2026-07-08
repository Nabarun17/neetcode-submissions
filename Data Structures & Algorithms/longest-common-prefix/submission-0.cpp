class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(strs.empty())return "";

        string ans="";

        for(int i=0;i<strs[0].size();i++){
            char x = strs[0][i];

            for(int j =0 ;j<n;j++){
                if(i >= strs[j].size() || strs[j][i] != x){
                        return ans;
                }
                
            }
            ans+=x;

            
        }
        return ans;
    }
};