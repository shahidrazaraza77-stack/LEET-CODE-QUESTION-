class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Special handling for 1
        if (freq.count(1)) {
            if (freq[1] % 2)
                ans = max(ans, freq[1]);
            else
                ans = max(ans, freq[1] - 1);
        }

        for (auto &[start, cnt] : freq) {
            if (start == 1) continue;

            long long cur = start;
            int len = 0;

            while (true) {
                if (!freq.count(cur)) break;

                // If current number has only one copy,
                // it must be the center.
                if (freq[cur] == 1) {
                    len++;
                    break;
                }

                // Need next square to continue the chain.
                if (cur > 1000000000LL / cur ||
                    !freq.count(cur * cur)) {
                    len++;
                    break;
                }

                len += 2;
                cur = cur * cur;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};