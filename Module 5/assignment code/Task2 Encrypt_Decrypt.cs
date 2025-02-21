using System;

public class EncryptDecrypt
{
    public static string Encrypt(string s)
    {
        string result = "";
        int i = 0;

        // Step 1: Iterate through the string to count consecutive identical characters
        while (i < s.Length)
        {
            int count = 1;
            char charAtI = s[i];

            // Step 2: Count consecutive occurrences of the same character
            while (i + 1 < s.Length && s[i] == s[i + 1])
            {
                count++;
                i++;
            }

            // Step 3: Append the character and its frequency
            result += count.ToString() + charAtI;
            i++;
        }

        // Step 4: Reverse the transformed string and return
        char[] resultArray = result.ToCharArray();
        Array.Reverse(resultArray);
        return new string(resultArray);
    }

    public static string Decrypt(string encrypted)
    {
        string result = "";
        int i = 0;

        // Step 1: Reverse the encrypted string to get the original transformed string
        char[] encryptedArray = encrypted.ToCharArray();
        Array.Reverse(encryptedArray);
        encrypted = new string(encryptedArray);

        // Step 2: Iterate through the reversed string to extract counts and characters
        while (i < encrypted.Length)
        {
            string countStr = "";

            // Extract the count
            while (i < encrypted.Length && Char.IsDigit(encrypted[i]))
            {
                countStr += encrypted[i];
                i++;
            }

            // Convert the count to integer
            int count = int.Parse(countStr);

            // The next character is the one that occurred 'count' times
            result += new string(encrypted[i], count);
            i++;
        }

        return result;
    }

    public static void Main()
    {
        string input1 = "aaaaaaaaaaa";
        string input2 = "ostad";

        // Encrypt the strings
        string encrypted1 = Encrypt(input1);
        string encrypted2 = Encrypt(input2);

        // Print encrypted outputs
        Console.WriteLine($"Encrypted '{input1}': {encrypted1}");
        Console.WriteLine($"Encrypted '{input2}': {encrypted2}");

        // Decrypt the strings
        string decrypted1 = Decrypt(encrypted1);
        string decrypted2 = Decrypt(encrypted2);

        // Print decrypted outputs
        Console.WriteLine($"Decrypted '{encrypted1}': {decrypted1}");
        Console.WriteLine($"Decrypted '{encrypted2}': {decrypted2}");

        // Check if the decrypted strings match the originals
        Console.WriteLine($"Decryption matches original for '{input1}': {(decrypted1 == input1 ? "True" : "False")}");
        Console.WriteLine($"Decryption matches original for '{input2}': {(decrypted2 == input2 ? "True" : "False")}");
    }
}
