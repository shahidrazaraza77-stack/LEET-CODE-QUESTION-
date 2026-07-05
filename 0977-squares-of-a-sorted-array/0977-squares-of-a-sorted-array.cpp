class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        int i = 0;
        int j = nums.size() - 1;

        vector<int> ans(nums.size());

        int k = nums.size() - 1;

      

        while (i <= j) {
            int left=nums[i]*nums[i];
            int right =nums[j]*nums[j];


            if (left > right) {
                ans[k] = left;
                i++;
            }
            else {
                ans[k] =right;
                j--;
            }

            k--;
        }

        return ans;
    }
};