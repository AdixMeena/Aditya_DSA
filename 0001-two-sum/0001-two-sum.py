class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        ans = {}

        for i in range(len(nums)):
            need = target - nums[i]
            if need in ans:
                return [i, ans[need]]
            ans.update({nums[i]: i})
        return []