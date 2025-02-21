#include <stdio.h>
#include <string.h>

void k_Ostad(char s1[], char s2[], int k) {
    // Frequency arrays for both strings (26 lowercase English letters)
    int mp1[26] = {0};
    int mp2[26] = {0};

    // Count character frequencies for s1
    for (int i = 0; s1[i] != '\0'; i++) {
        mp1[s1[i] - 'a']++;
    }

    // Count character frequencies for s2
    for (int i = 0; s2[i] != '\0'; i++) {
        mp2[s2[i] - 'a']++;
    }

    // Count excess characters in both strings
    int s1HasS2DoesntHave = 0, s2HasS1DoesntHave = 0;
    for (int i = 0; i < 26; i++) {
        if (mp1[i] > mp2[i]) s1HasS2DoesntHave += mp1[i] - mp2[i];
        if (mp2[i] > mp1[i]) s2HasS1DoesntHave += mp2[i] - mp1[i];
    }

    // Minimum operations needed to make both strings equal
    int need = (s1HasS2DoesntHave > s2HasS1DoesntHave) ? s1HasS2DoesntHave : s2HasS1DoesntHave;

    // 1. min(s1HasS2DoesntHave, s2HasS1DoesntHave) times swap
    // 2. max(s1HasS2DoesntHave, s2HasS1DoesntHave) - min(s1HasS2DoesntHave, s2HasS1DoesntHave) times insert/delete

    if (need <= k) printf("Yes\n");
    else printf("No\n");
}

int main() {
    // char s1[101], s2[101];
    // int k;
    // scanf("%s %s %d", s1, s2, &k);
    // k_Ostad(s1, s2, k);
    k_Ostad("ostad", "boss", 1);        // No
    k_Ostad("anagram", "grammar", 2);   // Yes
    k_Ostad("aabcz", "abcdeyy", 3);     // No
    k_Ostad("aabcz", "abcdeyy", 4);     // Yes
    return 0;
}
