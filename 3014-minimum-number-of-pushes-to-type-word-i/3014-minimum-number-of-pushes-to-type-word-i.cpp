class Solution {
public:
    int minimumPushes(string word) {
        // Get the total number of characters in the word
        int wordLength = word.size();
      
        // Initialize the total number of pushes required
        int totalPushes = 0;
      
        // Initialize the current push count per character
        // (increases after every 8 characters are assigned)
        int pushesPerChar = 1;
      
        // Process complete groups of 8 characters
        // Each group uses all 8 available keys
        int completeGroups = wordLength / 8;
        for (int groupIndex = 0; groupIndex < completeGroups; ++groupIndex) {
            // Add pushes for this group (8 characters * current push count)
            totalPushes += pushesPerChar * 8;
          
            // Increment push count for the next group
            ++pushesPerChar;
        }
      
        // Process the remaining characters (less than 8)
        int remainingChars = wordLength % 8;
        totalPushes += pushesPerChar * remainingChars;
      
        return totalPushes;
    }
};