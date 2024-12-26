#include "tinylock.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <cctype>
#include <cstdlib>

void clear_screen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void display_ascii_art()
{
    std::cout << R"(


   /$$     /$$                     /$$                     /$$      
  | $$    |__/                    | $$                    | $$      
 /$$$$$$   /$$ /$$$$$$$  /$$   /$$| $$  /$$$$$$   /$$$$$$$| $$   /$$
|_  $$_/  | $$| $$__  $$| $$  | $$| $$ /$$__  $$ /$$_____/| $$  /$$/
  | $$    | $$| $$  \ $$| $$  | $$| $$| $$  \ $$| $$      | $$$$$$/ 
  | $$ /$$| $$| $$  | $$| $$  | $$| $$| $$  | $$| $$      | $$_  $$ 
  |  $$$$/| $$| $$  | $$|  $$$$$$$| $$|  $$$$$$/|  $$$$$$$| $$ \  $$
   \___/  |__/|__/  |__/ \____  $$|__/ \______/  \_______/|__/  \__/
                         /$$  | $$                                  
                        |  $$$$$$/                                  
                         \______/                                      
)" << std::endl;
}


void display_method_menu()
{
    clear_screen();
    display_ascii_art();
    std::cout << "Select a method:" << std::endl;
    std::cout << "1) Basic Caesar Cipher" << std::endl;
    std::cout << "2) Vigenère Cipher" << std::endl;
    std::cout << "0) Exit" << std::endl;
    std::cout << "> ";
}

void display_action_menu()
{
    clear_screen();
    display_ascii_art();
    std::cout << "Select an action:" << std::endl;
    std::cout << "1) Encrypt" << std::endl;
    std::cout << "2) Decrypt" << std::endl;
    std::cout << "3) Back" << std::endl;
    std::cout << "0) Exit" << std::endl;
    std::cout << "> ";
}


void post_action_menu() {
    std::cout << "What do you want to do next?" << std::endl;
    std::cout << "1) Encrypt/Decrypt another text with the same method" << std::endl;
    std::cout << "2) Select a different method" << std::endl;
    std::cout << "0) Exit" << std::endl;
    std::cout << "> ";
}


std::string caesar_encrypt(std::string text, int shifting_value)
{
    std::string result;
    for (char c : text)
    {
        if (isupper(c))
        {
            result += char(int(c + shifting_value - 65 + 26) % 26 + 65);
        }
        else if (islower(c))
        {
            result += char(int(c + shifting_value - 97 + 26) % 26 + 97);
        }
        else
        {
            result += c;
        }
    }
    return result;
}

std::string caesar_decrypt(std::string text, int shifting_value)
{
    return caesar_encrypt(text, 26 - (shifting_value % 26));
}

std::string clean_key(const std::string& key)
{
    std::string cleaned_key;
    for (char c : key)
    {
        if (isalpha(c))
        {
            cleaned_key += c;
        }
    }
    return cleaned_key;
}

std::string vigenere_encrypt(std::string plaintext, std::string key)
{
    std::string result;
    size_t key_size = key.size();
    size_t key_index = 0;
    for (char c : plaintext)
    {
        if (isalpha(c))
        {
            char moving_value = toupper(key[key_index % key_size]) - 65;
            if (isalpha(c))
            {
                result += caesar_encrypt(std::string(1, c), moving_value);
                key_index++;
            }
        }
        else
        {
            result += c;
        }
    }
    return result;
}

std::string vigenere_decrypt(std::string plaintext, std::string key)
{
    std::string result;
    size_t key_size = key.size();
    size_t key_index = 0;
    for (char c : plaintext)
    {
        if (isalpha(c))
        {
            char moving_value = toupper(key[key_index % key_size]) - 65;
            if (isalpha(c))
            {
                result += caesar_decrypt(std::string(1, c), moving_value);
                key_index++;
            }
        }
        else
        {
            result += c;
        }
    }
    return result;
}

