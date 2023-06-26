/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caboudar <caboudar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:42:31 by caboudar          #+#    #+#             */
/*   Updated: 2023/05/15 16:42:32 by caboudar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
}

Account::~Account() {
	_displayTimestamp();
	std::cout 	<< " index:" <<_accountIndex << ";amount:"
				<< _amount << ";closed" << std::endl;
	_nbAccounts--;
}



void	Account::makeDeposit(int deposit) {
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout	<< " index:" << _accountIndex << ";p_amount:"
				<< _amount - deposit << ";deposit:" << deposit
				<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (_amount - withdrawal < 0)
	{
		std::cout 	<< " index:" << _accountIndex << ";p_amount:"
					<< _amount << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout 	<< " index:" << _accountIndex << ";p_amount:"
				<< _amount + withdrawal << ";withdrawal:"
				<< withdrawal << ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount(void) const { return _amount; }

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout	<< " accounts:" << _accountIndex << ";total:"
				<< _amount << ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
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
	_displayTimestamp();
	std::cout	<< " accounts:" << getNbAccounts() << ";total:"
				<< getTotalAmount() << ";deposits:" << getNbDeposits()
				<< ";nb_withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(void) {}
