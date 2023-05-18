class Solution {
public:
    int rob1(vector<int>& nums) {
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
    
    
    int rob(vector<int>& nums) {
     vector<int>first,last;
        int n=nums.size();
        if (n==1)
            return nums[0];
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                first.push_back(nums[i]);
            if(i!=n-1)
                last.push_back(nums[i]);
        }
        return max(rob1(first),rob1(last));
    }
};