#include <iostream>
#include <conio.h> // For _getch()

class Password {
   public:

    std::string psw;
    int length;

    Password() : length(0) {}
    
    // Method to input password
    void InputPassword();
};

void Password::InputPassword() {
    char temp_c;
    psw = "";
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
                    std::cout << "*"; // Use '*' to replace what you input
                    psw += temp_c; // Connect each character to string 'psw'
                    length++;
                    break;
            }
        } else {
            break;
        }
    }
    std::cout << std::endl;
}

int main() {
    Password password;
    std::cout << "Enter your password: ";
    password.InputPassword();
    std::cout << "Password entered: " << password.psw << std::endl;
    return 0;
}
