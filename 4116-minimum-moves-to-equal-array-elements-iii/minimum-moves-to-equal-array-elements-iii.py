class Solution:
    def minMoves(self, nums: list[int]) -> int:

        check = 0
        for num in nums:
            if check < num:
                check = num

        steps = 0
        for num in nums:
            steps += (check - num)

        return steps
            
            