std::string handle_caesar_encrypt()
{
    int shifting_value;
    std::string encrypted_text;
    std::string text;
    clear_screen();
    display_ascii_art();
    std::cout << "Insert the text you wish to encrypt: ";
    std::getline(std::cin, text);
    std::cout << "Insert the shifting value: ";
    std::cin >> shifting_value;
    std::cout << "The following text, '" << text << "', will be encrypted by shifting " << shifting_value << " positions." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    encrypted_text = caesar_encrypt(text, shifting_value);
    std::cout << "The text was encrypted successfully: '" << encrypted_text << "'" << std::endl;
    std::cout << std::endl;
    return encrypted_text;
}

std::string handle_caesar_decrypt()
{
    int shifting_value;
    std::string decrypted_text;
    std::string text;
    clear_screen();
    display_ascii_art();
    std::cout << "Insert the text you wish to decrypt: ";
    std::getline(std::cin, text);
    std::cout << "Insert the shifting value: ";
    std::cin >> shifting_value;
    std::cout << "The following text, '" << text << "', will be decrypted by shifting " << shifting_value << " positions." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    decrypted_text = caesar_decrypt(text, shifting_value);
    std::cout << "The text was decrypted successfully: '" << decrypted_text << "'" << std::endl;
    std::cout << std::endl;
    return decrypted_text;
}

std::string handle_vigenere_encrypt()
{
    std::string text;
    std::string key;
    std::string encrypted_text;
    clear_screen();
    display_ascii_art();
    std::cout << "Insert the text you wish to encrypt: ";
    std::getline(std::cin, text);
    std::cout << "Insert the key: ";
    std::getline(std::cin, key);
    key = clean_key(key);
    std::cout << "The following text, '" << text << "', will be encrypted by using the key " << key << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    encrypted_text = vigenere_encrypt(text, key);
    std::cout << "The text was encrypted successfully: '" << encrypted_text << "'" << std::endl;
    std::cout << std::endl;
    return encrypted_text;
}

std::string handle_vigenere_decrypt()
{
    std::string text;
    std::string key;
    std::string decrypted_text;
    clear_screen();
    display_ascii_art();
    std::cout << "Insert the text you wish to decrypt: ";
    std::getline(std::cin, text);
    std::cout << "Insert the key: ";
    std::getline(std::cin, key);
    key = clean_key(key);
    std::cout << "The following text, '" << text << "', will be decrypted by using the key " << key << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    decrypted_text = vigenere_decrypt(text, key);
    std::cout << "The text was decrypted successfully: '" << decrypted_text << "'" << std::endl;
    std::cout << std::endl;
    return decrypted_text;
}

void main_handle_vigenere_chiper()
{
    int choice;
    bool flag = true;
    
    while (flag)
    {
        display_action_menu();
        std::cin >> choice;
        std::cin.ignore();
        
        switch (choice) {
            case 1:
                handle_vigenere_encrypt();
                break;
            case 2:
                handle_vigenere_decrypt();
                break;
            case 3:
                clear_screen();
                return;
            default:
                exit(0);
        }
        post_action_menu();
        std::cin >> choice;
        switch (choice)
        {
            case 1:
                flag = true;
                break;
            case 2:
                clear_screen();
                return;
            default:
                exit(0);
        }
    }
}

void main_handle_caesar_cipher()
{
    int choice;
    bool flag = true;

    while (flag)
    {
        display_action_menu();
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                handle_caesar_encrypt();
                break;
            case 2:
                handle_caesar_decrypt();
                break;
            case 3:
                clear_screen();
                return;
            default:
                exit(0);
        }
        post_action_menu();
        std::cin >> choice;
        switch (choice)
        {
            case 1:
                flag = true;
                break;
            case 2:
                clear_screen();
                return;
            default:
                exit(0);
        }
    }
}

int main()
{
    bool flag = true;

    while (flag)
    {
        int method_choice;
        display_method_menu();
        std::cin >> method_choice;
        switch (method_choice)
        {
            case 1:
                main_handle_caesar_cipher();
                break;
            case 2:
                main_handle_vigenere_chiper();
                break;
            case 0:
                flag = false;
                break;
            default:
                std::cout << "Optiune invalida" << std::endl;
                flag = false;
                break;
        }
    }
}
