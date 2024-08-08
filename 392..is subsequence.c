bool isSubsequence(const char *str1, const char *str2) {
    // Pointers for the current position in str1 and str2
    const char *p1 = str1;
    const char *p2 = str2;

    // Traverse both strings
    while (*p2 != '\0') {
        if (*p1 == *p2) {
            p1++;  // Move pointer in str1 when characters match
        }
        p2++;  // Always move pointer in str2
    }

    // If we reached the end of str1, all characters were found in str2
    return *p1 == '\0';
}