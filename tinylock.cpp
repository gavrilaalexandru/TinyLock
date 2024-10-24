#include <iostream>
#include "tinylock.h"

// adauga nume random si animate + criptate
// adauga mai multe methode de criptare

void set_console_title(const std::string& title) // nu stiu daca are sens
{
	system(("title " + title).c_str());
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
	display_ascii_art();
	std::cout << "Select a method:" << std::endl;
	std::cout << "1) Basic Caesar Cipher" << std::endl;
	std::cout << "2. Advanced Caesar Cipher" << std::endl;
	std::cout << "0) Exit" << std::endl;
	std::cout << "> ";
}

void display_action_menu()
{
	system("cls");
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

void set_random_title()
{
	std::vector<std::string> titles =
	{
		"alex",
		"cox.",
		"vali",
		"doha",
		"rcvo",
		"p123",
		"alon"
	};
	std::srand(static_cast<unsigned int>(std::time(0)));
	while (true)
	{
		std::shuffle(titles.begin(), titles.end(), std::default_random_engine(std::rand()));

		for (const std::string& selectedName : titles)
		{
			std::string encryptedName = caesar_encrypt(selectedName, 69);
			std::string title = "tinylock by " + encryptedName;
			set_console_title(title);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}
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


std::string handle_caesar_encrypt()
{
	int shifting_value;
	std::string encrypted_text;
	std::string text;
	system("cls");
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
	system("cls");
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


void main_handle_caesar_cipher()
{
	int choice;
	int shifting_value;
	std::string text;
	bool flag = true;

	while (flag)
	{
		display_action_menu();
		std::cin >> choice;
		std::cin.ignore();

		if (choice == 1)
		{
			handle_caesar_encrypt();
		}
		else if (choice == 2)
		{
			handle_caesar_decrypt();
		}
		else if (choice == 3)
		{
			system("cls");
			return;
		}
		else if (choice == 0)
		{
			flag = false;
			exit(0);
		}
		else
		{
			exit(0);
		}

		post_action_menu();
		std::cin >> choice;
		if (choice == 1)
		{
			flag = true;
		}

		else if (choice == 2)
		{
			system("cls");
			return;
		}

		else if (choice == 0)
		{
			exit(0);
		}
		else
		{
			exit(0);
		}
	}
}

int main()
{
	std::cout << "test" << std::endl;
	std::thread titleThread(set_random_title);
	titleThread.detach();
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
			std::cout << "Neimplementat!" << std::endl;
			flag = false;
			break;
		case 0:
			flag = false;
			break;
		default:
			std::cout << "Optiune nevalida" << std::endl;
			flag = false;
			break;
		}
	}
}