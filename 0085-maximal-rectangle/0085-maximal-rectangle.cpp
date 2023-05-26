class Solution {
public:
         vector<int> nextSmaller(vector<int> &arr,int n){
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for(int i=arr.size()-1;i>=0;i--){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int> &arr,int n){
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);
        for(int i=0;i<arr.size();i++){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int maxAreaHistogram(vector<int> &arr){
        int n = arr.size();
        vector<int> next(n);
        vector<int> prev(n);
        next = nextSmaller(arr,n);
        prev = prevSmaller(arr,n);
        int area = 0;
        for(int i=0;i<arr.size();i++){
            int length = arr[i];
            if(next[i]==-1){
                next[i]=n;
            }
            int width = next[i]-prev[i]-1;
            area = max(area,(length*width));
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        ios_base::sync_with_stdio(false);
        vector<vector<int>> mat;
        for(int i=0;i<matrix.size();i++){
            vector<int> v;
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]=='1'){
                    v.push_back(1);
                }
                else{
                    v.push_back(0);
                }
            }
            mat.push_back(v);
        }
        int n = mat.size();
        int area = maxAreaHistogram(mat[0]);
        for(int i=1;i<n;i++){
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]!=0){
                    mat[i][j]+=mat[i-1][j];
                }
            }
            area=max(area,maxAreaHistogram(mat[i]));
        }
        return area;
    }

   
};