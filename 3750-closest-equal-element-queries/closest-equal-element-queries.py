from collections import defaultdict
from bisect import bisect_left

class Solution:
    def solveQueries(self, nums, queries):
        # store indices of each value
        pos = defaultdict(list)
        
        for i, v in enumerate(nums):
            pos[v].append(i)
        
        n = len(nums)
        best = [-1] * n
        
        # compute nearest equal distance for each index
        for v, arr in pos.items():
            m = len(arr)
            if m == 1:
                continue
            
            for i in range(m):
                idx = arr[i]
                
                # circular neighbors in sorted list
                left = arr[i - 1]
                right = arr[(i + 1) % m]
                
                best[idx] = min(
                    abs(idx - left),
                    abs(idx - right),
                    n - abs(idx - left),   # if circular considered
                    n - abs(idx - right)
                )
        
        # answer queries
        return [best[q] for q in queries]