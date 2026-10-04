class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int currentMax = nums[0];
        int currentMin = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            int x = nums[i];

            int oldMax = currentMax;
            int oldMin = currentMin;

            currentMax = max({x, oldMax * x, oldMin * x});

            currentMin = min({x, oldMax * x, oldMin * x});

            ans = max(ans, currentMax);
        }

        return ans;
    }
};