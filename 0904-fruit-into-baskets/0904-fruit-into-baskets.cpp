class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int left = 0;
        int ans = 0;

        unordered_map<int, int> mp;

        for (int right = 0; right < fruits.size(); right++) {

            // Add current fruit
            mp[fruits[right]]++;

            // More than 2 types of fruits
            while (mp.size() > 2) {

                mp[fruits[left]]--;

                // Remove fruit type if its frequency becomes 0
                if (mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }

                left++;
            }

            // Current window is valid
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};