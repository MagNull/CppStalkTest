#include "UsersFileReader.h"

#include <iostream>
#include <regex>
#include <windows.h>
#include <fcntl.h>
#include <stdio.h>

#include "User.h"

UsersFileReader::UsersFileReader(const std::string& file_path)
{
    ifstream_.open(file_path, std::ios::in);

    if (!ifstream_.is_open())
    {
        std::string message = "Сouldn't open a file with path: " + file_path;
        throw std::runtime_error(message.c_str());
    }
}

UsersFileReader::~UsersFileReader()
{
    ifstream_.close();
}

bool UsersFileReader::ParseUserFromString(const wchar_t* str, User*& out_user) const
{
    static const std::wregex regex(L"([a-z|A-Z|а-я|А-Я]+) ([a-z|A-Z|а-я|А-Я]+): ([\\d]\\d+)");
    std::wcmatch match;

    if (std::regex_search(str, match, regex))
    {
        out_user = new User(match[2].str(), match[1].str(), std::stoull(match[3].str()));
        return true;
    }

    std::wstring message =  L"Couldn't parse ad string: " + std::wstring(str);
    std::wcout << message << L'\n';
    return false;
}

bool UsersFileReader::GetUsers(std::vector<User*>& out_users)
{
    std::wstring line;
    while (std::getline(ifstream_, line))
    {
        User* user = nullptr;
        if (ParseUserFromString(line.c_str(), user))
        {
            out_users.push_back(user);
        }
        else
        {
            return false;
        }
    }
    return true;
}
