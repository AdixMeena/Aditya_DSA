class Solution:
    def shortestBeautifulSubstring(self, s: str, k: int) -> str:
        """
        Find the shortest substring containing exactly k ones.
        If multiple exist with same length, return the lexicographically smallest.
      
        Args:
            s: Binary string containing only '0' and '1'
            k: Target number of '1's in the substring
      
        Returns:
            Shortest beautiful substring or empty string if none exists
        """
        n = len(s)
        result = ""
      
        # Try all possible starting positions
        for start in range(n):
            # Try all possible ending positions (minimum length k to contain k ones)
            for end in range(start + k, n + 1):
                # Extract current substring
                current_substring = s[start:end]
              
                # Check if current substring has exactly k ones
                if current_substring.count("1") == k:
                    # Update result if:
                    # 1. Result is empty (first valid substring found)
                    # 2. Current substring is shorter than result
                    # 3. Same length but lexicographically smaller
                    if (not result or 
                        end - start < len(result) or 
                        (end - start == len(result) and current_substring < result)):
                        result = current_substring
      
        return result
