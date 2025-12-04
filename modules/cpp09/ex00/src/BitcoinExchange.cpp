#include "BitcoinExchange.hpp"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

const std::string databaseDefaultFilepath = "data.csv";
const std::string inputDefaultFilepath = "input.txt";
std::map<std::string, std::string> BitcoinExchange::database;
std::map<std::string, std::string> BitcoinExchange::input;

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) { (void)other; }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this == &other) return (*this);
  return *this;
}

static inline bool is_not_space(int ch) {
  return !std::isspace(static_cast<unsigned char>(ch));
}

static inline void ltrim(std::string& s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), is_not_space));
}

static inline void rtrim(std::string& s) {
  s.erase(std::find_if(s.rbegin(), s.rend(), is_not_space).base(), s.end());
}

static inline void trim(std::string& s) {
  rtrim(s);
  ltrim(s);
}

static void openFile(std::ifstream& infile, const std::string& filepath) {
  infile.open(filepath.c_str(), std::ios::in);
  if (infile.fail()) throw std::runtime_error("could not open file.");
}
static void split(const std::string& line, const char delim, std::string& key,
                  std::string& value) {
  size_t delimiter_pos = line.find(delim);

  if (delimiter_pos == std::string::npos) {
    key = line;
    value = "";
    return;
  }
  key = line.substr(0, delimiter_pos);
  value = line.substr(delimiter_pos + 1);
}

static void readFile(std::ifstream& infile,
                     std::map<std::string, std::string>& storage,
                     const char delim) {
  std::string key, value, line;

  std::getline(infile, line);  // skip first line
  while (true) {
    std::getline(infile, line);
    if (infile.eof()) break;
    split(line, delim, key, value);
    trim(key);
    trim(value);
    storage[key] = value;
  }
}

static inline void closeFile(std::ifstream& infile) { infile.close(); }

static void fillStorage(std::map<std::string, std::string>& storage,
                        const std::string& filepath, const char delim) {
  std::ifstream infile;

  try {
    openFile(infile, filepath);
    readFile(infile, storage, delim);
    closeFile(infile);
  } catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

static void validatePair(const std::pair<std::string, std::string>& pair) {
  if (pair.first.empty() || pair.second.empty())
    throw "bad input => " + pair.first + " | " + pair.second;
}

static void validateDate(const std::string& date) {
  char hifen;
  std::stringstream stream(date);
  struct tm old = {}, normalized = {};
  const std::string error = "bad input => " + date;

  if (date.size() != 10) throw error;
  if (!(stream >> old.tm_year >> hifen >> old.tm_mon >> hifen >> old.tm_mday))
    throw error;
  old.tm_mon -= 1;
  old.tm_year -= 1900;
  normalized = old;
  mktime(&normalized);
  if (normalized.tm_year != old.tm_year || normalized.tm_mon != old.tm_mon ||
      normalized.tm_mday != old.tm_mday)
    throw error;
}

static void validateValue(const std::string& value) {
  char* endptr = NULL;
  const double num = std::strtod(value.c_str(), &endptr);
  if (*endptr != '\0') throw "bad input => " + value;
  if (num < 0) throw "not a positive number.";
  if (num > 1000.0) throw "too large number";
}

static bool isValid(const std::pair<std::string, std::string>& pair) {
  try {
    validatePair(pair);
    validateDate(pair.first);
    validateValue(pair.second);
    return true;
  } catch (const std::string& what) {
    std::cout << "Error: " << what << std::endl;
    return false;
  }
}

static const std::string findClosestDate(
    const std::string& date, std::map<std::string, std::string>& database) {
  std::map<std::string, std::string>::iterator current;
  std::map<std::string, std::string>::iterator previous;

  if (date < database.begin()->first) return "";
  if (date > database.rbegin()->first) return (database.rbegin()->second);

  previous = database.begin();
  current = database.begin();
  current++;
  while (current != database.end()) {
    if (current->first > date) return (previous->second);
    previous = current;
    ++current;
  }
  return "";
}

static float getRate(const std::string& date,
                     std::map<std::string, std::string>& database) {
  if (database.find(date) == database.end())
    return std::atof(database[findClosestDate(date, database)].c_str());
  else
    return std::atof(database[date].c_str());
}

// static void run(std::map<std::string, std::string>& input,
//                 std::map<std::string, std::string>& database) {
//   for (std::map<std::string, std::string>::iterator it = input.begin();
//        it != input.end(); it++) {
//     if (!isValid(*it)) continue;
//     std::cout << it->first << " => " << it->second << " = "
//               << std::atof(it->second.c_str()) * getRate(it->first, database)
//               << std::endl;
//   }
// }

void print(std::map<std::string, std::string>& input) {
  for (std::map<std::string, std::string>::iterator it = input.begin();
       it != input.end(); it++) {
    std::cout << it->first << " " << it->second << std::endl;
  }
}
void BitcoinExchange::calculate(const std::string& inputfile) {
  // std::cout << databaseDefaultFilepath << std::endl;
  // std::cout << inputfile << std::endl;
  fillStorage(BitcoinExchange::database, databaseDefaultFilepath, ',');
  (void)inputfile;

  fillStorage(BitcoinExchange::input, inputfile, '|');
  print(BitcoinExchange::input);
  // run(input, BitcoinExchange::database);
}
