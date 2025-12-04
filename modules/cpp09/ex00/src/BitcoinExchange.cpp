#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>

const std::string BitcoinExchange::_databaseFilepath = "data.csv";

static std::map<std::string, float> fillDatabase();

BitcoinExchange::BitcoinExchange() {
  try {
    this->_database = fillDatabase();
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

static std::ifstream openFile(const std::string& filepath) {
  std::ifstream infile;
  infile.open(filepath.c_str(), std::ios::in);
  if (infile.fail())
    throw std::runtime_error("Could not open " + filepath + "for reading.");
  return infile;
}

static std::map<std::string, float> fillDatabase() {
  std::ifstream infile = openFile(BitcoinExchange::_databaseFilepath);
  std::string key, value;
}
