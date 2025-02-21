def k_Ostad(s1, s2, k):
    # Frequency maps for both strings
    mp1 = {}
    mp2 = {}

    # Count character frequencies for s1
    for c in s1:
        mp1[c] = mp1.get(c, 0) + 1

    # Count character frequencies for s2
    for c in s2:
        mp2[c] = mp2.get(c, 0) + 1

    # Count excess characters in both strings
    s1HasS2DoesntHave = 0
    s2HasS1DoesntHave = 0
    for ch in range(ord('a'), ord('z') + 1):
        freq1 = mp1.get(chr(ch), 0)
        freq2 = mp2.get(chr(ch), 0)
        if freq1 > freq2:
            s1HasS2DoesntHave += freq1 - freq2
        if freq2 > freq1:
            s2HasS1DoesntHave += freq2 - freq1

    # Minimum operations needed to make both strings equal
    need = max(s1HasS2DoesntHave, s2HasS1DoesntHave)

    # 1. min(s1HasS2DoesntHave, s2HasS1DoesntHave) times swap
    # 2. max(s1HasS2DoesntHave, s2HasS1DoesntHave) - min(s1HasS2DoesntHave, s2HasS1DoesntHave) times insert/delete

    if need <= k:
        print("Yes")
    else:
        print("No")


if __name__ == "__main__":
    # s1 = input()
    # s2 = input()
    # k = int(input())
    # k_Ostad(s1, s2, k)
    k_Ostad("ostad", "boss", 1)        # No
    k_Ostad("anagram", "grammar", 2)   # Yes
    k_Ostad("aabcz", "abcdeyy", 3)     # No
    k_Ostad("aabcz", "abcdeyy", 4)     # Yes
