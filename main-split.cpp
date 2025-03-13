#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

/// @brief Reads a file an makes a vector that of the full, unaltered lines of the file.
/// @param fileName Name of the file to read.
/// @return Vector of full extracted lines.
std::vector<std::string> readFile(const std::string &fileName) {
    std::vector<std::string> fullLines;
    
    // Constructor opens file
    std::ifstream file(fileName);
    if (!file.is_open()) {
        std::cout << "Problem opening file. Check file name and if it exists inside this directory." << std::endl;
        file.close();
        return fullLines;
    }

    // Get full lines
    std::string readLine;
    while (std::getline(file, readLine)) 
        fullLines.push_back(readLine);
    
    file.close();

    // Check for valid file length
    if (fullLines.size() == 2 || fullLines.empty())
        std::cout << "Invalid number of lines. Need at least 3 for a valid pyramid." << std::endl;

    return fullLines; // Full extracted lines: ["1 love", "23 kitten", "400 boat"]
}

/// @brief Makes a decode key and maps lines to their numbers for easy look-up.
/// @param fullLines All complete, unparsed lines of a file.
/// @param mappedLines Map of words to their coded number values.
/// @return The decode key of all the last numbers in each pyramid row.
std::pair< std::vector<std::string>, std::unordered_map<std::string, std::string> > makeDecodeKey(const std::vector<std::string> &fullLines) {
    std::vector<std::string> nums;
    std::unordered_map<std::string, std::string> mappedLines;

    // Get all nums
    for (int i = 0; i < fullLines.size(); i++) {
        std::string currentLine = fullLines[i];
        
        std::string::iterator endOfNum = std::find_if(currentLine.begin(), currentLine.end(), ::isspace); // Iterator to exclusive end of num
        std::string fullNum(currentLine.begin(), endOfNum); // Make string from begin to end of each line's num

        std::string::iterator startOfWord = std::find_if(currentLine.begin(), currentLine.end(), ::isspace) + 1; // Iterator to the start of word after whitespace
        std::string fullWord(startOfWord, currentLine.end());

        mappedLines.emplace(fullNum, fullWord);
        nums.push_back(fullNum);
    }
    
    // Sort each line's full num, ["5", "32", "236"]
    std::sort(nums.begin(), nums.end(),
        [](const std::string &a, const std::string &b) { 
            return std::stoi(a) < std::stoi(b);
        }
    );

    // Make decode key
    std::vector<std::string> decodeKey;
    int step = 1;
    while (!nums.empty()) {
        std::string lastNum = *(nums.begin() + step - 1); // Always gives the last num of each pyramid row
        decodeKey.push_back(lastNum);

        nums.erase(nums.begin(), nums.begin() + step); // Remove pyramid row section
        step++;
    }

    std::pair< std::vector<std::string>, std::unordered_map<std::string, std::string> > result(decodeKey, mappedLines);
    return result;
}

/// @brief Decodes the message of a file.
/// @param message_file Name of the file to decode.
/// @return The final decoded message.
std::string decode(const std::string &message_file) {
    std::vector<std::string> fullLines = readFile(message_file);
    
    auto pair = makeDecodeKey(fullLines);
    std::vector<std::string> decodeKey = pair.first;
    std::unordered_map<std::string, std::string> mappedLines = pair.second;
    
    // Decode
    std::string result;
    for (int i = 0; i < decodeKey.size(); i++) {
        std::string targetWord = mappedLines.at(decodeKey[i]);
        i == fullLines.size() - 1 ? result += targetWord : result += targetWord + ' ';
    }

    return result;
}

int main (int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Invalid number of args. Enter only the input file name." << std::endl;
        return 0;
    }

    std::string result = decode(argv[1]); // Argv[1] is the file name
    std::cout << result << std::endl;

    return 0;
}
