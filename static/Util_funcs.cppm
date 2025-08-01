/*
 Header file with some useful functions
 */

#ifndef UTIL_FUNCS_HPP
#define UTIL_FUNCS_HPP

/**
 Module with different useful functions.
 */
export module UtilFuncs;

#include <regex>

#include "../Custom_operators.hpp"
#include "Variables.hpp"
#include "dependencies/termcolor.hpp"

/**
 Namespace with utility functions of the C+ compiler
 */
export namespace utility {
    /**
     Enumerate class for compiler output colors
     */
    enum Color {
        WHITE,
        RED,
        BLUE,
        GREEN
    };

    /**
     Function for printt value into standard output with next line.
     @param value
     */
    Generic<typename T>
    None println(const T &value) {
        std::cout << value << "\n";
    }

    /**
     Function for print value into standard output without next line.
     @param value
     @param separator
     */
    Generic<typename T>
    None print(const T &value, string separator = " ") {
        std::cout << value << separator;
    }

    /**
     Data object with useful ansi things
     */
    DataObject ansi_utils {
    local:
        string red_start = "\033[91m";

        string color_end = "\033[00m";

        string green_start = "\033[92m";

        string yellow_start = "\033[93m";

        string cyan_start = "\033[96m";

        string gray_start = "\033[97m";

    global:
        /**
         *
         * @param value
         */
        None ansi_utils::prRed(string refer value) {
            print(red_start + value + color_end);
        }

        /**
         *
         * @param value
         */
        None ansi_utils::prGreen(const_string refer value) {
            print(green_start + value + color_end);
        }

        /**
        *
        * @param value
        */
        None ansi_utils::prYellow(const_string refer value) {
            print(yellow_start + value + color_end);
        }

        /**
        *
        * @param value
        */
        None ansi_utils::prCyan(const_string refer value) {
            print(cyan_start + value + color_end);
        }

        /**
        *
        * @param value
        */
        None ansi_utils::prLightGray(const_string refer value) {
            print(gray_start + value + color_end);
        }
    };

    /**
     *
     * @param source
     * @param string_if_contains
     * @return bool value if string is in source
     */
    [[maybe_unused]] inline bool contains(const_string &source, const_string &string_if_contains) {
        return source.find(string_if_contains);
    }

    /**
     Function for text output into standard output with color.
     Color provided by termcolor library.
     @param str string for output in console
     @param color color value from Color enum
     */
    [[maybe_unused]] inline void colored_txt_output(const_string &str, const Color color = Color::WHITE) {
        match (color) {
            case Color::WHITE:
                std::cout << termcolor::white;
                break;
            case Color::RED:
                std::cout << termcolor::red;
                break;
            case Color::BLUE:
                std::cout << termcolor::blue;
                break;
            case Color::GREEN:
                std::cout << termcolor::green;
                break;
            default:
                std::cout << "Color do not specified.";
                break;
        }
        std::cout << str;
        std::cout << termcolor::nocolorize;
    }

    /**
    Function for printing message in red
     */
    [[maybe_unused]] inline void print_error(const_string &error) {
        std::cout << termcolor::red << error;
    }

    /**
    Function for printing message in green
    */
    [[maybe_unused]] inline void print_success(const_string &success) {
        std::cout << termcolor::green << success;
    }

    /**
    Function for transferring ASCII to bool value.
    Yes, I know that this function is something that smell, but...
    */
    [[maybe_unused]] inline bool atob(const_string &string_to_scan) {
        if (string_to_scan == "true") {
            return true;
        }
        if (string_to_scan == "false") {
            return false;
        }
        if (string_to_scan == "True") {
            return true;
        }
        if (string_to_scan == "False") {
            return false;
        }
        colored_txt_output("Error occurred in atob function", Color::RED);
        return false;
    }

    /**
    Function for replacing symbol c1 with c2.
    Returns string value with replacing symbols.
    */
    [[maybe_unused]] static string replace(string &s, const char c1, const char c2) {
        val2 l = s.length();
        for (int i = 0; i < l; i++) {
            if (s[i] == c1) {
                s[i] = c2;
            }
            elif (s[i] == c2) {
                s[i] = c1;
            }
        }
        return s;
    }

    /**
    Function for replacing string c1 with c2.
    Returns string value with replacing symbols.
    */
    [[maybe_unused]] static string replace(const_string &s, const_string &s1, const_string &s2) {
        const var3 l = s.size();
        for (int i = 0; i < l; i++) {
            //
        }
        return "";
    }

    /**
    Function for splitting string into array of strings.
    @param to_split
    @param delim
    */
    [[maybe_unused]] static std::vector<string> &line_splitter(const_string &to_split, const char delim = ' ') {
        std::istringstream input{to_split};
        std::vector<std::string> result;
        string tmp;
        // extract substrings one-by-one
        while (getline(input, tmp, delim)) {
            input >> tmp;
            result.push_back(tmp);
        }
        return result;
    }

    /**
    trim some characters at sequence
    @param seq
    @param pred
     */
    Generic<typename Sequence, typename Pred>
    [[maybe_unused]] Sequence &trim(Sequence &seq, Pred pred) {
        return trim_start(trim_end(seq, pred), pred);
    }

    /**
    trim some characters at sequence end
    @param seq
    @param pred
     */
    Generic<typename Sequence, typename Pred>
    [[maybe_unused]] Sequence &trim_end(Sequence &seq, Pred pred) {
        var3 last = std::find_if_not(seq.rbegin(), seq.rend(), pred);
        seq.erase(last.base(), seq.end());
        return seq;
    }

    /**
    trim some characters at sequence start
    @param seq
    @param pred
     */
    Generic<typename Sequence, typename Pred>
    [[maybe_unused]] Sequence &trim_start(Sequence &seq, Pred pred) {
        var3 first = std::find_if_not(seq.begin(), seq.end(), pred);
        seq.erase(seq.begin(), first);
        return seq;
    }

    /**
     Function for replacing all strings in string
     @param str
     @param replace
     @param with
     */
    [[maybe_unused]] optim string &replace_string_all(string &str, const_string &replace, const_string &with) {
        if (!replace.empty()) {
            std::size_t pos = 0;
            while ((pos = str.find(replace, pos)) != string::npos) {
                str.replace(pos, replace.length(), with);
                pos += with.length();
            }
        }
        return str;
    }

    /**
     Function for replace string
     @param str
     @param replace
     @param with
     */
    [[maybe_unused]] inline string replace_string(string &str, const_string &replace, const_string &with) {
        std::size_t pos = str.find(replace);
        if (pos != string::npos)
            str.replace(pos, replace.length(), with);
        return str;
    }

    /**
    Function for converting from char array into string array.
    @param input_array char array.
    @param size - size of the char array.
    */
    [[maybe_unused]] inline string convert_to_string(const cconst_string input_array, const_int size) {
        string s;
        for (int i = 0; i < size; i++) {
            s += input_array[i];
        }
        return s;
    }
}

#endif
