#include "Account.hpp"
#include <iostream>
#include <ctime>

//Static int needs to be initialized before use
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::checkAmount(void) const {return this->_amount;}
int	Account::getNbAccounts(void) {return Account::_nbAccounts;}
int	Account::getTotalAmount(void) {return Account::_totalAmount;}
int Account::getNbDeposits(void) {return Account::_totalNbDeposits;}
int	Account::getNbWithdrawals(void) {return Account::_totalNbWithdrawals;}

void	Account::_displayTimestamp(void) {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    std::cout << "[" << (now->tm_year + 1900) - 2000 << (now->tm_mon + 1) << now->tm_mday << "_"
         << (now->tm_hour) << (now->tm_min) << (now->tm_sec) << "] ";
}

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts),
		_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	Account::_nbAccounts++;
	Account::_totalAmount += Account::checkAmount();
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";created" << std::endl;
}

Account::~Account(void) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";closed" << std::endl;
	Account::_nbAccounts--;
	Account::_totalAmount -= Account::checkAmount();
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "amount:" << getTotalAmount() << ";";;
	std::cout << "deposits:" << getNbDeposits() << ";";;
	std::cout << "Withdrawals:" << getNbWithdrawals() << ";" << std::endl;
}

void	Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << Account::checkAmount() << ";";
	if (deposit < 0) {
		std::cout << "deposit:refused" << std::endl;}
	else {
		std::cout << "deposit:" << deposit << ";";
		this->_amount += deposit;
		Account::_totalAmount += deposit;
		std::cout << "amount:" << Account::checkAmount() << ";";
		this->_nbDeposits++;
		Account::_totalNbDeposits++;
		std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;}
}

bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << Account::checkAmount() << ";";
	if (withdrawal > _amount || withdrawal < 0) {
		std::cout << "withdrawal:refused" << std::endl;	
		return (false);
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	Account::_totalAmount -= withdrawal;
	std::cout << "amount:" << Account::checkAmount() << ";";
	this->_nbWithdrawals++;
	Account::_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return (true);
}


void	Account::displayStatus(void) const {
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << Account::checkAmount() << ";";
	std::cout << "deposits" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
}
