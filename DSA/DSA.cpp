#include <cstdio>
#include "String/c_string.h"

const int number_of_char = 26;

#pragma string_implement
void string_implement()
{
    char str[] = "IcEcrEAm";//12 chars
    
    // reverse a string
    // char *reversedString = c_string::reverse_string(str);
    
    // // check if a string is palindrome
    // bool palindrome = c_string::check_palindrome(str);
    
    // // check duplicated characters in a string
    // const int *duplicated_hash_table = c_string::check_duplicated(str);
    // string::print_duplicated_hash_table(duplicated_hash_table, number_of_char);
    // c_string::check_duplicated_bitwise(str);

    // string s = "abcd";
    // c_string::reverse_string_2k(s, 4);

    // c_string::reverse_words(str);

    // auto reversed_string = c_string::reverse_vowels(str);
    // printf("%s", reversed_string.c_str());

    c_string::can_construct("aa", "aab");
}
#pragma

void test()
{
    int a = 2;
    int b = 1;
    int c = a | b;
    printf("%d", c);
}

int main(int argc, char* argv[])
{
    string_implement();
    return 0;
}
