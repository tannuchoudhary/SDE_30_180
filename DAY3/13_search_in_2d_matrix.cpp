/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.
*/


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(!matrix.size()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int lo = 0;
        int hi = m*n -1;
        
        while(lo <= hi){
            int mid = (lo + (hi-lo)/2);
            if(matrix[mid/n][mid%n] == target)
                return true;
            else if(matrix[mid/n][mid%n] < target)
                lo = mid+1;
            else
                hi = mid-1;
            
           
            
        }
        return false;
        
    }
};
