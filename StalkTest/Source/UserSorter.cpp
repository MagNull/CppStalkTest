#include "UserSorter.h"

#include <algorithm>

void UserSorter::SortByName()
{
    std::sort(users_.begin(), users_.end(), [](User* lhs, User* rhs)
    {
        return lhs->GetName() < rhs->GetName();
    });
}

void UserSorter::SortBySurname()
{
    std::sort(users_.begin(), users_.end(), [](User* lhs, User* rhs)
    {
        return lhs->GetSurname() < rhs->GetSurname();
    });
}

void UserSorter::SortById()
{
    std::sort(users_.begin(), users_.end(), [](User* lhs, User* rhs)
    {
        return lhs->GetID() < rhs->GetID();
    });
}
