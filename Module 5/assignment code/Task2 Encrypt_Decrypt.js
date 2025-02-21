function encrypt(s) {
    let result = '';
    let i = 0;
    
    // Step 1: Iterate through the string to count consecutive identical characters
    while (i < s.length) {
        let count = 1;
        let charAtI = s[i];
        
        // Step 2: Count consecutive occurrences of the same character
        while (i + 1 < s.length && s[i] === s[i + 1]) {
            count++;
            i++;
        }
        
        // Step 3: Append the character and its frequency
        result += count + charAtI;
        i++;
    }
    
    // Step 4: Reverse the transformed string and return
    return result.split('').reverse().join('');
}

function decrypt(encrypted) {
    let result = '';
    let i = 0;
    
    // Step 1: Reverse the encrypted string to get the original transformed string
    encrypted = encrypted.split('').reverse().join('');
    
    // Step 2: Iterate through the reversed string to extract counts and characters
    while (i < encrypted.length) {
        let countStr = '';
        
        // Extract the count
        while (i < encrypted.length && !isNaN(encrypted[i])) {
            countStr += encrypted[i];
            i++;
        }
        
        // Convert the count to integer
        let count = parseInt(countStr);
        
        // The next character is the one that occurred 'count' times
        result += encrypted[i].repeat(count);
        i++;
    }
    
    return result;
}

// Sample Test Cases
let input1 = "aaaaaaaaaaa";
let input2 = "ostad";

let encrypted1 = encrypt(input1);
let encrypted2 = encrypt(input2);

console.log("Encrypted '" + input1 + "': " + encrypted1);
console.log("Encrypted '" + input2 + "': " + encrypted2);

let decrypted1 = decrypt(encrypted1);
let decrypted2 = decrypt(encrypted2);

console.log("Decrypted '" + encrypted1 + "': " + decrypted1);
console.log("Decrypted '" + encrypted2 + "': " + decrypted2);

console.log("Decryption matches original for '" + input1 + "': " + (decrypted1 === input1 ? "True" : "False"));
console.log("Decryption matches original for '" + input2 + "': " + (decrypted2 === input2 ? "True" : "False"));
