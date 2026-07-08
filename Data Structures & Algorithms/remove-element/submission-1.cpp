class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k =0;

        int l=0;
        int r = nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==val)
            k++;
            }

        while(l<=r){
            if(nums[l]==val){
                swap(nums[l],nums[r]);
                r--;
            }
            else
            l++;
        }

        return nums.size()-k;

        
    }
};