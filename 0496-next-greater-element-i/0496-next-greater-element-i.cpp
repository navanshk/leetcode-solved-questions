class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       unordered_map<int,int>mp;
        vector<int>ans;
        int n=nums2.size();
        stack<int>s;
        for(int i=n-1;i>=0;i--)
        {   int ele=nums2[i];
            while(!s.empty()&&s.top()<=ele)
            {
                s.pop();
                
            }
            int res=(s.empty())?-1:s.top();
           mp[ele]=res;
         s.push(ele);
        }
        for(auto i:nums1)
        {
            ans.push_back(mp[i]);
        }
        return ans;
    }
};