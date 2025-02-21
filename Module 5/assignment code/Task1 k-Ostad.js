function k_Ostad(s1, s2, k) {
    // Frequency maps for both strings
    let mp1 = new Map();
    let mp2 = new Map();

    // Count character frequencies for s1
    for (let c of s1) {
        mp1.set(c, (mp1.get(c) || 0) + 1);
    }
    // Count character frequencies for s2
    for (let c of s2) {
        mp2.set(c, (mp2.get(c) || 0) + 1);
    }

    // Count excess characters in both strings
    let s1HasS2DoesntHave = 0;
    let s2HasS1DoesntHave = 0;
    for (let ch = "a".charCodeAt(0); ch <= "z".charCodeAt(0); ch++) {
        let char = String.fromCharCode(ch);
        let freq1 = mp1.get(char) || 0;
        let freq2 = mp2.get(char) || 0;
        if (freq1 > freq2) s1HasS2DoesntHave += freq1 - freq2;
        if (freq2 > freq1) s2HasS1DoesntHave += freq2 - freq1;
    }

    // Minimum operations needed to make both strings equal
    let need = Math.max(s1HasS2DoesntHave, s2HasS1DoesntHave);

    // 1. min(s1HasS2DoesntHave, s2HasS1DoesntHave) times swap
    // 2. max(s1HasS2DoesntHave, s2HasS1DoesntHave) - min(s1HasS2DoesntHave, s2HasS1DoesntHave) times insert/delete

    if (need <= k) console.log("Yes");
    else console.log("No");
}

// Sample test cases
// let s1 = prompt();
// let s2 = prompt();
// let k = parseInt(prompt());
// k_Ostad(s1, s2, k);
k_Ostad("ostad", "boss", 1);        // No
k_Ostad("anagram", "grammar", 2);   // Yes
k_Ostad("aabcz", "abcdeyy", 3);     // No
k_Ostad("aabcz", "abcdeyy", 4);     // Yes
