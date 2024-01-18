#include <iostream>
#include "UsersFileReader.h"
#include "UserSorter.h"
#include <windows.h>
#include <fcntl.h>


enum UserSortType
{
    ByName = 1,
    BySurname = 2,
    ById = 3,
};

static void Start(std::vector<User*>& users)
{
    UserSorter sorter(users);

    //Welcome message
    std::cout << "Для сортировки по именам введите – " << UserSortType::ByName
        << ", по фамилиям введите - " << UserSortType::BySurname
        << ", по телефонам введите - " << UserSortType::ById << '\n';
    
    std::string input;
    std::wcout << L"> ";

    //Sorting and printing loop
    while (std::getline(std::cin, input))
    {
        try
        {
            const auto sort_type = std::stoi(input);

            switch (sort_type)
            {
            case UserSortType::ByName:
                sorter.SortByName();
                break;
            case UserSortType::BySurname:
                sorter.SortBySurname();
                break;
            case UserSortType::ById:
                sorter.SortById();
                break;
            default:
                throw std::logic_error("Incorrect sort type!");
            }
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::wcout << L"> ";
            continue;
        }

        for (auto user : sorter.GetUsers())
        {
            std::wcout << user->GetName() << L" " << user->GetSurname() << L": " << user->GetID() << L'\n';
        }
        std::wcout << L"> ";
    }
}

int main(int argc, char* argv[])
{
    std::locale::global(std::locale("ru_RU.UTF-8"));
    SetConsoleOutputCP(CP_UTF8);
    
    try
    {
        if (argc < 2)
        {
            throw std::logic_error("No input file!");
        }

        const std::string filename = argv[1];

        UsersFileReader reader(filename);
        std::vector<User*> users;
        reader.GetUsers(users);
        
        if (users.empty())
        {
            throw std::runtime_error("Input file is empty or has an incorrect data format!");
        }
        Start(users);
    }
    catch (const std::exception& e)
    {
        std::wcerr << e.what() << '\n';
        std::cin.get();
    }

    return 0;
}
