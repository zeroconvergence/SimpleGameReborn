#pragma once
#include <filesystem>
#include <fstream>
#include <limits>

namespace fs = std::filesystem;

using std::string;
using std::cout;
using std::ifstream;

void FReadFile(std::string filename) {
	if (fs::exists(filename) && fs::is_regular_file(filename)) {
		string text;
		ifstream file(filename);

		while (getline(file, text)) {
			cout << text << "\n";
		}
		file.close();
	}
}

std::fstream& GoToASpecificLine(std::fstream& filename, unsigned int line) {
	filename.seekg(std::ios::beg);
	for (int i = 0; i < line - 1; i++) {
		filename.ignore(1000, '\n');
	}
	return filename;
}

