class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>ans;
        vector<int>tem;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

       vector<pair<int,int>>v;
       for(auto it :mp){
        v.push_back({it.second,it.first});
       }
       sort(v.begin(),v.end(),greater<pair<int,int>>());
      

       for(int i=0;i<k;i++){
        ans.push_back(v[i].second);

       }
       
    return ans;
        
    }
};
