#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

const std::string BitcoinExchange::_databaseFilepath = "data.csv";

static void fillDatabase(std::map<std::string, float>& database);

BitcoinExchange::BitcoinExchange() {
  try {
    fillDatabase(this->_database);
  } catch (const std::exception& e) {
    std::cout << "Exception: " << e.what() << std::endl;
    std::cout << "Exiting..." << std::endl;
    std::exit(EXIT_FAILURE);
  }
}
BitcoinExchange::~BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
  if (this == &other) return (*this);
  this->_database = other._database;
  return *this;
}

static void openFile(std::ifstream& infile, const std::string& filepath) {
  infile.open(filepath.c_str(), std::ios::in);
  if (infile.fail())
    throw std::runtime_error("Could not open " + filepath + "for reading.");
}

static void readFile(std::ifstream& infile,
                     std::map<std::string, float>& database) {
  std::string key, value;

  std::getline(infile, value);  // skip first line
  while (true) {
    std::getline(infile, key, ',');
    std::getline(infile, value, '\n');
    if (infile.eof()) break;
    database[key] = std::atof(value.c_str());
  }
}

static inline void closeFile(std::ifstream& infile) { infile.close(); }

static void fillDatabase(std::map<std::string, float>& database) {
  std::ifstream infile;

  openFile(infile, BitcoinExchange::_databaseFilepath);
  readFile(infile, database);
  closeFile(infile);
}
