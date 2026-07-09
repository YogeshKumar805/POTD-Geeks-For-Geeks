class Solution:
    def countKdivPairs(self, arr, k):
        freq = [0] * k
        count = 0

        for num in arr:
            rem = num % k

            if rem == 0:
                count += freq[0]
            else:
                count += freq[k - rem]

            freq[rem] += 1

        return count

