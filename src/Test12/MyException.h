#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include <iostream>
#include <exception>

class FileNotOpenedException : public std::exception {
public:
	FileNotOpenedException(const std::string& what_arg) : what_arg(what_arg) {
	}
	const char* what() const noexcept override {
		return what_arg.c_str();
	}
private:
	std::string what_arg;
};

#endif // MYEXCEPTION_H
