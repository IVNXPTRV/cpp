#include "Account.hpp"

#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(void)
    : _accountIndex(Account::_nbAccounts),
      _amount(0),
      _nbDeposits(0),
      _nbWithdrawals(0) {
  Account::_nbAccounts += 1;
  Account::_totalAmount += 0;

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "created" << std::endl;
}

// [19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit)
    : _accountIndex(Account::_nbAccounts),
      _amount(initial_deposit),
      _nbDeposits(0),
      _nbWithdrawals(0) {
  Account::_nbAccounts += 1;
  Account::_totalAmount += initial_deposit;

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "created" << std::endl;
}

//[19920104_091532] index:0;amount:47;closed
Account::~Account(void) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "closed" << std::endl;
}

int Account::getNbAccounts(void) { return (Account::_nbAccounts); }
int Account::getTotalAmount(void) { return (Account::_totalAmount); }
int Account::getNbDeposits(void) { return (Account::_totalNbDeposits); }
int Account::getNbWithdrawals(void) { return (Account::_totalNbWithdrawals); }

int Account::checkAmount(void) const { return (this->_amount); }

// accounts:8;total:21524;deposits:8;withdrawals:0
void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::_nbAccounts << ";";
  std::cout << "total:" << Account::_totalAmount << ";";
  std::cout << "deposits:" << Account::_totalNbDeposits << ";";
  std::cout << "withdrawals:" << Account::_totalNbWithdrawals;
  std::cout << std::endl;
}

// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void Account::makeDeposit(int deposit) {
  this->_amount += deposit;
  this->_nbDeposits++;
  Account::_totalAmount += deposit;
  Account::_totalNbDeposits++;

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount - deposit << ";";
  std::cout << "deposit:" << deposit << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532]
// index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal) {
  bool refused;

  refused = true;
  if (withdrawal <= this->_amount) {
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    refused = false;
  }
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  if (refused) {
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "withdrawal:refused" << std::endl;
    return (false);
  }
  std::cout << "p_amount:" << this->_amount + withdrawal << ";";
  std::cout << "withdrawal:" << withdrawal << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
  return (true);
}

// index:7;amount:16576;deposits:0;withdrawals:0
void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "deposits:" << this->_nbDeposits << ";";
  std::cout << "withdrawals:" << this->_nbWithdrawals;
  std::cout << std::endl;
}

// [19920104_091532]
void Account::_displayTimestamp(void) {
  std::time_t time;
  std::tm *timemark;

  time = std::time(NULL);
  timemark = std::localtime(&time);
  std::cout << "[" << timemark->tm_year + 1900;
  std::cout << std::setfill('0') << std::setw(2) << timemark->tm_mon + 1;
  std::cout << std::setfill('0') << std::setw(2) << timemark->tm_mday << "_";
  std::cout << std::setfill('0') << std::setw(2) << timemark->tm_hour;
  std::cout << std::setfill('0') << std::setw(2) << timemark->tm_min;
  std::cout << std::setfill('0') << std::setw(2) << timemark->tm_sec << "] ";
}
