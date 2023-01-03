#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include "FileReader.h"
#include "IP.h"

// Input & Output
using std::cout;
using std::cin;
using std::cout;
using std::string;

// Fstream
using std::fstream;
using std::ofstream;
using std::ifstream;

// Boost File System
namespace fs = std::filesystem;

int main()
{
	const string NEW_LINE = "\n";
	const string USER_DATA = "data";
	const string USER_DATA2 = "data/";

	const string USER_DATA3 = "data/";

	if (fs::exists(USER_DATA) && fs::is_directory(USER_DATA) && fs::is_empty(USER_DATA)) {
		if (fs::remove_all(USER_DATA));
	}

	cout << "Welcome, Guest." << NEW_LINE;

	cout << "Enter username: " << NEW_LINE;
	string username;
	cin >> username;

	cout << "Enter password: " << NEW_LINE;
	string password;
	cin >> password;

	if (fs::exists(USER_DATA) && fs::is_directory(USER_DATA) && fs::exists(USER_DATA2 + username + ".txt")) {
		fstream file(USER_DATA2 + username + ".txt");
		GoToASpecificLine(file, 1);
		string user;
		file >> user;

		if (username == user) {
			GoToASpecificLine(file, 2);
			string pass;
			file >> pass;

			if (password == pass) {
				system("cls");
				cout << "Initializing system..." << NEW_LINE;
				cout << "Welcome, " << username << "." << NEW_LINE;

				cout << "Enter commands: " << NEW_LINE;
				string commands;
				cin >> commands;

				if (commands == "/help" || commands == "0") {
					cout << "/date" << NEW_LINE;
				}

				if (commands == "/date") {
					cout << "January 26, 2034 1:15 PM" << NEW_LINE;
				}

				if (commands == "/ip") {
					if (fs::exists(USER_DATA2 + "ip.txt")) {
						FReadFile(USER_DATA2 + "ip.txt");
					}

					else {
						AssignIP();
					}
				}

				if (commands == "/scan") {
					ofstream scan("scan.txt");
					//scan << username << "'s Battlestation@" << FReadFile(USER_DATA2 + "ip.txt");
					scan.close();
				}
			}
		}
	}

	else {
		if (username.length() < 4 || password.length() < 8 && username.length() < 4 && password.length() < 8) {
			cout << "Username and password are too weak. Do you really want to proceed?" << NEW_LINE;
			int proceed;
			cin >> proceed;

			if (proceed == 1) {
				system("cls");
				cout << "Creating account..." << NEW_LINE;

				if (fs::create_directory(USER_DATA)) {
					ofstream user(USER_DATA2 + username + ".txt");
					user << username << NEW_LINE;
					user << password << NEW_LINE;
					user.close();
				}

				else {
					cout << "Could not create account. " << GetLastError();
				}
			}

			else {
				cout << "Closing..." << NEW_LINE;
			}
		}

		else {
			system("cls");
			cout << "Creating account..." << NEW_LINE;

			if (fs::create_directory(USER_DATA)) {
				ofstream user(USER_DATA2 + username + ".txt");
				user << username << NEW_LINE;
				user << password << NEW_LINE;
				user.close();
			}

			else {
				cout << "Could not create account. Error code: " << GetLastError();
			}
		}
	}
	system("pause");
}