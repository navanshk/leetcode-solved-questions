class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int n=nums.size();
        int c1=0;
        int c2=0;
        int e1,e2;
        for(int i=0;i<n;i++)
        {
            if(c1==0&&nums[i]!=e2)
            {
                c1++;
                e1=nums[i];
            }
           else if(c2==0&&nums[i]!=e1)
            {
                c2++;
                e2=nums[i];
            }
           else if(nums[i]==e1)
                c1++;
           else if(nums[i]==e2)
                c2++;
            else
            {
                c1--;
                c2--;
            }
        }
        int min=(int)n/3+1;
        int a1=0;
        int a2=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==e1)
                a1++;
            if(nums[i]==e2)
                a2++;
        }
        if(a1>=min)
            ans.push_back(e1);
        if(a2>=min)
            ans.push_back(e2);
        return ans;
    }
};