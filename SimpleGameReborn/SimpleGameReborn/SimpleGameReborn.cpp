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
				cout << "Logging in..." << NEW_LINE;
				cout << "Initializing system..." << NEW_LINE;
				if (!fs::exists(USER_DATA2 + "ip.txt")) {
					cout << "Assigning IP..." << NEW_LINE;
					AssignIP();
				}
				
				cout << "Welcome, " << username << "." << NEW_LINE;

				string commands;
				cout << "Enter commands: " << NEW_LINE;
				cin.ignore();
				std::getline(cin, commands);

				if (commands == "/help" || commands == "0") {
					cout << "/date" << NEW_LINE;
				}

				if (commands == "/ls -all") {
					cout << "Available directories: " << NEW_LINE;
					cout << "/system" << NEW_LINE;
					cout << "/programs" << NEW_LINE;
					cout << "/downloads" << NEW_LINE;
					cout << "/temp" << NEW_LINE;

					cout << NEW_LINE;

					string directory;
					cout << "Enter directory: " << NEW_LINE;
					cin.clear();
					cin.sync();
					std::getline(cin, directory);

					if (directory == "/ls system") {
						cout << "Retrieving list of directory..." << NEW_LINE;
						Sleep(3 * 1000);
						cout << "bootloader.exe" << NEW_LINE;
						cout << "OS.dll" << NEW_LINE;
						cout << "security.dll" << NEW_LINE;
						cout << "mgr.exe" << NEW_LINE;
					}

					if (directory == "/ls programs") {
						cout << "Retrieving list of directory..." << NEW_LINE;
						Sleep(2 * 1000);
						cout << "TCPCrack.exe" << NEW_LINE;
						cout << "UDPFlooder.exe" << NEW_LINE;
						cout << "SSHOverflow.exe" << NEW_LINE;
						cout << "FTPDta.exe" << NEW_LINE;
					}

					if (directory == "/ls downloads") {
						cout << "Empty" << NEW_LINE;
					}

					if (directory == "/ls temp") {
						srand(time(0));
						string temp[5] = { "TCD1AA" + rand() % 50, "TCD1AB" + rand() % 49, "TCD1AC" + rand() % 48, "TCD1AX" + rand() % 47, "TCD14AD" + rand() % 46 };
						
						for (int i = 0; i < sizeof(temp) / sizeof(string); i++) {
							cout << temp[i] << NEW_LINE;
						}
					}
				}

				if (commands == "/date") {
					cout << "January 26, 2034 1:15 PM" << NEW_LINE;
				}

				if (commands == "/ip") {
					if (fs::exists(USER_DATA2 + "ip.txt")) {
						cout << username << "'s Battlestation@";
						FReadFile(USER_DATA2 + "ip.txt");
						cout << "Test Server@193.50.23.26" << NEW_LINE;
					}

					else {
						cout << "Coult not fetch IP" << NEW_LINE;
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

				cout << "Restart the system to log in" << NEW_LINE;
			}

			else {
				cout << "Could not create account. Error code: " << GetLastError();
			}
		}
	}
	system("pause");
}