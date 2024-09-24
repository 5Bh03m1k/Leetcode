class Solution:
    def longestCommonPrefix(self, arr1: List[int], arr2: List[int]) -> int:
        def prefix(a, b):
            a, b = str(a), str(b)
            length = min(len(a), len(b))
            for i in range(length):
                if a[i] != b[i]:
                    return i  
            return length  
        result = 0
        d1 = sorted(map(str, set(arr1)))
        d2 = sorted(map(str, set(arr2)))
        i = j = 0
        while i < len(d1) and j < len(d2):
            result = max(result, prefix(d1[i], d2[j]))
            if d1[i] < d2[j]:
                i += 1
            else:
                j += 1
        return result