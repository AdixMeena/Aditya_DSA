from math import gcd
from typing import List

class Solution:
    def gcdSum(self, nums: List[int]) -> int:
        n = len(nums)
        prefix_gcd = []
        cur_max = 0
        for x in nums:
            cur_max = max(cur_max, x)
            prefix_gcd.append(gcd(x, cur_max))
        
        prefix_gcd.sort()
        
        total = 0
        left, right = 0, n - 1
        while left < right:
            total += gcd(prefix_gcd[left], prefix_gcd[right])
            left += 1
            right -= 1
        
        return total