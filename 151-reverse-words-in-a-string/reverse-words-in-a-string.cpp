class Solution {
public:
    string reverseWords(string input) {
        stringstream inputStream(input);
        string reversedString;
        string word;

        // Iterate through each word in reverse order
        while (inputStream >> word) {
            // Append the word to the beginning of the result string
            if (!reversedString.empty()) {
                reversedString = word + " " + reversedString;
            } else {
                reversedString = word;
            }
        }

        return reversedString;
    }
};
