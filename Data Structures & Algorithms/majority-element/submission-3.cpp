class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int cnt=1;
        int x=nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]==x)cnt++;
            else if(cnt==0){
                x=nums[i];
            }
            else cnt--;
        }
        return x;
        
    }
};