# include "Account.hpp"
# include <iostream>
# include <iomanip>
# include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
	:	_accountIndex(_nbAccounts),
		_amount(initial_deposit),
		_nbDeposits(0),
		_nbWithdrawals(0)
{
	_totalAmount += _amount;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int	Account::getNbAccounts( void ) // Static
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) // Static
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) // Static
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) // Static
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void ) // Static
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	if (deposit < 1)
		return ;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << _amount
			<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
	if (withdrawal < 1 || withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount
			<< ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

//	--- Private --- //

void	Account::_displayTimestamp( void ) // Static
{
	time_t time;
	tm *full_time;

	std::time(&time);
	full_time = std::localtime(&time);
	std::cout << "[" << (1900 + full_time->tm_year);
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << full_time->tm_sec << "] ";
}
