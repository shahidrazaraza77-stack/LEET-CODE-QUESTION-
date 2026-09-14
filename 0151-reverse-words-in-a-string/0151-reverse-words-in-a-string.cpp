class Solution {
public:
    string reverseWords(string s) {

        int n = s.length();
        string ans = "";

        // Step 1: Reverse the complete string
        reverse(s.begin(), s.end());

        for (int i = 0; i < n; i++) {
            string word = "";

            // Step 2: Extract one word
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Step 3: Reverse the extracted word
            reverse(word.begin(), word.end());

            // Step 4: Add the word to answer
            if (word.length() > 0) {
                ans += " " + word;
            }
        }

        // Step 5: Remove the first extra space
        return ans.substr(1);
    }
};