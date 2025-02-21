#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encrypt(char *s, char *result) {
    int n = strlen(s);
    int i = 0;
    int result_idx = 0;

    // Step 1: Iterate through the string to count consecutive identical characters
    while (i < n) {
        int count = 1;
        char current_char = s[i];

        // Step 2: Count consecutive occurrences of the same character
        while (i + 1 < n && s[i] == s[i + 1]) {
            count++;
            i++;
        }

        // Step 3: Append the count and character to result
        result_idx += sprintf(result + result_idx, "%d%c", count, current_char);
        i++;
    }

    // Step 4: Reverse the result string
    int len = strlen(result);
    for (int j = 0; j < len / 2; j++) {
        char temp = result[j];
        result[j] = result[len - 1 - j];
        result[len - 1 - j] = temp;
    }
}

void decrypt(char *encrypted, char *result) {
    int n = strlen(encrypted);
    int i = 0;
    int result_idx = 0;

    // Step 1: Reverse the encrypted string to get the original transformed string
    for (int j = 0; j < n / 2; j++) {
        char temp = encrypted[j];
        encrypted[j] = encrypted[n - 1 - j];
        encrypted[n - 1 - j] = temp;
    }

    // Step 2: Extract counts and characters from the reversed string
    while (i < n) {
        int count = 0;
        while (i < n && encrypted[i] >= '0' && encrypted[i] <= '9') {
            count = count * 10 + (encrypted[i] - '0');
            i++;
        }

        // Append the character the specified number of times
        for (int j = 0; j < count; j++) {
            result[result_idx++] = encrypted[i];
        }
        i++;
    }

    result[result_idx] = '\0';
}

int main() {
    char input1[] = "aaaaaaaaaaa";
    char input2[] = "ostad";

    char encrypted1[100], encrypted2[100], decrypted1[100], decrypted
    char decrypted1[100], decrypted2[100];

    // Encrypt the strings
    encrypt(input1, encrypted1);
    encrypt(input2, encrypted2);

    // Print encrypted outputs
    printf("Encrypted '%s': %s\n", input1, encrypted1);
    printf("Encrypted '%s': %s\n", input2, encrypted2);

    // Decrypt the strings
    decrypt(encrypted1, decrypted1);
    decrypt(encrypted2, decrypted2);

    // Print decrypted outputs
    printf("Decrypted '%s': %s\n", encrypted1, decrypted1);
    printf("Decrypted '%s': %s\n", encrypted2, decrypted2);

    // Check if the decrypted strings match the originals
    printf("Decryption matches original for '%s': %s\n", input1, (strcmp(decrypted1, input1) == 0 ? "True" : "False"));
    printf("Decryption matches original for '%s': %s\n", input2, (strcmp(decrypted2, input2) == 0 ? "True" : "False"));

    return 0;
}
