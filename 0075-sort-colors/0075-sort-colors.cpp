class Solution {
public:
    void sortColors(vector<int>& nums) {
       int z=0;
           int o=0;int t=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                z++;
            if(nums[i]==1)
                o++;
            if(nums[i]==2)
                t++;
        }
        for(int i=0;i<n;i++)
        {
            if(z>0)
            {
                nums[i]=0;
                z--;
                continue;
            }
            
        if(o>0)
            {
                nums[i]=1;
                o--;
                continue;
            }
        if(t>0)
            {
                nums[i]=2;
                t--;
                continue;
            }
        }
    }
};