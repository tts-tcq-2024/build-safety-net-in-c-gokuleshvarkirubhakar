#ifndef SOUNDEX_H
#define SOUNDEX_H

#include "Soundex.h"
#include <ctype.h>
#include <string.h>

// Character to code mapping for soundex algorithm
/*                 ABCDEFGHIJKLMNOPQRSTUVWXYZ */
char CHAR_MAP[] = "01230120022455012623010202";

#define IS_VALID_CHAR(c) ((c) >= 0 && (c) <= 25)
#define IS_VOWEL(c)      ((c) == 'A' || (c) == 'E' || (c) == 'I' || (c) == 'O' || (c) == 'U' || (c) == 'Y')

// Function to check validity and get char code for the given character
char get_char_code(char c) {
    int pos = c - 'A';
    if (IS_VALID_CHAR(pos)) {
        return CHAR_MAP[pos];
    }
    return '0';
}

// Function to decide whether to encode the character
bool decide_encode(char char_code, char prev_code, char prev_char) {
    return char_code != prev_code || IS_VOWEL(prev_char);
}

// Function to encode given name based on soundex algorithm
void encode_string(char name_ch, char* encoded_name, int* si) {
    static char prev = '\0';
    char char_code = get_char_code(name_ch);
    if(char_code != '0' && decide_encode(char_code, encoded_name[*si - 1], prev) {
        encoded_name[*si] = char_code;
        (*si)++;
    }
    prev = name_ch;
}

// Function to add zero padding to encoded name if applicable
void add_zero_padding(char *s, int idx)
{
    while (idx <= 3) {
        s[idx++] = '0';
    }
}

// Function to generate soundex for given string
void generateSoundex(const char *str, char *encoded_string)
{
    int si = 1;
    int str_len = strlen(str);
    encoded_string[0] = toupper(str[0]);
    for(int i = 1; i < str_len && si <= 3; i++) {
        encode_string(str[i], encoded_string, &si);
    }
    add_zero_padding(encoded_string, si);
    encoded_string[4] = '\0';
}

#endif // SOUNDEX_H
