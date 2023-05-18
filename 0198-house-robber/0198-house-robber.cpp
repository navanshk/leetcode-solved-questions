class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int pre=nums[0];
        int pre2=0;
        for(int i=1;i<n;i++)
        {
            int take=nums[i];
            if(i>1)
                take+=pre2;
            int nontake=0+pre;
            int cur=max(take,nontake);
            pre2=pre;
            pre=cur;
        }
        return pre;
    }
};