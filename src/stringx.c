#include "include/stringx.h"

// Compares two strings (Equal / Not equal)
boolx comparex(const str string1, const str string2) {
    int str1len = lenx(string1);
    int str2len = lenx(string2);
    if (str1len != str2len) return false;
    for (int i = 0; i < str1len; i++)
        if (string1[i] != string2[i]) return false;
    return true;
}

// Returns true if `substr` is a substring of `string`
boolx is_substrx(const str string, const str substr) {
    int strlen = lenx(string);
    int substrlen = lenx(substr);
    if (substrlen > strlen) return false;
    int searchSize = strlen-substrlen+1;
    for (int i = 0; i < searchSize; i++) {
        int j = 0;
        while (j < substrlen) {
            if (string[i+j] != substr[j]) break;
            if (j == substrlen-1) return true;
            j++;
        }
    }
    return false;
}

// String length without '\0'
int lenx(const str string) {
    int i = 0;
    while (string[i] != '\0') i++;
    return i;
}
    
// Is used to define the size of the `result` variable before `replacex()`
int calcx(const str string, const str old, const str new) {
    int searchSize = lenx(string)-lenx(old)+1;
    int count = 0;
    for (int i = 0; i < searchSize; i++) {
        int j = 0;
        while (j < lenx(old)) {
            if (string[i+j] != old[j]) break;
            if (j == lenx(old)-1) {
                count++;
                if (i <= searchSize-lenx(old)) i += lenx(old);
                break;
            }
            j++;
        }
    }
    return lenx(string)-count*lenx(old)+count*lenx(new);
}

// Replaces `old` with `new` in `string` and returns `result` 
void replacex(const str string, const str old, const str new, str result) {
    int strlen = lenx(string);
    int oldlen = lenx(old);
    int newlen = lenx(new);
    int i = 0;
    int pos = 0;
    while (i < strlen) {
        boolx match = true;
        for (int j = 0; j < oldlen && (i + j) < strlen; j++) {
            if (string[i + j] != old[j]) {
                match = false;
                break;
            }
        }
        if (match && oldlen > 0) {
            for (int k = 0; k < newlen; k++)
                result[pos++] = new[k];
            i += oldlen;
        } else result[pos++] = string[i++];
    }
    result[pos] = '\0';
}

