class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto it:mp){
            ans.push_back(it.first);
        }
        int k = ans.size();
        for(int i=0;i<k;i++){
            nums[i]=ans[i];
        }

        return k;
    }
};