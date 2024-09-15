#pragma once
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

class c_string
{
public:
    static int string_length(const char *str)
    {
        int length = 0;
        while (str[length] != '\0')
        {
            length++;
        }
        return length;
    }
    
    static char* reverse_string(char str[])
    {
        const int length = string_length(str);
        for (int i = 0; i < length / 2; i++)
        {
            const char temp = str[length - 1 -i];
            str[length - 1 - i] = str[i];
            str[i] = temp;
        }
        return str;
    }

    static bool check_palindrome(char *str)
    {
        const int length = string_length(str);
        for(int i = 0; i<length/2; i++)
        {
            if(str[i] != str[length - 1 -i])
            {
                return false;
            }
        }

        return true;
    }

    static void print_duplicated_hash_table(const int *hash_table, const int length)
    {
        for(int i = 0; i< length; i++)
        {
            int appear = hash_table[i]; 
            if(appear > 0)
            {
                printf("%c appears %d\n", i+97, appear);
            }
        }
    }
    
    static int *check_duplicated(char *str)
    {
        const int length = string_length(str);
        int hash_table[26] = {0}; 

        for(int i =0; i<length; i++)
        {
            const int ascii_code = str[i];
            hash_table[ascii_code-97]++;
        }

        return hash_table;
    }

    static void check_duplicated_bitwise(char *str)
    {
        int length = string_length(str);
        int bits = 0;
        
        for(int i = 0; i<length; i++)
        {
            const int ascii = str[i] - 97;
            const int bitwise = bits & (1 << ascii); // masking bit
            if(bitwise > 0)
            {
                printf("%c is duplicated\n", str[i]);
            }
            else
            {
                bits = bits | (1 << ascii); //merging bit 
            }
        }
    }

    static int last_word_length(string s)
    {
        int count = 0;
        int length = s.length();
        for(int i = length - 1;i>0; i--)
        {
            if(s[i] != ' ')
            {
                count++;
            }
            else
            {
                if(count != 0)
                {
                    return count;
                }
            }
        }
    }

    // https://leetcode.com/problems/reverse-string-ii/
    static string reverse_string_2k(string s, int k) {
        const int length = s.length();
        int j=0;
        while(j<length){
            int incr = j+k <= length ? k : length - j;
            int stageLength = j + incr; //"length" in each stage of reversing
            for(int i=j;i<j+incr/2;i++){
                char temp = s[i];
                s[i] = s[j+(stageLength-1-i)];
                s[j+(stageLength-1-i)] = temp;
            }
            j += 2*k;
        }

        return s;
    }

    // https://leetcode.com/problems/reverse-words-in-a-string-iii/
    static void reverse_words(char* s)
    {
        int i = 0;
        while(s[i] != '\0'){
            if(s[i] == ' ') i++;
            else{
                int k = i;
                int j = i;
                while(s[j+1] != ' '){
                    if(s[j+1] == '\0') break;
                    j++;
                }

                i = j+1;

                while(k<j){
                    char temp = s[k];
                    s[k] = s[j];
                    s[j] = temp;
                    k++;
                    j--;
                }
            }
        }    
    }

    // https://leetcode.com/problems/reverse-vowels-of-a-string/ -- solution has a better way
    static string reverse_vowels(string s)
    {
        int i = 0;
        int count_index = 0;
        const auto vowel_index = static_cast<int*>(malloc(s.length()*sizeof(int)));
        while(s[i] != '\0'){
            if(s[i] == 'a' || 
                s[i] == 'e' ||
                s[i] == 'i' ||
                s[i] == 'o' ||
                s[i] == 'u' ||
                s[i] == 'A' || 
                s[i] == 'E' ||
                s[i] == 'I' ||
                s[i] == 'O' ||
                s[i] == 'U' )
            {
                vowel_index[count_index]=i;
                count_index++;
            }
            i++;
        }
        
        if(i==0) return s;

        for(int j =0;j<count_index/2;j++)
        {
            char temp = s[vowel_index[j]];
            s[vowel_index[j]] = s[vowel_index[count_index - 1 -j]];
            s[vowel_index[count_index - 1 -j]] = temp;
        }

        return s;
    }

    //https://leetcode.com/problems/ransom-note/solutions/1671552/1ms-100-easy-explanation-java-solution/ 
    static bool can_construct(string ransomNote, string magazine)
    {
        int* ransomHashTable = (int*)calloc(26, sizeof(int));
        
        for(int i =0 ;i<ransomNote.length();i++){
            int ascii = (int)ransomNote[i]-97;
            ransomHashTable[ascii]++;
        }

        for(int i =0;i<magazine.length(); i++){
            int ascii = (int)magazine[i]-97;
            if(ransomHashTable[ascii] >0){
                ransomHashTable[ascii]--;
            }
        }

        for(int i =0;i<ransomNote.length(); i++){
            if(ransomNote[i] != 0) return false;
        }

        return true;
    }
};
