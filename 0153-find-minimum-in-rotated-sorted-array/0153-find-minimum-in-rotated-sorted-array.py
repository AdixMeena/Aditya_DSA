class Solution:
    def findMin(self, nums: list[int]) -> int:
        low = 0
        high = len(nums)-1
        ans = inf
        while low <= high:
            mid = (low+high)//2

            if nums[low] <= nums[mid]:  #left is sorted part 
                ans =  min(nums[low], ans)
                low = mid+1


            else:# right is then
                ans =  min(nums[mid], ans)
                high = mid-1
        return ans


        