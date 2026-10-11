class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxi=nums[0];
        int mini=nums[0];
        int ans =nums[0];

        

        for (int i =1;i<nums.size();i++){
            int x = nums[i];
            int oldmin = mini*x;
            int oldmax = maxi*x;
            maxi=max({x, oldmax, oldmin});
            mini=min({x, oldmin, oldmax});
            ans=max(ans,max(maxi,mini ));
        }
        return ans ;
        
    }
};