#include "Tools.h"

namespace SNS
{

    void clearScreen(){
        system("clear");
    }

    string getEnteredString(string text, ValidateString validate, std::istream &in)
    {
        string console_enter{};

        while (true)
        {
            cout << text;
            in >> console_enter;

            if (in.fail() || (validate && !validate(console_enter)))
            {
                console_enter.clear();
                in.clear();
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "\n\nYou entered an incorrect value, please try again!\n\n";
                continue;
            }

            break;
        }

        return console_enter;
    }

    int getEnteredNum(string text, ValidateNum validate, std::istream &in)
    {
        int console_enter{};

        while (true)
        {
            cout << text;
            in >> console_enter;

            if (cin.fail() || (validate && !validate(console_enter)))
            {
                in.clear();
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "\n\nYou entered an incorrect value, please try again!\n\n";
                continue;
            }

            break;
        }

        return console_enter;
    }

    char getEnteredChar(string text, ValidateChar validate, std::istream &in)
    {
        char console_enter{};

        while (true)
        {
            cout << text;
            in >> console_enter;

            if (cin.fail() || (validate && !validate(console_enter)))
            {
                in.clear();
                in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "\n\nYou entered an incorrect value, please try again!\n\n";
                continue;
            }

            break;
        }

        return console_enter;
    }

} // namespace SNS
