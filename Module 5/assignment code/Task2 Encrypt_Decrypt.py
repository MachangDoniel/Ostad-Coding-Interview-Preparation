def encrypt(s):
    # Step 1: Initialize variables for encryption
    n = len(s)
    result = []
    i = 0

    # Step 2: Iterate through the string to count consecutive identical characters
    while i < n:
        count = 1  # At least one occurrence of the character
        char = s[i]  # Current character

        # Step 3: Count consecutive occurrences of the same character
        while i + 1 < n and s[i] == s[i + 1]:
            count += 1
            i += 1

        # Step 4: Append the character along with its frequency
        result.append(f"{count}{char}")

        # Move to the next character
        i += 1

    # Step 5: Concatenate the result and reverse it
    encrypted_str = "".join(result)[::-1]
    return encrypted_str


def decrypt(encrypted):
    # Step 1: Reverse the encrypted string to get the original transformed string
    reversed_encrypted = encrypted[::-1]

    # Step 2: Initialize a variable to store the decrypted string
    decrypted_str = ""
    i = 0
    n = len(reversed_encrypted)

    # Step 3: Iterate through the reversed string to extract characters and their counts
    while i < n:
        # Extract the count (it can be more than 1 digit)
        count_str = ""
        while i < n and reversed_encrypted[i].isdigit():
            count_str += reversed_encrypted[i]
            i += 1

        # Convert the extracted count to an integer
        count = int(count_str)

        # The next character is the one that occurred 'count' times
        char = reversed_encrypted[i]
        decrypted_str += char * count

        # Move to the next character
        i += 1

    return decrypted_str


# Sample Test Cases
input1 = "aaaaaaaaaaa"
input2 = "ostad"

# Encrypt the strings
encrypted1 = encrypt(input1)
encrypted2 = encrypt(input2)

# Print encrypted outputs
print(f"Encrypted '{input1}': {encrypted1}")
print(f"Encrypted '{input2}': {encrypted2}")

# Decrypt the strings
decrypted1 = decrypt(encrypted1)
decrypted2 = decrypt(encrypted2)

# Print decrypted outputs
print(f"Decrypted '{encrypted1}': {decrypted1}")
print(f"Decrypted '{encrypted2}': {decrypted2}")

# Check if the decrypted strings match the originals
print(f"Decryption matches original for '{input1}': {decrypted1 == input1}")
print(f"Decryption matches original for '{input2}': {decrypted2 == input2}")
