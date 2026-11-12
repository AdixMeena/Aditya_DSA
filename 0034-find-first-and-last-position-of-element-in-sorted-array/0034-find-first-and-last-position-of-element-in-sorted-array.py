class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        low = 0
        high = len(nums)-1
        lower = -1
        greter = -1
        while low <= high:
            mid = (low+high)// 2
            if nums[mid] >= target:
                lower = mid
                high = mid-1
            else:
                low = mid+1

        if lower == -1 or nums[lower] != target:
            return [-1, -1]

        low = 0
        high = len(nums)-1     
        while low <= high:
            mid = (low+high)// 2
            if nums[mid] <= target:
                greter = mid
                low = mid+1
            else:
                high = mid-1

        return [lower,greter]
        

