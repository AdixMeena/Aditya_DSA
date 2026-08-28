class Solution:
    def lexPalindromicPermutation(self, s: str, target: str) -> str:
        n = len(s)
        cnt = [0] * 26
        for ch in s:
            cnt[ord(ch) - 97] += 1

        odd_chars = [c for c in range(26) if cnt[c] % 2]
        if (n % 2 == 0 and odd_chars) or (n % 2 == 1 and len(odd_chars) != 1):
            return ""  # no palindromic permutation exists at all

        mid_char = odd_chars[0] if n % 2 == 1 else -1
        half_cnt = [cnt[c] // 2 for c in range(26)]
        h = n // 2

        # ---- Case 1: try exact prefix match (target[:h] uses half_cnt exactly) ----
        prefix_cnt = [0] * 26
        for ch in target[:h]:
            prefix_cnt[ord(ch) - 97] += 1

        if prefix_cnt == half_cnt:
            first_half = target[:h]
            mid = chr(mid_char + 97) if mid_char != -1 else ""
            candidate = first_half + mid + first_half[::-1]
            if candidate > target:
                return candidate

        # ---- Case 2: diverge within the first half ----
        remaining = half_cnt[:]
        best_i, best_char = -1, -1

        for i in range(h):
            t = ord(target[i]) - 97
            for c in range(t + 1, 26):
                if remaining[c] > 0:
                    best_i, best_char = i, c
                    break
            if remaining[t] == 0:
                break
            remaining[t] -= 1

        if best_i == -1:
            return ""

        rem = half_cnt[:]
        for j in range(best_i):
            rem[ord(target[j]) - 97] -= 1
        rem[best_char] -= 1

        suffix = ''.join(chr(c + 97) * rem[c] for c in range(26))
        first_half = target[:best_i] + chr(best_char + 97) + suffix
        mid = chr(mid_char + 97) if mid_char != -1 else ""
        return first_half + mid + first_half[::-1]