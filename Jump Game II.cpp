class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1)return 0;
        int jumps=1;
        int curr_max=nums[0];
        
        int index=0;
        int max_reach=nums[0];
        
        while(max_reach<nums.size()-1)
        {
            index++;
            
            if (index+nums[index]>curr_max)
            {
                curr_max=index+nums[index];
            }
            if (index==max_reach)
            {
                jumps++;
                max_reach=curr_max;
            }
            
            
        }
        
            
        
        return jumps;
    }
};
