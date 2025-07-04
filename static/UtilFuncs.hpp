/*
 Header file with some useful functions
 */

#pragma once

#ifndef UTILFUNCS_HPP
#define UTILFUNCS_HPP

#include <regex>

#include "../core/data/Variables.hpp"
#include "../core/data/dependencies/termcolor.hpp"

/*
 Namespace with utility functions
 */
namespace utility {
    /*
     Enumerate class for compiler colors
     */
    enum class Color {
        white,
        red,
        blue,
        green
    };

    using namespace std;

    /*
     Function for printt value into standard output with next line.
     */
    template<typename T>
    void println(const T &value) {
        cout << value << "\n";
    }

    /*
     Function for print value into standard output without next line.
     */
    template<typename T>
    void print(const T &value, string separator = " ") {
        cout << value << separator;
    }

    [[maybe_unused]] inline bool contains(const_string &source, const_string &string_if_contains) {
        return source.find(string_if_contains);
    }

    /*
     Function for text output into standard output with color.
     Color provided by termcolor library.
     str - string for output in console
     color - color value from Color enum
     */
    [[maybe_unused]] inline void colored_txt_output(const_string &str, const Color color = Color::white) {
        switch (color) {
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
    Function for printing message in red
     */
    [[maybe_unused]] inline void print_error(const_string &error) {
        cout << termcolor::red << error;
    }

    /*
    Function for printing message in green
    */
    [[maybe_unused]] inline void print_success(const_string &success) {
        cout << termcolor::green << success;
    }

    /*
    Function for transferring ASCII to bool value.
    */
    [[maybe_unused]] inline bool atob(const_string &string_to_scan) {
        if (string_to_scan == "true") {
            return true;
        } else if (string_to_scan == "false") {
            return false;
        } else if (string_to_scan == "True") {
            return true;
        } else if (string_to_scan == "False") {
            return false;
        } else {
            if (string_to_scan == "true") {
                return false;
            }
            colored_txt_output("Error occurred in atob function", Color::red);
        }
        return false;
    }

    /*
     Manual converting each character to lowercase
     using ASCII values
    */
    [[maybe_unused]] static string to_lower_case(const_string &s) {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](const unsigned char c) { return std::tolower(c); });
    }

    /*
    Manual converting each character to high case
    using ASCII values
     */
    [[maybe_unused]] static string to_high_case(const_string &s) {
        std::transform(s.begin(), s.end(), s.begin(),
                       [](const unsigned char c) { return std::toupper(c); });
    }

    /*
    Manual converting each character to capitalize case
    using ASCII values
     */
    [[maybe_unused]] static string to_capitalize(const_string &s) {
        auto first_character = std::transform(s.begin(), s.end(), s.begin(),
                                              [](unsigned char c) { return std::toupper(c); });

        auto another_word_part = std::transform(s.begin() + 1, s.end(), s.begin(),
                                                [](unsigned char c) { return std::tolower(c); });
    }

    /*
    Function for replacing symbol c1 with c2.
    Returns string value with replacing symbols.
    */
    [[maybe_unused]] static string replace(string &s, const char c1, const char c2) {
        const int l = s.length();
        for (int i = 0; i < l; i++) {
            if (s[i] == c1)
                s[i] = c2;
            else if (s[i] == c2)
                s[i] = c1;
        }
        return s;
    }

    /*
    Function for replacing string c1 with c2.
    Returns string value with replacing symbols.
    */
    [[maybe_unused]] static string replace(const_string &s, const_string &s1, const_string &s2) {
        const int l = s.length();
        for (int i = 0; i < l; i++) {
            //
        }
        return "";
    }

    /*
    Function for splitting string into array of strings.
    */
    [[maybe_unused]] static string *line_splitter(const_string &to_split, const_string &delim = "") {
        const regex del(delim);
        sregex_token_iterator it(to_split.begin(), to_split.end(), del, -1);
        const sregex_token_iterator end;
        while (it != end) {
            cout << "\"" << *it << "\"" << " ";
            ++it;
        }
    }

    /*
    trim some characters at sequence
     */
    template<typename Sequence, typename Pred>
    [[maybe_unused]] Sequence &trim(Sequence &seq, Pred pred) {
        return trim_start(trim_end(seq, pred), pred);
    }

    /*
    trim some characters at sequence end
     */
    template<typename Sequence, typename Pred>
    [[maybe_unused]] Sequence &trim_end(Sequence &seq, Pred pred) {
        auto last = std::find_if_not(seq.rbegin(), seq.rend(), pred);
        seq.erase(last.base(), seq.end());
        return seq;
    }

    /*
    trim some characters at sequence start
     */
    template<typename Sequence, typename Pred>
    [[maybe_unused]] Sequence &trim_start(Sequence &seq, Pred pred) {
        auto first = std::find_if_not(seq.begin(), seq.end(), pred);
        seq.erase(seq.begin(), first);
        return seq;
    }

    /*
     Function for replacing all strings in string
     */
    [[maybe_unused]] inline string &replace_string_all(string str, const_string &replace, const_string &with) {
        if (!replace.empty()) {
            std::size_t pos = 0;
            while ((pos = str.find(replace, pos)) != string::npos) {
                str.replace(pos, replace.length(), with);
                pos += with.length();
            }
        }
        return str;
    }

    /*
     Function for replace string
     */
    [[maybe_unused]] inline string replace_string(string &str, const_string &replace, const_string &with) {
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
    [[maybe_unused]] inline string convert_to_string(cconst_string *input_array, const_int size) {
        string s;
        for (int i = 0; i < size; i++) {
            s += input_array[i];
        }
        return s;
    }
}

#endif UTILFUNCS_HPP
