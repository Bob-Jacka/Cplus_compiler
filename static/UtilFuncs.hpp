#pragma once

#ifndef UTILFUNCS.HPP
#define UTILFUNCS .HPP

#include <Variables.hpp>
#include <termcolor.hpp>

// System defined exit symbol
#if defined(_WIN32) || defined(_WIN64)
#define NEW_LINE "\r\n"
#elif defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
#define NEW_LINE "\n"
#endif

namespace utility {

    using namespace std;

    inline bool contains(string &source, string string_if_contains)
    {
        return *source.find(string_if_contains);
    }

    inline void colored_txt_output(string str = "", string color = "white")
    {
        switch (color)
        {
        case "white":
            cout << termcolor::white;
            break;
        case "red":
            cout << termcolor::red;
            break;
        case "blue":
            cout << termcolor::blue;
            break;
        case "green":
            cout << termcolor::green;
            break;
        default:
            cout << "Color do not specified.";
            break;
        }
        cout << str;
        cout << termcolor::nocolor;
    }
    
    /*
    Function for transfering askii to bool value.
    */
    inline bool atob(const string string_to_scan)
    {
        switch (string_to_scan)
        {
            case "true":
                return true;
            case "false":
                return false;
            case "True":
                return true;
            case "False":
                return false;
            default:
                break;
        }
    }

    /*
    Function for splitting string into array of strings.
    */
    inline string[] line_splitter(const string to_split, const string delim) {
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
}

#endif UTILFUNCS.HPP