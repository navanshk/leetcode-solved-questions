class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n=nums.size();
        int sum=0;
          int total=((n+1)*(n))/2;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        return total-sum;
    }
};