
class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> prefix(n+1, 0);

        // Step 1: Transform array into +1 (target) / -1 (non-target)
        for (int i = 0; i < n; i++) {
            int val = (nums[i] == target ? 1 : -1);
            prefix[i+1] = prefix[i] + val;
        }

        // Step 2: Coordinate compression of prefix sums
        vector<long long> all = prefix;
        sort(all.begin(), all.end());
        all.erase(unique(all.begin(), all.end()), all.end());

        auto getIndex = [&](long long x) {
            return (int)(lower_bound(all.begin(), all.end(), x) - all.begin()) + 1;
        };

        // Step 3: Fenwick Tree (BIT) for counting
        vector<long long> BIT(all.size()+2, 0);
        auto update = [&](int idx) {
            for (; idx < BIT.size(); idx += idx & -idx) BIT[idx]++;
        };
        auto query = [&](int idx) {
            long long sum = 0;
            for (; idx > 0; idx -= idx & -idx) sum += BIT[idx];
            return sum;
        };

        // Step 4: Count valid subarrays
        long long ans = 0;
        for (int j = 0; j <= n; j++) {
            int idx = getIndex(prefix[j]);
            // count how many previous prefix < current
            ans += query(idx-1);
            update(idx);
        }

        return ans;
    }
};
