class Solution {
public:
    int fib(int n) {
        int pre2=0;
        if(n==0)
            return 0;
        int pre1=1;
        for(int i=2;i<=n;i++)
        {
            int cur=pre1+pre2;
            pre2=pre1;
            pre1=cur;
        }
        return pre1;
    }
};