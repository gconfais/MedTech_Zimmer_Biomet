#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

const std::string INVERTED_ARG = "-i";
const std::string REMOVE_DUPLICATE_ARG = "-rmvd";
const std::string HELP_TEXT = "Wrong command. Help :\n$> MzbTest.exe \"a list of words\" [-i] [-rmvd]\n\t[-i]\tOptional. Inverse Alphabetical Order.\n\t[-rmvd]\tOptional. Remove duplicates.";

bool invertedStringCompare(std::string a, std::string b) { return a > b; }

int main(int argc, char* argv[])
{
	if (argc < 2 || argc > 4)
	{
		std::cout << HELP_TEXT << std::endl;
		return -1;
	}

	// many other checks to do
	// we could also create an option -input:"path/to/file.txt" and log in an output file like "path/to/file_sorted.txt" 
	// and even an "-output:path/to/file_sorted.txt" option to enhance by a lot the user experience,
	// no need to type the words to sort every time you call the app => use a file.

	std::string words = argv[1];
	std::string arg2 = argc > 2 ? argv[2] : "";
	std::string arg3 = argc > 3 ? argv[3] : "";

	bool inverted = arg2 == INVERTED_ARG || arg3 == INVERTED_ARG;
	bool remove_duplicate = arg2 == REMOVE_DUPLICATE_ARG || arg3 == REMOVE_DUPLICATE_ARG;

	std::stringstream strstream(words);
	std::string word;
	std::vector<std::string> word_list;

	while (strstream >> word)
	{
		if (remove_duplicate && std::count(word_list.begin(), word_list.end(), word))
			continue;

		word_list.push_back(word);
	}

	if (inverted)
		std::sort(word_list.begin(), word_list.end(), invertedStringCompare);
	else
		std::sort(word_list.begin(), word_list.end());

	std::cout << "Result :" << std::endl;
	for (auto w : word_list)
		std::cout << "\t" << w << std::endl;
}