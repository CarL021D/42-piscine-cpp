#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts() { return _nbAccounts; }

int	Account::getTotalAmount() { return _totalAmount; }

int	Account::getNbDeposits() { return _totalNbDeposits; }

int	Account::getNbWithdrawals() { return _totalNbWithdrawals; }

Account::Account(int initial_deposit) {
   
	_accountIndex = _nbAccounts;
	_displayTimestamp();
	std::cout << "index:" <<_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
	_nbAccounts++;
	_amount += initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits++; 
	_totalNbDeposits++;
}

Account::~Account() {
	_displayTimestamp();
	std::cout 	<< " index:" <<_accountIndex << ";amount:"
				<< _amount << ";closed" << std::endl;
}



void	Account::makeDeposit(int deposit) {
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (withdrawal - _amount < 0)
	{
		std::cout 	<< " index:" <<_accountIndex << ";p_amount:"
					<< _amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout 	<< " index:" <<_accountIndex << ";p_amount:"
				<< _amount + withdrawal << ";withdrawal:"
				<< withdrawal << ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount(void) const { return 0; }

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts<< ";total:"
				<< _totalAmount << ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void) {

	char temp[20];
	time_t rawtime = time( &rawtime);
	struct tm * timeinfo = localtime (&rawtime);
	std::cout << "[";
	strftime(temp, 30, "%G%m%e_%H%M%S", timeinfo);
	std::cout << "]";
}

void	Account::displayAccountsInfos() {

	// for (int i = 0; t[i]; i++)
	// _displayTimestamp();
	// std::cout	<< " index:" << _accountIndex << ";amount:"
	// 			<< _amount << ";deposit:" << _nbDeposits
	// 			<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

Account::Account(void) {}
