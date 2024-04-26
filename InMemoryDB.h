#pragma once
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <iostream>
#include <stdio.h>
#include <optional>


class InMemoryDB
{
public:
	InMemoryDB() 
	{ 
		val_ = NULL; 
		key_ = ""; 
		inProcess_ = false; 
		transactionMap_.clear();
		databaseMap_.clear();
	}
	~InMemoryDB() 
	{ 
		inProcess_ = false;
		transactionMap_.clear();
		databaseMap_.clear();
	}

	// Transaction functions:
	void begin_transaction();
	void commit();
	void rollback();
	
	// Getters/setters
	std::optional<int> get(std::string key);
	void put(std::string key, int val);
	bool getInProcess();
	void setInProcess(bool inProcess);

private:
	// Variables:
	std::string key_; // String key for transaction
	int val_; // Value of transaction
	std::map <std::string, int> transactionMap_; // Stores the key and value!
	std::map <std::string, int> databaseMap_; // Stores the committed transactions
	bool inProcess_; // Transaction is in process! Initialize to false
};

