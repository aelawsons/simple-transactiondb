#include "InMemoryDB.h"

void InMemoryDB::begin_transaction()
{
	// Set process to true only if the process is false, otherwise throw exception
	if(!getInProcess())
	{
		setInProcess(true);
		std::cout << "\nNew transaction created." << std::endl;
	}
	else
		std::cout << "\nERROR: Transaction Already in Progress\n" << std::endl;
}

// Commit the transaction map info to the database map, then clear transactionMap
void InMemoryDB::commit()
{
	// End transaction and apply transaction map to the total database
	if (getInProcess())
	{
		setInProcess(false);
		for (auto i = transactionMap_.begin(); i != transactionMap_.end(); i++)
		{
			if (databaseMap_.find(i->first) == databaseMap_.end())
				databaseMap_.emplace(i->first, i->second);
			else
				databaseMap_[i->first] = i->second;
		}
		transactionMap_.clear();
		std::cout << "\nTransactions committed." << std::endl;
	}
	else
		std::cout << "\nERROR: No Transaction in Progress\n" << std::endl;
}

// Rollback the data, clear the transaction map and not commit it!
void InMemoryDB::rollback()
{
	// Reset transactionMap_ and set progress to false
	if (getInProcess())
	{
		setInProcess(false);
		transactionMap_.clear();
		std::cout << "\nTransactions rolled back." << std::endl;
	}
	else
		std::cout << "\nERROR: No Transaction in Progress\n" << std::endl;

}

// Get from the database map: (committed transactions only)
std::optional<int> InMemoryDB::get(std::string key)
{
	// Key can't be found:
	if (databaseMap_.find(key) == databaseMap_.end())
		return std::nullopt;

	// Otherwise: return the value for that key!
	return databaseMap_.find(key)->second;
}

// Put transaction into the transactionMap but don't commit to databaseMap yet!
void InMemoryDB::put(std::string key, int val)
{
	// Check that a trasaction isn't in process:
	if (!getInProcess())
		std::cout << "\nERROR: No Transaction in Progress\n" << std::endl;
	
	// If the key doesn't exist in the map yet:
	if (transactionMap_.find(key) == transactionMap_.end())
	{
		transactionMap_.emplace(key, val);
		std::cout << "\nKey added." << std::endl;

	} else 
	{
		// Otherwise, update current key value:
		transactionMap_[key] = val;
		std::cout << "\nKey updated." << std::endl;
	}
}

bool InMemoryDB::getInProcess()
{
	return inProcess_;
}

void InMemoryDB::setInProcess(bool inProcess)
{
	inProcess_ = inProcess;
}
