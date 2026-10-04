class Solution:
    def ifGreaterSwap(self, a: list[int], i: int, b: list[int], j: int) -> None:
        if a[i] > b[j]:
            a[i], b[j] = b[j], a[i]

    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        total = m + n
        gap = total // 2 + total % 2   # ceil(total / 2)

        while gap > 0:
            left = 0
            right = left + gap

            while right < total:
                if left < m and right >= m:
                    # left in nums1, right in nums2
                    self.ifGreaterSwap(nums1, left, nums2, right - m)
                elif left >= m:
                    # both in nums2
                    self.ifGreaterSwap(nums2, left - m, nums2, right - m)
                else:
                    # both in nums1
                    self.ifGreaterSwap(nums1, left, nums1, right)
                left += 1
                right += 1

            if gap == 1:
                break
            gap = gap // 2 + gap % 2

        # copy sorted nums2 into the tail of nums1
        for k in range(n):
            nums1[m + k] = nums2[k]