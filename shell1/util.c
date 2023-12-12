// util.c

#include "shell.h"
#include <stdlib.h>

/**
 * _atoi - Converts a string to an integer
 * @s: The input string
 * 
 * Return: The converted integer
 */
int _atoi(const char *s) {
    int result = 0;
    int sign = 1;

    while (*s) {
        if (*s == '-') {
            sign = -sign;
        } else if (*s >= '0' && *s <= '9') {
            result = result * 10 + (*s - '0');
        } else {
            break;
        }
        s++;
    }

    return result * sign;
}

/**
 * _strcmp - Compares two strings
 * @s1: The first string
 * @s2: The second string
 * 
 * Return: 0 if the strings are equal, a negative value if s1 < s2, a positive value if s1 > s2
 */
int _strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }

    return *(unsigned char *)s1 - *(unsigned char *)s2;
}

