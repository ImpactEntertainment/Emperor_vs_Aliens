/**
 * \file exception.h
 * \brief Classe base que representa as exceções.
 *
 * \author Edson Alves (edsonalves@unb.br)
 * \date 31/12/2012
 */
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>

using namespace std;

class Exception {
public:
	Exception(const string& message) { this->message = message; }
	string getMessage() const { return message; }

private:
	string message;
};

#endif

