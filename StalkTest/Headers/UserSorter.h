#pragma once
#include <vector>

#include "User.h"

class UserSorter
{
public:
    UserSorter(const std::vector<User*>& users) : users_(users)
    {
    }

    std::vector<User*> GetUsers() const { return users_; }

    void SortByName();

    void SortBySurname();

    void SortById();

private:
    std::vector<User*> users_;
};
