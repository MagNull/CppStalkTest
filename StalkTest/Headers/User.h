#pragma once
#include <string>

class User
{
public:
    User(const std::wstring name, const std::wstring surname, const uint64_t id) : name_(name),
                                                                                     surname_(surname), id_(id)
    {
    }

    std::wstring GetName() const { return name_; }
    std::wstring GetSurname() const { return surname_; }
    uint64_t GetID() const { return id_; }

private:
    std::wstring name_;
    std::wstring surname_;
    uint64_t id_ = 0;
};
