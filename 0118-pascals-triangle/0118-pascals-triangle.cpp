class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      int n=numRows;
      vector<vector<int>>result;
      for(int i=1;i<=n;i++)
      {
          vector<int>temp;
          temp.push_back(1);
          int ans=1;
          for(int col=1;col<i;col++)
          {
              ans*=i-col;
              ans/=col;
              temp.push_back(ans);

          }
          result.push_back(temp);

      } 
      return result;
    }
};