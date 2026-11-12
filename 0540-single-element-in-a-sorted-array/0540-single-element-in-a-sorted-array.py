class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        low = 0
        high = len(nums)

        if high == 1: return nums[0]
        if nums[0] != nums[1]: return nums[0]
        if nums[high-1] != nums[high-2]: return nums[high-1]

        high -= 2
        low += 1

        while low <= high:
            mid = (low + high)//2

            if nums[mid -1] != nums[mid] != nums[mid+1]:
                return nums[mid]
            elif mid % 2 == 1 and nums[mid] == nums[mid-1] or mid % 2 == 0 and nums[mid] == nums[mid+1]:
                low = mid+1
            else:
                high = mid-1
        return -1
        