#pragma once
#include <string>

void set_console_title(const std::string& title);
void display_ascii_art();
void display_menu();
void display_action_menu();
void post_action_menu();
std::string caesar_encrypt(std::string text, int shifting_value);
std::string caesar_decrypt(std::string text, int shifting_value);
std::string clean_key(const std::string& key);
std::string vigenere_encrypt(std::string plaintext, std::string key);
std::string vigenere_decrypt(std::string plaintext, std::string key);
std::string handle_caesar_encrypt();
std::string handle_caesar_decrypt();
std::string handle_vigenere_encrypt();
std::string handle_vigenere_decrypt();
void main_handle_caesar_chiper();
void main_handle_vigenere_chiper();
