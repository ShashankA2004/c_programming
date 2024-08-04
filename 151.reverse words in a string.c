void reverseString(char* s, int start, int end) {
    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}


char* skipSpaces(char* s) {
    while (*s && *s == ' ') {
        s++;
    }
    return s;
}

char* reverseWords(char* s) {
    int len = strlen(s);
    reverseString(s, 0, len - 1);
    int res_index = 0;
    int word_start, word_end;
    char* res = (char*)malloc((len + 1) * sizeof(char));

    s = skipSpaces(s);
    while (*s) {

        word_start = res_index;
        while (*s && *s != ' ') {
            res[res_index++] = *s++;
        }
        word_end = res_index - 1;

        reverseString(res, word_start, word_end);


        if (*s) {
            res[res_index++] = ' ';
            s++;
        }
        s = skipSpaces(s);
    }
 if (res_index > 0 && res[res_index - 1] == ' ') {
        res_index--;
    }
    res[res_index] = '\0';
    return res;
}