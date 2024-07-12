#include "Account.hpp"
#include <iostream>
#include <string>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);
 
    char buffer[128];
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", now);
    std::cout << "[" << buffer << "] ";
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
    _totalAmount += _amount;
    this->_accountIndex = _nbAccounts;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<
        ";amount:"  << _amount << ";created" << std::endl; 
    _nbAccounts++;
}
Account::~Account(void)
{
    _displayTimestamp();
    std::cout << "index:" << _accountIndex <<
        ";amount:" << _amount << ";closed" << std::endl; 
}

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}

int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbDeposits(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";total:" <<
        getTotalAmount() << ";deposits:" <<  getNbDeposits() <<
        ";withdrawals:" << getNbWithdrawals() << std::endl; 
}

void Account::displayStatus(void) const
{
    _displayTimestamp();
    std::cout << "index:" <<  _accountIndex << ";amount:" <<
        _amount << ";deposits:" << _nbDeposits <<
        ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    _totalAmount += deposit;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    std::cout << ";deposit:" << deposit << ";amount:" << _amount + deposit;
    if(deposit > 0)
    {
        _nbDeposits++;
        _totalNbDeposits++;
    }
    std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
    _amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    _displayTimestamp();
    if(_amount - withdrawal < 0)
    {
        std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _totalAmount -= withdrawal;
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount;
    std::cout << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal;
    if(withdrawal > 0)
    {
        _nbWithdrawals++;
        _totalNbWithdrawals++;
    }
    std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    _amount -= withdrawal;
    return true;
}
