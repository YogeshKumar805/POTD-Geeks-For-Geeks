class Solution:
    def countBalanced(self, arr):
        def is_vowel(ch):
            return ch in 'aeiou'

        prefix_diff_count = {0: 1}
        total = 0
        vowel_count = consonant_count = 0

        for word in arr:
            for ch in word:
                if is_vowel(ch):
                    vowel_count += 1
                else:
                    consonant_count += 1

            diff = vowel_count - consonant_count
            total += prefix_diff_count.get(diff, 0)
            prefix_diff_count[diff] = prefix_diff_count.get(diff, 0) + 1

        return total
