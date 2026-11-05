class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        res = 0

        for x in arr1:
            for i, y in enumerate(arr2):
                if abs(x - y) <= d:
                    break
                
                if i == len(arr2) - 1:
                    res += 1
                
        
        return res

                