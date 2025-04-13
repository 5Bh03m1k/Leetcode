mod = 1000000007
class Solution:
    def countGoodNumbers(self, n: int) -> int:
        return (pow( 4 , n//2 , mod) * pow( 5 , (n//2+n%2) , mod) ) % mod
        