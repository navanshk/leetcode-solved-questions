class Solution {
public:
    void f(int i,int t,vector<int>&arr,  vector<vector<int>>&ans,vector<int>&ds)
    {    int n=arr.size();
        if(i==n)
        {
            if(t==0)
                ans.push_back(ds);
            return ;
        }
        if(arr[i]<=t)
        {
            ds.push_back(arr[i]);
            f(i,t-arr[i],arr,ans,ds);
            ds.pop_back();
        }
        f(i+1,t,arr,ans,ds);
    }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>ds;
        f(0,target,candidates,ans,ds);
        return ans;
    }
};