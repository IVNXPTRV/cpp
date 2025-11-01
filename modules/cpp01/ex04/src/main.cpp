#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

bool isValidInput(int argc) {
  if (argc != 4) {
    std::cout << "Usage: filename old_string new_string" << std::endl;
    return false;
  } else
    return true;
}

bool readContent(char *filename, std::string &content) {
  std::ifstream infile(filename);
  std::string line;

  if (infile.fail()) {
    std::cout << "Failed to open '" << filename << "'" << std::endl;
    return false;
  }
  while (std::getline(infile, line)) {
    if (!infile.eof()) line = line + "\n";
    content += line;
  }
  infile.close();
  return true;
}

bool writeContent(std::string filename, std::string &content) {
  std::ofstream outfile((filename + ".replace").c_str());

  if (outfile.fail()) {
    std::cout << "Failed to open '" << filename + ".replace" << "'"
              << std::endl;
    return false;
  }
  outfile << content;
  outfile.close();
  return true;
}

void replace(std::string &newContent, std::string oldString,
             std::string newString) {
  size_t newStart;
  size_t oldStart;
  std::string oldContent(newContent);

  if (oldString.empty()) return;
  newContent.erase();
  oldStart = 0;
  while (true) {
    newStart = oldContent.find(oldString, oldStart);
    newContent += oldContent.substr(oldStart, newStart - oldStart);
    if (newStart == std::string::npos) break;
    newContent += newString;
    oldStart = newStart + oldString.length();
  }
}

int main(int argc, char *argv[]) {
  std::string content = "";

  if (!isValidInput(argc)) return EXIT_FAILURE;
  if (!readContent(argv[1], content)) return EXIT_FAILURE;
  replace(content, argv[2], argv[3]);
  if (!writeContent(argv[1], content)) return EXIT_FAILURE;
  return EXIT_SUCCESS;
}
