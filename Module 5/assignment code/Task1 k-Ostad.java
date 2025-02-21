import java.util.*;

public class Main {
    static void k_Ostad(String s1, String s2, int k) {
        // Frequency maps for both strings
        Map<Character, Integer> mp1 = new HashMap<>();
        Map<Character, Integer> mp2 = new HashMap<>();

        // Count character frequencies for s1
        for (char c : s1.toCharArray()) {
            mp1.put(c, mp1.getOrDefault(c, 0) + 1);
        }
        // Count character frequencies for s2
        for (char c : s2.toCharArray()) {
            mp2.put(c, mp2.getOrDefault(c, 0) + 1);
        }

        // Count excess characters in both strings
        int s1HasS2DoesntHave = 0, s2HasS1DoesntHave = 0;
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int freq1 = mp1.getOrDefault(ch, 0);
            int freq2 = mp2.getOrDefault(ch, 0);
            if (freq1 > freq2) s1HasS2DoesntHave += freq1 - freq2;
            if (freq2 > freq1) s2HasS1DoesntHave += freq2 - freq1;
        }

        // Minimum operations needed to make both strings equal
        int need = Math.max(s1HasS2DoesntHave, s2HasS1DoesntHave);

        // 1. min(s1HasS2DoesntHave, s2HasS1DoesntHave) times swap
        // 2. max(s1HasS2DoesntHave, s2HasS1DoesntHave) - min(s1HasS2DoesntHave, s2HasS1DoesntHave) times insert/delete

        if (need <= k) System.out.println("Yes");
        else System.out.println("No");
    }

    public static void main(String[] args) {
        // Scanner sc = new Scanner(System.in);
        // String s1= sc.next();
        // String s2 = sc.next();
        // int k = sc.nextInt();
        // k_Ostad(s1, s2, k);
        k_Ostad("ostad", "boss", 1);        // No
        k_Ostad("anagram", "grammar", 2);   // Yes
        k_Ostad("aabcz", "abcdeyy", 3);     // No
        k_Ostad("aabcz", "abcdeyy", 4);     // Yes
    }
}
