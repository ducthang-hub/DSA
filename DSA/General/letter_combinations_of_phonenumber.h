#pragma once
#include <stack>
#include <string>
#include <vector>

using namespace std;

class letter_combinations_of_phonenumber
{
public:
    vector<char> split_string(string str)
    {
        vector<char> char_array(0);
        for(auto i: str)
        {
            char_array.push_back(i);
        }
        return char_array;
    }

    void push_chars(stack<pair<char, string>> &stack, vector<char> array, string previous_path)
    {
        for(auto i : array)
        {
            stack.push(pair<char, string>(i, previous_path));
        }
    }

    int find_next_digit(char letter, vector<string> phone, string digits)
    {
        int index;
        for(int i = 0;i<phone.size(); i++)
        {
            if(phone[i].find(letter) != string::npos)
            {
                index = i;
                break;
            }
        }

        for(int j = 0;j<digits.length(); j++)
        {
            if(index == digits[j] - '0')
            {
                return digits[j+1]-'0';
            }
        }

        return 2;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.length() == 0) return {};

        vector<string> phone {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        auto last_digit = digits[digits.size()-1] - '0';
        auto first_digit = (int)digits[0] - '0';
        vector<string> result;
        
        stack<pair<char, string>> letters;
        auto char_array = split_string(phone[first_digit]);
        push_chars(letters, char_array, "");

        while(!letters.empty())
        {
            auto letter = letters.top();
            letters.pop();

            if(phone[last_digit].find(letter.first) != string::npos)
            {
                result.push_back(letter.second + letter.first);
            }
            else
            {
                int next_digit = find_next_digit(letter.first, phone, digits);
                char_array = split_string(phone[next_digit]);
                push_chars(letters, char_array, letter.second+letter.first);
            }
        }

        return result;
    }
};
