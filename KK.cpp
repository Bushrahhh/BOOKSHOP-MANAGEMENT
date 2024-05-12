#include <iostream>
#include <string>
#include <conio.h> // For _getch() function

class Password {
private:
    std::string psw;
    int length = 0;
public:
    void InputPassword();
};

void Password::InputPassword() {
    std::cout << "Enter password: ";
    char temp_c;
    while (true) {
        temp_c = _getch(); // Get a character without showing it
        if (temp_c != char(13)) { // If character is ENTER then break
            switch (temp_c) {
                case 8: // If character is Backspace
                    if (length != 0) {
                        std::cout << "\b \b";
                        psw = psw.substr(0, length - 1);
                        length--;
                    }
                    break;
                default:
                    std::cout << temp_c; // Display the character
                    psw += temp_c; // Connect each character to string 'psw'
                    length++;
                    break;
            }
        } else break;
    }
    std::cout << std::endl;
}

int main() {
    Password password;
    password.InputPassword(); // Prompt for password input
    return 0;
}
