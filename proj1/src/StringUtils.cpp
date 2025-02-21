#include "StringUtils.h"

namespace StringUtils
{

    std::string Slice(const std::string &str, ssize_t start, ssize_t end) noexcept
    {
        // Replace code here
        if (start < 0)
        {
            start = str.size() + start;
        }
        if (end < 0)
        {
            end = str.size() + end;
        }
        auto len = (end - start);
        return str.substr(start, len);
    }

    std::string Capitalize(const std::string &str) noexcept
    {
        // Replace code here
        std::string result = str;
        result[0] = toupper(result[0]);
        for (int i = 1; i < result.length(); i++)
        {
            result[i] = tolower(result[i]);
        }
        // return result;
        return result;
    }

    std::string Upper(const std::string &str) noexcept
    {
        // Replace code here
        std::string result = str;
        for (int i = 0; i < result.length(); i++)
        {
            result[i] = toupper(result[i]);
        }

        return result;
    }

    std::string Lower(const std::string &str) noexcept
    {
        // Replace code here
        std::string result = str;
        for (int i = 0; i < result.length(); i++)
        {
            result[i] = tolower(result[i]);
        }
        return result;
    }

    std::string LStrip(const std::string &str) noexcept
    {
        // Replace code here
        // for this one
        std::string result = str;
        for (int i = 0; i < result.length(); i++)
        {
            if (result[i] != ' ')
            {
                result = result.substr(i);
                break;
            }
        }
        return result;
    }

    std::string RStrip(const std::string &str) noexcept
    {
        // Replace code here
        std::string result = str;
        for (int i = result.length() - 1; i >= 0; i--)
        {
            if (result[i] != ' ')
            {
                result = result.substr(0, i + 1);
                break;
            }
        }
        return result;
    }

    std::string Strip(const std::string &str) noexcept
    {

        // Replace code here
        std::string result = str;
        for (int i = 0; i < result.length(); i++)
        {
            if (result[i] != ' ')
            {
                result = result.substr(i);
                break;
            }
        }
        for (int i = result.length() - 1; i >= 0; i--)
        {
            if (result[i] != ' ')
            {
                result = result.substr(0, i + 1);
                break;
            }
        }
    }

    std::string Center(const std::string &str, int width, char fill) noexcept
    {
        // Replace code here
        std::string result = str;
        int leftWidth = (width - result.length()) / 2;
        int rightWidth = (width - result.length()) / 2;
        if ((width - result.length()) % 2 != 0)
        {
            rightWidth++;
        }
        for (int i = 0; i < leftWidth; i++)
        {
            result = fill + result;
        }
        for (int i = 0; i < rightWidth; i++)
        {
            result = result + fill;
        }

        return result;
    }

    std::string LJust(const std::string &str, int width, char fill) noexcept
    {
        // Replace code here
        std::string result = str;
        width = width - result.length();
        for (int i = 0; i < width; i++)
        {
            result = result + fill;
        }
        return result;
    }

    std::string RJust(const std::string &str, int width, char fill) noexcept
    {
        // Replace code here
        std::string result = str;
        width = width - result.length();
        for (int i = 0; i < width; i++)
        {
            result = fill + result;
        }
        return result;
    }

    std::string Replace(const std::string &str, const std::string &old, const std::string &rep) noexcept
    {
        std::string result = str;
        auto temp = str.find(old);
        while (temp != std::string::npos)
        {
            std::string before_old = result.substr(0, temp);
            std::string after_old = result.substr(temp + old.length());
            result = result.substr(0, temp) + rep + result.substr(temp + old.length());
            temp = result.find(old);
        }
        return result;
    }

    std::vector<std::string> Split(const std::string &str, const std::string &splt) noexcept
    {
        // Replace code her
        // this splits the strin gup into a vector of strings based on splt parameter.
        // if splt parameter is an empty string, split on white space
        std::vector<std::string> result;
        if (splt.empty())
        {
            std::istringstream iss(str);
            std::string word;
            while (iss >> word)
            {
                result.push_back(word);
            }
        }
        else
        {
            size_t start = 0;
            size_t end = str.find(splt);
            while (end != std::string::npos)
            {
                result.push_back(str.substr(start, end - start));
                start = end + splt.length();
                end = str.find(splt, start);
            }
            result.push_back(str.substr(start));
        }

        return result;
    }

    std::string Join(const std::string &str, const std::vector<std::string> &vect) noexcept
    {
        std::string result = vect[0];
        for (size_t i = 1; i < vect.size(); i++)
        {
            result += str + vect[i];
        }
        return result;
    }

    std::string ExpandTabs(const std::string &str, int tabsize) noexcept
    {

        std::string res;
        size_t curr = 0;
        if (tabsize == 0)
        {
            for (char c : str)
            {
                if (c != '\t')
                {
                    res += c;
                }
            }
            return res;
        }
        for (char c : str)
        {
            if (c == '\t')
            {
                size_t numspaces = tabsize - (curr % tabsize);
                res.append(numspaces, ' ');
                curr += numspaces;
            }
            else
            {
                res += c;
                curr += 1;
            }
        }
        return res;
    }

    int EditDistance(const std::string &left, const std::string &right, bool ignorecase) noexcept
    {
        // Replace code here
        return 0;
    }

};
