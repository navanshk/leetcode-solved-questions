class Solution {
public:
    int majorityElement(vector<int>& nums) {
    
    int n=nums.size();
        int c=0;
        int element;
        for(int i=0;i<n;i++)
        {
            if(c==0)
            {
                c++;
                element=nums[i];
            }
            else if(nums[i]==element)
                c++;
            else
                c--;
        }
        return element;
    }
};