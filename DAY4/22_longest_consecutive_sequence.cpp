/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Follow up: Could you implement the O(n) solution? 

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

 

Constraints:

    0 <= nums.length <= 104
    -109 <= nums[i] <= 109

*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashset;
        for(int num:nums)
            hashset.insert(num);
        
        int largestStreak=0;
        for(int num:nums){
            if(!hashset.count(num-1)){
                int currentNum = num;
                int currentStreak = 1;
                
                while(hashset.count(currentNum+1)){
                    currentStreak += 1;
                    currentNum += 1;
                }
                largestStreak = max(largestStreak, currentStreak);
            }
        }
        return largestStreak;
    }
};
