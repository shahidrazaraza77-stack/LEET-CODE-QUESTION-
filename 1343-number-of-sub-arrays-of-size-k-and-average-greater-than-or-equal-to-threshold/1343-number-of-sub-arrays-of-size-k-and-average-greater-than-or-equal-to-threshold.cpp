class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {

        int left = 0;
        int sum = 0;
        int ans = 0;

        for (int right = 0; right < arr.size(); right++) {

            // Add current element
            sum += arr[right];

            // Window size becomes k
            if (right - left + 1 == k) {

                // Check average >= threshold
                if (sum >= threshold * k) {
                    ans++;
                }

                // Remove left element
                sum -= arr[left];
                left++;
            }
        }

        return ans;
    }
};