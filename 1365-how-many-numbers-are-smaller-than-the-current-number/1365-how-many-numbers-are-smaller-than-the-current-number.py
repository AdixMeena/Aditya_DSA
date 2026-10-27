class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        n = len(nums)

        ans = [0] * n

        for i in range(n):
            for j in range(n):
                if nums[i] > nums[j]:
                    ans[i] += 1
                else:
                    pass

        return ans
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        