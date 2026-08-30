class Solution:
    def minimumDeletions(self, nums: list[int]) -> int:
        n = len(nums)
        i_min = nums.index(min(nums))
        i_max = nums.index(max(nums))
        
        # Ensure i_min is the smaller index and i_max is the larger index
        if i_min > i_max:
            i_min, i_max = i_max, i_min
            
        # Three possible deletion strategies
        delete_from_front = i_max + 1
        delete_from_back = n - i_min
        delete_from_both = (i_min + 1) + (n - i_max)
        
        return min(delete_from_front, delete_from_back, delete_from_both)
