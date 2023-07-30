#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include <Windows.h>
#include <chrono>
#include <ctime>

#include "FileReader.h"
#include "IP.h"
#include "Servers.h"
#include "Timer.h"
#include "Utils.h"

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
	srand(time(0));

	const string NEW_LINE = "\n";
	const string USER_DATA = "data";
	const string USER_DATA2 = "data/";

	const string USER_DATA3 = "data/";
	const string FILE_SYSTEM = "data/filesystem";
	const string FILE_SYSTEM2 = "data/filesystem/";

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

				fstream OSFileSystem(FILE_SYSTEM2 + "system.txt");
				GoToASpecificLine(OSFileSystem, 1);
				string bootloader;
				OSFileSystem >> bootloader;

				fstream OSFileSystem2(FILE_SYSTEM2 + "system.txt");
				GoToASpecificLine(OSFileSystem2, 2);
				string osdll;
				OSFileSystem2 >> osdll;

				fstream OSFileSystem3(FILE_SYSTEM2 + "system.txt");
				GoToASpecificLine(OSFileSystem3, 3);
				string security;
				OSFileSystem3 >> security;

				fstream OSFileSystem4(FILE_SYSTEM2 + "system.txt");
				GoToASpecificLine(OSFileSystem4, 4);
				string mgr;
				OSFileSystem4 >> mgr;

				if (bootloader != "bootloader.exe") {
					cout << "bootloader.exe [-]" << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "OS.dll [+]" << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "security.dll [+]" << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "mgr.exe [+]" << NEW_LINE;

					cout << "Boot Loader Not Found. Error code: 0xc0000225" << NEW_LINE;

					Sleep(3 * 1000);

					ofstream log(USER_DATA2 + "system.log");
					log << "Boot Loader Not Found. Error code: 0xc0000225" << NEW_LINE;
					log << "Create a new account to continue" << NEW_LINE;
					log.close();

					exit(125);
				}

				if (osdll != "OS.dll") {
					cout << "bootloader.exe [+]" << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "OS.dll [-]" << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "security.dll [+]" << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "mgr.exe [+]" << NEW_LINE;

					cout << "Missing OS. Error code: 0xc0001331" << NEW_LINE;

					Sleep(3 * 1000);

					ofstream log(USER_DATA2 + "system.log");
					log << "Missing OS. Error code: 0xc0001331" << NEW_LINE;
					log << "Create a new account to continue" << NEW_LINE;
					log.close();

					exit(343);
				}

				if (security != "security.dll") {
					cout << "bootloader.exe [+]" << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "OS.dll [+]" << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "security.dll [-]" << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "mgr.exe [+]" << NEW_LINE;

					cout << "Security File Not Found. Error code: 0xc0201980" << NEW_LINE;

					Sleep(3 * 1000);

					ofstream log(USER_DATA2 + "system.log");
					log << "Security File Not Found. Error code: 0xc0201980" << NEW_LINE;
					log << "Create a new account to continue" << NEW_LINE;
					log.close();

					exit(215);
				}

				if (mgr != "mgr.exe") {
					cout << "bootloader.exe [+]" << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "OS.dll [+]" << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "security.dll [+]" << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "mgr.exe [-]" << NEW_LINE;

					cout << "OS Manager Missing. Error code: 0xfa020150" << NEW_LINE;

					Sleep(3 * 1000);

					ofstream log(USER_DATA2 + "system.log");
					log << "OS Manager Missing. Error code: 0xfa020150" << NEW_LINE;
					log << "Create a new account to continue" << NEW_LINE;
					log.close();

					exit(661);
				}

				cout << "bootloader.exe [+]" << NEW_LINE;
				Sleep(1 * 1000);
				cout << "OS.dll [+]" << NEW_LINE;
				Sleep(1 * 1000);
				cout << "security.dll [+]" << NEW_LINE;
				Sleep(1 * 1000);
				cout << "mgr.exe [+]" << NEW_LINE;

				system("cls");

				if (fs::exists(USER_DATA2 + "config.ini") && !fs::is_empty(USER_DATA2 + "config.ini")) {
					fstream OSConfig(USER_DATA2 + "config.ini");
					GoToASpecificLine(OSConfig, 1);
					string accountpassword;
					OSConfig >> accountpassword;

					if (accountpassword == "ResetAccountPassword:True") {
						cout << "Enter new password: " << NEW_LINE;
						string newpassword;
						cin >> newpassword;

						if (newpassword.length() > 8) {
							cout << "Resetting user account password..." << NEW_LINE;

							ofstream userfile(USER_DATA2 + username + ".txt", std::ios::trunc);
							userfile << username << NEW_LINE;
							userfile << newpassword;

							userfile.close();

							cout << "Account password has been reset" << NEW_LINE;

							ofstream userconfig(USER_DATA2 + "config.ini", std::ios::trunc);
							userconfig << "ResetAccountPassword:False";
							userconfig.close();

							system("SimpleGameReborn.exe");
							exit(0);
						}

						else {
							cout << "Password must be between 8-30 characters" << NEW_LINE;
						}
					}

					if (accountpassword == "ResetAccountPassword:False") {

					}
				}

				cout << "Logging in..." << NEW_LINE;
				cout << "Initializing system..." << NEW_LINE;
				if (!fs::exists(USER_DATA2 + "ip.txt")) {
					cout << "Assigning IP..." << NEW_LINE;
					AssignIP();
				}

				file.close();
				OSFileSystem.close();
				OSFileSystem2.close();
				OSFileSystem3.close();
				OSFileSystem4.close();

				cout << "Welcome, " << username << "." << NEW_LINE;

				//NormalTracker();

				string commands;
				cout << "Enter commands: " << NEW_LINE;
				cin.ignore();
				std::getline(cin, commands);

				if (commands == "/settings") {
					cout << "Choose category: " << NEW_LINE;
					std::string category;
					cin >> category;

					if (is_int(category)) {
						if (category == "0") {
							cout << "[0] - Categories List" << NEW_LINE;
							cout << "[1] - System Settings" << NEW_LINE;
							cout << "[2] - Exit" << NEW_LINE;
							system("SimpleGameReborn.exe");
							exit(0);
						}

						if (category == "1") {
							cout << "1 - Reset account password" << NEW_LINE;

							cout << "Choose setting: " << NEW_LINE;
							int setting;
							cin >> setting;

							if (setting == 1) {
								ofstream config(USER_DATA2 + "config.ini", std::ios::beg);
								config << "ResetAccountPassword:True" << NEW_LINE;
								config.close();

								system("SimpleGameReborn.exe");
								exit(0);
							}
						}

						if (category == "2") {
							system("SimpleGameReborn.exe");
							exit(0);
						}

						else {
							cout << "Category " << category << " does not exist" << NEW_LINE;
							system("SimpleGameReborn.exe");
							exit(0);
						}
					}

					else {
						cout << "Entered input is not a digit" << NEW_LINE;
						system("SimpleGameReborn.exe");
						exit(0);
					}
				}

				if (commands == "/help" || commands == "0") {
					cout << "/date" << NEW_LINE;

					cout << "/ls -all" << NEW_LINE;
					cout << "/ls system" << NEW_LINE;
					cout << "/ls programs" << NEW_LINE;
					cout << "/ls downloads" << NEW_LINE;

					cout << "/scp <filename>" << NEW_LINE;
					cout << "/del <filename>" << NEW_LINE;
					cout << "/ren <filename>" << NEW_LINE;

					cout << "/settings" << NEW_LINE;
				}

				if (commands == "/ls -all") {
					cout << "Available directories: " << NEW_LINE;
					cout << "/system" << NEW_LINE;
					cout << "/programs" << NEW_LINE;
					cout << "/downloads" << NEW_LINE;

					cout << NEW_LINE;

					cout << "Enter directory: " << NEW_LINE;
					string directory;
					cin.clear();
					cin.sync();
					std::getline(cin, directory);

					if (directory == "/ls system") {
						cout << "Retrieving list of directory..." << NEW_LINE;
						Sleep(3 * 1000);
						FReadFile(FILE_SYSTEM2 + "system.txt");

						cout << "Enter commands: " << NEW_LINE;
						string systemcommands;
						std::getline(cin, systemcommands);

						if (systemcommands == "/del bootloader.exe") {
							cout << "You are about to delete system file. Are you sure?" << NEW_LINE;
							string deletingchoice;
							cin >> deletingchoice;

							if (is_int(deletingchoice)) {
								if (deletingchoice == "1") {
									if (fs::exists(FILE_SYSTEM2 + "system.txt")) {
										if (fs::remove(FILE_SYSTEM2 + "system.txt"));
										ofstream systemfile(FILE_SYSTEM2 + "system.txt");
										systemfile << "OS.dll" << NEW_LINE;
										systemfile << "security.dll" << NEW_LINE;
										systemfile << "mgr.exe";
										systemfile.close();
									}

									else {
										ofstream systemfile(FILE_SYSTEM2 + "system.txt");
										systemfile << "OS.dll" << NEW_LINE;
										systemfile << "security.dll" << NEW_LINE;
										systemfile << "mgr.exe";
										systemfile.close();
									}
								}

								if (deletingchoice == "0") {
									system("SimpleGameReborn.exe");
									exit(0);
								}

								else {
									cout << "Entered input is not a digit" << NEW_LINE;
								}
							}
						}

						if (systemcommands == "/del OS.dll") {
							cout << "You are about to delete system file. Are you sure?" << NEW_LINE;
							string choice;
							cin >> choice;

							if (is_int(choice)) {
								if (choice == "1") {
									ofstream systemfile(FILE_SYSTEM2 + "system.txt");
									systemfile << "bootloader.exe" << NEW_LINE;
									systemfile << "OS.dll" << NEW_LINE;
									systemfile << "security.dll" << NEW_LINE;
									systemfile << "mgr.exe";
									systemfile.close();

									system("SimpleGameReborn.exe");
									exit(0);
								}

								if (choice == "0") {
									system("SimpleGameReborn.exe");
									exit(0);
								}

								else {
									cout << "Entered input is not a digit" << NEW_LINE;
								}
							}
						}

						if (systemcommands == "/del security.dll") {
							cout << "You are about to delete system file. Are you sure?" << NEW_LINE;
							string choice;
							cin >> choice;

							if (is_int(choice)) {
								if (choice == "1") {
									ofstream systemfile(FILE_SYSTEM2 + "system.txt");
									systemfile << "bootloader.exe" << NEW_LINE;
									systemfile << "OS.dll" << NEW_LINE;
									systemfile << "mgr.exe";
									systemfile.close();

									system("SimpleGameReborn.exe");
									exit(0);
								}

								if (choice == "0") {
									system("SimpleGameReborn.exe");
									exit(0);
								}

								else {
									cout << "Entered input is not a digit" << NEW_LINE;
								}
							}
						}

						if (systemcommands == "/del mgr.exe") {
							cout << "You are about to delete system file. Are you sure?" << NEW_LINE;
							string choice;
							cin >> choice;

							if (is_int(choice)) {
								if (choice == "1") {
									ofstream systemfile(FILE_SYSTEM2 + "system.txt");
									systemfile << "bootloader.exe" << NEW_LINE;
									systemfile << "security.dll" << NEW_LINE;
									systemfile << "OS.dll";
									systemfile.close();

									system("SimpleGameReborn.exe");
									exit(0);
								}

								if (choice == "0") {
									system("SimpleGameReborn.exe");
									exit(0);
								}

								else {
									cout << "Entered input is not a digit" << NEW_LINE;
								}
							}
						}

						system("SimpleGameReborn.exe");
						exit(0);
					}

					if (directory == "/ls programs") {
						cout << "Retrieving list of directory..." << NEW_LINE;
						Sleep(2 * 1000);
						FReadFile(FILE_SYSTEM2 + "programs.txt");

						system("SimpleGameReborn.exe");
						exit(0);
					}

					if (directory == "/ls downloads") {
						system("cls");
						cout << "Retrieving list of directory..." << NEW_LINE;
						Sleep(2 * 500);
						FReadFile(FILE_SYSTEM2 + "downloads.txt");

						cout << "Enter commands: " << NEW_LINE;
						string hostcommands;
						cin.clear();
						cin.sync();
						std::getline(cin, hostcommands);

						if (hostcommands == "/del 0_234186.exe") {
							fstream file(FILE_SYSTEM + "downloads.txt");
							GoToASpecificLine(file, 2);
							string pfile;
							file >> pfile;

							if (pfile == "0_234186.exe") {
								ofstream downloads(FILE_SYSTEM2 + "downloads.txt", std::ios::trunc);
								downloads << "Empty" << NEW_LINE;
								downloads.close();

								system("SimpleGameReborn.exe");
								exit(0);
							}

							else {
								cout << "File not found" << NEW_LINE;
								exit(0);
							}
						}

						if (hostcommands == "0_234186.exe") {
							fstream OSDownloads(FILE_SYSTEM2 + "downloads.txt");
							GoToASpecificLine(OSDownloads, 1);
							string file;
							OSDownloads >> file;

							if (file == "0_234186.exe") {
								cout << "This file was downloaded using an insecure connection. Would you like to continue?" << NEW_LINE;
								int download;
								cin >> download;

								switch (download) {
								case 1: {
									cout << rand() % 10000 << rand() % 1000 << rand() % 100 << NEW_LINE;
									Sleep(2.5 * 1000);
									cout << rand() % 9999 << rand() % 999 << rand() % 99 << NEW_LINE;

									cout << NEW_LINE;

									ofstream system(FILE_SYSTEM2 + "system.txt", std::ios::trunc);
									system << "OS.dll" << NEW_LINE;
									system << "security.dll" << NEW_LINE;
									system << "mgr.exe";
									system.close();

									cout << "An error has occurred. Quitting..." << NEW_LINE;
									Sleep(2 * 1000);
									exit(1);
								}

								case 0: {
									cout << "Restarting..." << NEW_LINE;
									system("SimpleGameReborn.exe");
									exit(0);
								}
								}
							}
						}

						if (hostcommands == "grocery.docx") {
							fstream OSDownloads2(FILE_SYSTEM2 + "downloads.txt");
							GoToASpecificLine(OSDownloads2, 2);
							string file2;
							OSDownloads2 >> file2;

							if (file2 == "grocery.docx") {
								Sleep(2 * 1000);

								cout << "1. J-Cola" << NEW_LINE;
								cout << "2. 4 Eggs" << NEW_LINE;
								cout << "3. Sugar" << NEW_LINE;
								cout << "4. Snacks" << NEW_LINE;
								cout << "5. 5 Apples" << NEW_LINE;
								cout << "5. 2 Oranges" << NEW_LINE;
							}

							else {
								cout << "File " << hostcommands << " not found" << NEW_LINE;
							}
						}
					}
				}

				if (commands == "/date") {
					if (!fs::exists(USER_DATA2 + "config.ini")) {
						cout << "Choose preferred date format: " << NEW_LINE;
						string dateformat;
						cin >> dateformat;

						if (dateformat == "0") {
							cout << "US, UK, ISO 8601" << NEW_LINE;
						}

						if (dateformat == "US") {
							ofstream config(USER_DATA2 + "config.ini");
							config << "DateFormat:US" << NEW_LINE;
							config.close();
						}

						if (dateformat == "UK") {
							ofstream config(USER_DATA2 + "config.ini");
							config << "DateFormat:UK" << NEW_LINE;
							config.close();
						}

						if (dateformat == "ISO8601" || dateformat == "8601") {
							ofstream config(USER_DATA2 + "config.ini");
							config << "DateFormat:ISO8601" << NEW_LINE;
							config.close();
						}
					}

					else {
						fstream config(USER_DATA2 + "config.ini");
						GoToASpecificLine(config, 1);
						string date;
						config >> date;

						if (date == "DateFormat:US") {
							auto t = std::time(nullptr);
							auto tm = *std::localtime(&t);
							system("cls");

							cout << "January 26, 2034 " << std::put_time(&tm, "%H:%M:%S PT") << NEW_LINE;
							Sleep(2 * 2000);
							system("SimpleGameReborn.exe");
							exit(0);
						}

						if (date == "DateFormat:UK") {
							auto t = std::time(nullptr);
							auto tm = *std::localtime(&t);
							system("cls");

							cout << "26 January 2034 " << std::put_time(&tm, "%H:%M:%S") << NEW_LINE;
							Sleep(2 * 2000);
							system("SimpleGameReborn.exe");
							exit(0);
						}

						if (date == "DateFormat:ISO8601") {
							auto t = std::time(nullptr);
							auto tm = *std::localtime(&t);
							system("cls");

							cout << "2034-01-26 " << std::put_time(&tm, "%H:%M:%S") << NEW_LINE;
							Sleep(2 * 2000);
							system("SimpleGameReborn.exe");
							exit(0);
						}
					}
				}

				if (commands == "/date change") {
					cout << "Choose preferred date format: " << NEW_LINE;
					string dateformat;
					cin >> dateformat;

					fstream config(USER_DATA2 + "config.ini");
					GoToASpecificLine(config, 1);
					string date;
					config >> date;

					if (date == "DateFormat:US") {
						if (dateformat == "UK") {
							ofstream config(USER_DATA2 + "config.ini", std::ios::trunc);
							config << "DateFormat:UK" << NEW_LINE;
							config.close();
						}
					}

					if (date == "DateFormat:UK") {
						if (dateformat == "US") {
							ofstream config(USER_DATA2 + "config.ini", std::ios::trunc);
							config << "DateFormat:US" << NEW_LINE;
							config.close();
						}
					}

					if (date == "DateFormat:ISO8601") {
						if (dateformat == "US") {
							ofstream config(USER_DATA2 + "config.ini", std::ios::trunc);
							config << "DateFormat:US" << NEW_LINE;
							config.close();
						}

						if (dateformat == "UK") {
							ofstream config(USER_DATA2 + "config.ini", std::ios::trunc);
							config << "DateFormat:UK" << NEW_LINE;
							config.close();
						}
					}
					system("SimpleGameReborn.exe");
					exit(0);
				}

				if (commands == "/ip") {
					if (fs::exists(USER_DATA2 + "ip.txt")) {
						cout << username << "'s Battlestation@";
						FReadFile(USER_DATA2 + "ip.txt");
						system("SimpleGameReborn.exe");
						exit(0);
					}

					else {
						cout << "Could not fetch IP List" << NEW_LINE;
						system("SimpleGameReborn.exe");
						exit(0);
					}
				}

				if (commands == "/scan") {
					cout << "Scanning..." << NEW_LINE;
					Sleep(1.5 * 1000);
					cout << "Test Server@" << TestServerIP << NEW_LINE;
					cout << "ISP Web Server@" << ISPWebServerIP << NEW_LINE;
					system("SimpleGameReborn.exe");
					exit(0);
				}

				if (commands == "/connect") {
					cout << "Enter IP: " << NEW_LINE;
					string ip;
					cin >> ip;

					if (ip == TestServerIP) {
						system("cls");
						cout << "Connected to Test Server@" << TestServerIP << NEW_LINE;
						cout << "Enter commands: " << NEW_LINE;
						string commands2;
						cin.ignore();
						std::getline(cin, commands2);

						if (commands2 == "nmap " + TestServerIP) {
							cout << "Starting Nmap 10.1 at 2034-01-26" << NEW_LINE;
							cout << "Nmap scan report for " << TestServerIP << NEW_LINE;
							cout << "Host is up (0.000" << rand() % 40 << "s latency)" << NEW_LINE;

							cout << "PORT\tSTATE\n";
							cout << "134\tclosed\n";
							cout << "91\tclosed\n";

							cout << "Enter commands: " << NEW_LINE;
							string commands3;
							cin.clear();
							cin.sync();
							std::getline(cin, commands3);

							if (commands3 == "SCracker.exe") {
								fstream programs(FILE_SYSTEM2 + "programs.txt");
								GoToASpecificLine(programs, 1);
								string scracker;
								programs >> scracker;

								if (scracker == "SCracker.exe") {
									cout << "Starting up SCracker..." << NEW_LINE;
									Sleep(2 * 1000);
									cout << "Probing target's port" << NEW_LINE;
									Sleep(2 * 1000);
									cout << "Cracking..." << NEW_LINE;
									Sleep(1.5 * 1000);
									cout << "Port 134 Opened" << NEW_LINE;

									cout << "Enter commands: " << NEW_LINE;
									string commands4;
									cin.clear();
									cin.sync();
									std::getline(cin, commands4);

									if (commands4 == "SCracker.exe") {
										cout << "Starting up SCracker..." << NEW_LINE;
										Sleep(2 * 1000);
										cout << "Probing target's port" << NEW_LINE;
										Sleep(2 * 1000);
										cout << "Cracking..." << NEW_LINE;
										Sleep(1.5 * 1000);
										cout << "Port 91 Opened" << NEW_LINE;

										cout << "Success!";

										if (!fs::exists(USER_DATA2 + "cracked.txt")) {
											ofstream cracked(USER_DATA2 + "cracked.txt");
											cracked << TestServerIP;
											cracked.close();
										}

										system("cls");

										cout << "Enter remote commands: " << NEW_LINE;
										string remotecommands;
										cin.clear();
										cin.sync();
										std::getline(cin, remotecommands);

										if (remotecommands == "nmap " + TestServerIP) {
											cout << "Starting Nmap 10.1 at 2034-01-26" << NEW_LINE;
											cout << "Nmap scan report for " << TestServerIP << NEW_LINE;
											cout << "Host is up (0.000" << rand() % 40 << "s latency)" << NEW_LINE;

											cout << "PORT\tSTATE\n";
											cout << "134\topen\n";
											cout << "91\topen\n";
										}

										if (remotecommands == "/ls -all") {
											cout << "Available directories: " << NEW_LINE;
											cout << "/system" << NEW_LINE;
											cout << "/programs" << NEW_LINE;
											cout << "/downloads" << NEW_LINE;

											cout << NEW_LINE;

											cout << "Enter directory: " << NEW_LINE;
											string directory;
											cin.clear();
											cin.sync();
											std::getline(cin, directory);

											if (directory == "/ls system") {
												cout << "Retrieving list of directory..." << NEW_LINE;
												Sleep(4 * 1000);
												cout << "bootloader.exe" << NEW_LINE;
												cout << "OS.dll" << NEW_LINE;
												cout << "security.dll" << NEW_LINE;
												cout << "mgr.exe" << NEW_LINE;
												system("SimpleGameReborn.exe");
												exit(0);
											}

											if (directory == "/ls programs") {
												cout << "Retrieving list of directory..." << NEW_LINE;
												Sleep(3 * 1000);
												cout << "Empty" << NEW_LINE;
												system("SimpleGameReborn.exe");
												exit(0);
											}

											if (directory == "/ls downloads") {
												cout << "Retrieving list of directory..." << NEW_LINE;
												Sleep(3 * 1000);
												cout << "grocery.docx" << NEW_LINE;
												cout << "0_234186.exe" << NEW_LINE;

												cout << "Enter remote commands: " << NEW_LINE;
												string remotecommands;
												cin.clear();
												cin.sync();
												std::getline(cin, remotecommands);

												if (remotecommands == "/scp 0_234186.exe") {
													cout << "Downloading 0_234186.exe..." << NEW_LINE;
													Sleep(2.5 * 1000);
													cout << "Downloaded!" << NEW_LINE;

													ofstream downloads(FILE_SYSTEM2 + "downloads.txt", std::ios::trunc);
													downloads << "0_234186.exe" << NEW_LINE;
													downloads.close();
													system("SimpleGameReborn.exe");
													exit(0);
												}

												if (remotecommands == "/scp grocery.docx") {
													cout << "Downloading grocery.docx..." << NEW_LINE;
													Sleep(2.5 * 1000);
													cout << "Downloaded!" << NEW_LINE;

													ofstream downloads(FILE_SYSTEM2 + "downloads.txt", std::ios::trunc);
													downloads << "grocery.docx" << NEW_LINE;
													downloads.close();
													system("SimpleGameReborn.exe");
													exit(0);
												}
											}
										}
									}
								}
							}
						}
					}

					if (ip == ISPWebServerIP) {
						system("cls");
						cout << "Connected to ISP Web Server@" << ISPWebServerIP << NEW_LINE;
						cout << "Enter commands: " << NEW_LINE;
						string commands3;
						cin.ignore();
						std::getline(cin, commands3);

						if (commands3 == "nmap " + ISPWebServerIP) {
							cout << "Starting Nmap 10.1 at 2034-01-26" << NEW_LINE;
							cout << "Nmap scan report for " << ISPWebServerIP << NEW_LINE;
							cout << "Host is up (0.000" << rand() % 40 << "s latency)" << NEW_LINE;

							cout << "PORT\tSTATE\n";
							cout << "21\tclosed\n";
							cout << "22\tclosed\n";
							cout << "53\tclosed\n";
							cout << "443\tclosed\n";

							cout << "Unauthorized connection has been detected. Disconnect from the server now." << NEW_LINE;
							cout << "Tracking..." << NEW_LINE;

							NormalTracker();

							cout << "enter";
							string str;
							cin >> str;

						}
					}

					else {
						cout << "Could not find device at " << ip << NEW_LINE;
						system("SimpleGameReborn.exe");
						exit(0);
					}
				}
			}
		}
	}

	else {
		if (username.length() < 4 && password.length() < 8 || username.length() < 4 || password.length() < 8) {
			cout << "Username and password are too weak. Do you really want to proceed?" << NEW_LINE;
			cout << "0 - To not create an account with a weak password" << NEW_LINE;
			cout << "1 - Create an account with a weak password" << NEW_LINE;
			int proceed;
			cin >> proceed;

			switch (proceed) {
			case 1:
				system("cls");
				cout << "Creating account..." << NEW_LINE;

				if (!fs::exists(USER_DATA) && !fs::is_directory(USER_DATA)) {
					if (fs::create_directory(USER_DATA)) {
						ofstream user(USER_DATA2 + username + ".txt");
						user << username << NEW_LINE;
						user << password << NEW_LINE;
						user.close();

						cout << "Restart the system to log in" << NEW_LINE;
						if (fs::create_directory(FILE_SYSTEM)) {
							ofstream system(FILE_SYSTEM2 + "system.txt");
							system << "bootloader.exe" << NEW_LINE;
							system << "OS.dll" << NEW_LINE;
							system << "security.dll" << NEW_LINE;
							system << "mgr.exe";
							system.close();

							ofstream programs(FILE_SYSTEM2 + "programs.txt");
							programs << "SCracker.exe";
							programs.close();

							ofstream downloads(FILE_SYSTEM2 + "downloads.txt");
							downloads << "";
							downloads.close();
							exit(0);
						}
					}
				}

				else {
					ofstream user(USER_DATA2 + username + ".txt");
					user << username << NEW_LINE;
					user << password << NEW_LINE;
					user.close();

					cout << "Restart the system to log in" << NEW_LINE;
					exit(0);
				}
			case 0:
				cout << "Account has not been created. Closing..." << NEW_LINE;
			}
		}

		else {
			system("cls");
			cout << "Creating account..." << NEW_LINE;

			if (!fs::exists(USER_DATA) && !fs::is_directory(USER_DATA)) {
				if (fs::create_directory(USER_DATA)) {
					ofstream user(USER_DATA2 + username + ".txt");
					user << username << NEW_LINE;
					user << password << NEW_LINE;
					user.close();

					cout << "Restart the system to log in" << NEW_LINE;
					if (fs::create_directory(FILE_SYSTEM)) {
						ofstream system(FILE_SYSTEM2 + "system.txt");
						system << "bootloader.exe" << NEW_LINE;
						system << "OS.dll" << NEW_LINE;
						system << "security.dll" << NEW_LINE;
						system << "mgr.exe";
						system.close();

						ofstream programs(FILE_SYSTEM2 + "programs.txt");
						programs << "SCracker.exe";
						programs.close();

						ofstream downloads(FILE_SYSTEM2 + "downloads.txt");
						downloads << "";
						downloads.close();
						exit(0);
					}
				}
			}

			else {
				ofstream user(USER_DATA2 + username + ".txt");
				user << username << NEW_LINE;
				user << password << NEW_LINE;
				user.close();

				cout << "Restart the system to log in" << NEW_LINE;
				exit(0);
			}
		}
	}
	system("pause");
}