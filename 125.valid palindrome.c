bool isPalindrome(const char* s) {
    int length = strlen(s);
    char normalized[length + 1]; // Buffer to hold the normalized string
    int j = 0; // Index for normalized string

    // Normalize the string
    for (int i = 0; i < length; i++) {
        if (isalnum(s[i])) { // Check if the character is alphanumeric
            normalized[j++] = tolower(s[i]); // Convert to lowercase and add to normalized string
        }
    }
    normalized[j] = '\0'; // Null-terminate the normalized string

    // Check if normalized string is a palindrome
    int start = 0;
    int end = j - 1;
    while (start < end) {
        if (normalized[start] != normalized[end]) {
            return false; // Not a palindrome
        }
        start++;
        end--;
    }

    return true; // Is a palindrome
}