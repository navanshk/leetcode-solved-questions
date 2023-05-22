class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>l(n+1,1);
        vector<int>r(n+1,1);
        int sum=0;
        for(int i=1;i<n;i++)
        {
            if(ratings[i]>ratings[i-1])
                l[i]=l[i-1]+1;
        }
        for(int j=n-2;j>=0;j--)
        {
            if(ratings[j]>ratings[j+1])
                r[j]=r[j+1]+1;
        }
        for(int i=0;i<n;i++)
        {
            sum+=max(l[i],r[i]);
        }
        return sum;
    }
};