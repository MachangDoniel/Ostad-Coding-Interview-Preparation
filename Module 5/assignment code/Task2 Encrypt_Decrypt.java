public class EncryptDecrypt {

    public static String encrypt(String s) {
        StringBuilder result = new StringBuilder();
        int n = s.length();
        int i = 0;

        // Step 1: Iterate through the string to count consecutive identical characters
        while (i < n) {
            int count = 1;
            char charAtI = s.charAt(i);

            // Step 2: Count consecutive occurrences of the same character
            while (i + 1 < n && s.charAt(i) == s.charAt(i + 1)) {
                count++;
                i++;
            }

            // Step 3: Append the character and its frequency
            result.append(count).append(charAtI);
            i++;
        }

        // Step 4: Reverse the transformed string and return
        return result.reverse().toString();
    }

    public static String decrypt(String encrypted) {
        StringBuilder result = new StringBuilder();
        int n = encrypted.length();
        int i = 0;

        // Step 1: Reverse the encrypted string to get the original transformed string
        encrypted = new StringBuilder(encrypted).reverse().toString();

        // Step 2: Iterate through the reversed string to extract counts and characters
        while (i < n) {
            // Extract the count
            StringBuilder countStr = new StringBuilder();
            while (i < n && Character.isDigit(encrypted.charAt(i))) {
                countStr.append(encrypted.charAt(i));
                i++;
            }

            // Convert the count to integer
            int count = Integer.parseInt(countStr.toString());

            // The next character is the one that occurred 'count' times
            result.append(String.valueOf(encrypted.charAt(i)).repeat(count));
            i++;
        }

        return result.toString();
    }

    public static void main(String[] args) {
        String input1 = "aaaaaaaaaaa";
        String input2 = "ostad";

        // Encrypt the strings
        String encrypted1 = encrypt(input1);
        String encrypted2 = encrypt(input2);

        // Print encrypted outputs
        System.out.println("Encrypted '" + input1 + "': " + encrypted1);
        System.out.println("Encrypted '" + input2 + "': " + encrypted2);

        // Decrypt the strings
        String decrypted1 = decrypt(encrypted1);
        String decrypted2 = decrypt(encrypted2);

        // Print decrypted outputs
        System.out.println("Decrypted '" + encrypted1 + "': " + decrypted1);
        System.out.println("Decrypted '" + encrypted2 + "': " + decrypted2);

        // Check if the decrypted strings match the originals
        System.out.println("Decryption matches original for '" + input1 + "': " + (decrypted1.equals(input1) ? "True" : "False"));
        System.out.println("Decryption matches original for '" + input2 + "': " + (decrypted2.equals(input2) ? "True" : "False"));
    }
}
