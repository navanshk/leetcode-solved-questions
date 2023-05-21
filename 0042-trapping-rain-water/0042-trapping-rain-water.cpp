class Solution {
public:
    int trap(vector<int>& height) {
     int l=0;
        
        
        int n=height.size();
        int r=n-1;
        
        int res=0;
        int ml=0;
        int mr=0;
        while(l<=r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>=ml)
                    ml=height[l];
                else 
                    res+=ml-height[l];
                l++;
            }
            else
            {
                if(height[r]>=mr)
                    mr=height[r];
                else 
                    res+=mr-height[r];
                r--;
            }
        }
        return res;
    }
};