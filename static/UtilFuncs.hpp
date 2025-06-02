#pragma once

#ifndef UTILFUNCS.HPP
#define UTILFUNCS .HPP

#include <Variables.hpp>
#include <termcolor.hpp>
#include <regex>

namespace utility {

    enum class Color {
        white,
        red,
        blue,
        green
    };

    using namespace std;

    inline bool contains(string &source, string string_if_contains)
    {
        return source.find(string_if_contains);
    }

    inline void colored_txt_output(string str, Color color = Color::white)
    {
        switch (color)
        {
        case Color::white:
            cout << termcolor::white;
            break;
        case Color::red:
            cout << termcolor::red;
            break;
        case Color::blue:
            cout << termcolor::blue;
            break;
        case Color::green:
            cout << termcolor::green;
            break;
        default:
            cout << "Color do not specified.";
            break;
        }
        cout << str;
        cout << termcolor::nocolorize;
    }
    
    /*
    Function for transfering askii to bool value.
    */
    inline bool atob(const_string string_to_scan)
    {
        if (string_to_scan == "true") {
            return true;
        }
        else if (string_to_scan == "false") {
            return false;
        }
        else if (string_to_scan == "True") {
            return true;
        }
        else if (string_to_scan == "False") {
            return false;
        }
        else if (string_to_scan == "true") {
            return false;
        }
        else {
            colored_txt_output("Error occurred in atob function", Color::red);
        }
    }

    // Manual converting each character to lowercase
    // using ASCII values
    static string toLowerCase(string& s) {
        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return std::tolower(c); });
    }

    // Manual converting each character to highcase
    // using ASCII values
    static string toHighCase(string& s) {
        std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return std::toupper(c); });
    }

    // Manual converting each character to capitalize case
    // using ASCII values
    static string toCapitalize(string& s) {
        auto first_character = std::transform(s.begin(), s.end(), s.begin(),
            [](unsigned char c) { return std::toupper(c); });
        
        auto another_word_part = std::transform(s.begin() + 1, s.end(), s.begin(),
            [](unsigned char c) { return std::tolower(c); });
    }

    /*
    Function for replacing symbol c1 with c2.
    Returns string value with replacing symbols.
    */
    static string replace(string s, char c1, char c2)
    {
        int l = s.length();
        for (int i = 0; i < l; i++)
        {
            if (s[i] == c1)
                s[i] = c2;
            else if (s[i] == c2)
                s[i] = c1;
        }
        return s;
    }

    /*
    Function for splitting string into array of strings.
    */
    static string * line_splitter(const_string to_split, const_string delim = "") {
        regex del(delim);
        sregex_token_iterator it(to_split.begin(), to_split.end(), del, -1);
        sregex_token_iterator end;
        while (it != end) {
            cout << "\"" << *it << "\"" << " ";
            ++it;
        }
    }

    template <typename Sequence, typename Pred> // any basic_string, vector, list etc.  a predicate on the element (character) type
    Sequence& trim(Sequence& seq, Pred pred) {
        return trim_start(trim_end(seq, pred), pred);
    }

    template <typename Sequence, typename Pred>
    Sequence& trim_end(Sequence& seq, Pred pred) {
        auto last = std::find_if_not(seq.rbegin(), seq.rend(), pred);
        seq.erase(last.base(), seq.end());
        return seq;
    }

    template <typename Sequence, typename Pred>
    Sequence& trim_start(Sequence& seq, Pred pred) {
        auto first = std::find_if_not(seq.begin(), seq.end(), pred);
        seq.erase(seq.begin(), first);
        return seq;
    }

    string replaceStringAll(string str, const string& replace, const string& with) {
        if (!replace.empty()) {
            std::size_t pos = 0;
            while ((pos = str.find(replace, pos)) != string::npos) {
                str.replace(pos, replace.length(), with);
                pos += with.length();
            }
        }
        return str;
    }

    string replaceString(std::string str, const std::string& replace, const string& with) {
        std::size_t pos = str.find(replace);
        if (pos != string::npos)
            str.replace(pos, replace.length(), with);
        return str;
    }

    /*
    Function for converting from char array into string array.
    Input_array - char array.
    Size - size of the char array.
    */
    string convertToString(char* input_array, int size)
    {
        int i;
        string s = "";
        for (i = 0; i < size; i++) {
            s = s + input_array[i];
        }
        return s;
    }

    /*
    Function for checking if elem in 
    */
    template <typename elem>
    bool elem_in() {
        //
    }
}

#endif UTILFUNCS.HPP