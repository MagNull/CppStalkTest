#pragma once
#include <fstream>
#include <string>
#include <vector>

class User;

class UsersFileReader
{
public:
    explicit UsersFileReader(const std::string& file_path);
    ~UsersFileReader();

    bool GetUsers(std::vector<User*>& out_users);

private:
    bool ParseUserFromString(const wchar_t* str, User*& out_user) const;

private:
    std::wifstream ifstream_;
    static constexpr size_t BUF_SIZE = 1024;

    UsersFileReader(const UsersFileReader&) = delete;
    UsersFileReader& operator=(const UsersFileReader&) = delete;
};
