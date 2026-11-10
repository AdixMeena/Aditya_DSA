class Solution:
    def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
        low = 0
        high = (len(matrix) * len(matrix[0]))-1
        m = len(matrix[0])
        

        while(low <= high): 
            mid = (low + high) // 2
            row = mid // m
            col = mid % m

            if matrix[row][col] == target:
                return True
            elif matrix[row][col] > target:
                high = mid-1
            else:
                low = mid+1
        return False     