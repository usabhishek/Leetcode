class Solution:
    def minMoves2(self, nums: list[int]) -> int:
        nums.sort()

        n = len(nums)
        median = nums[n // 2]

        res = 0

        for num in nums:
            res += abs(median - num)

        return res
