class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
          int n = matrix.size();
          int m = matrix[0].size();
          int low=0,high=m-1,row=-1;
          for(int i=0;i<n;i++)
          {
             if(matrix[i][0]<=target)
             {
                row=i;
                if(matrix[i][0]==target)return true;
             }
             else break;
          }
          if(row==-1)return false;
          while(low<=high)
          {
            int mid = low +(high-low)/2;
            if(matrix[row][mid]==target)return true;
            else if(matrix[row][mid]<target)low = mid+1;
            else high = mid-1;
          }
          return false;
          
    }
};
