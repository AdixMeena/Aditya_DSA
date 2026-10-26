class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        merged = sorted(nums1 + nums2)
        n = len(merged)
        mid = n // 2

        if n % 2 == 0:
            return (merged[mid - 1] + merged[mid]) / 2.0
        return float(merged[mid])