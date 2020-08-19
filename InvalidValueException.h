#pragma once

#include <stdexcept>
using std::runtime_error;

class InvalidValueException :public std::exception {
public:
	virtual const char* what() const throw() {
		return "OPCION INVALIDA ";
	}
};