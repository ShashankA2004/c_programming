int romanToInt(const char* s) {
    // Define Roman numeral values
    int values[256] = {0};
    values['I'] = 1;
    values['V'] = 5;
    values['X'] = 10;
    values['L'] = 50;
    values['C'] = 100;
    values['D'] = 500;
    values['M'] = 1000;
    
    int length = strlen(s);
    int total = 0;
    
    for (int i = 0; i < length; i++) {
        int currentVal = values[(unsigned char)s[i]];
        int nextVal = (i + 1 < length) ? values[(unsigned char)s[i + 1]] : 0;
        
        // If the current value is less than the next value, subtract it; otherwise, add it
        if (currentVal < nextVal) {
            total -= currentVal;
        } else {
            total += currentVal;
        }
    }
    
    return total;
}