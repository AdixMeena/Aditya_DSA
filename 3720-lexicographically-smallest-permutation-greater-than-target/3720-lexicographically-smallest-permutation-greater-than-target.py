class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        n = len(s)
        cnt = [0] * 26
        for ch in s:
            cnt[ord(ch) - 97] += 1

        remaining = cnt[:]
        best_i, best_char = -1, -1

        for i in range(n):
            t = ord(target[i]) - 97
            # look for the smallest available letter strictly greater than target[i]
            for c in range(t + 1, 26):
                if remaining[c] > 0:
                    best_i, best_char = i, c
                    break
            # try to consume target[i] to keep matching the prefix
            if remaining[t] == 0:
                break
            remaining[t] -= 1

        if best_i == -1:
            return ""

        # rebuild the multiset state at position best_i
        rem = cnt[:]
        for j in range(best_i):
            rem[ord(target[j]) - 97] -= 1
        rem[best_char] -= 1

        suffix = ''.join(chr(c + 97) * rem[c] for c in range(26))
        return target[:best_i] + chr(best_char + 97) + suffix