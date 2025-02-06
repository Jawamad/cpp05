/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:22:44 by flmuller          #+#    #+#             */
/*   Updated: 2025/02/06 13:24:36 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"

/* constructors */
Intern::Intern() {}
Intern::~Intern(){}
Intern::Intern(const Intern & obj)
{
	*this = obj;
}
/* operators */
Intern&	Intern::operator=(const Intern & obj)
{
	(void) obj;
	return (*this);
}
/* members */
AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string	names[3] = {"presidential", "shrubbery", "robotomy"};
	AForm* (*formCreator[3])(std::string Target) = {PresidentialPardonForm::createForm, ShrubberyCreationForm::createForm, RobotomyRequestForm::createForm}; 
	for (int i = 0; i < 4; i++) {
		if (names[i] == name) {
			std::cout << "Intern creates " << name << " form" << std::endl;
			return formCreator[i](target);
		}
	}
	throw FormDoesntExistException(name, "cannot be create");
}
/* exceptions */
Intern::FormDoesntExistException::FormDoesntExistException(const std::string &m, const std::string &fN): _message(m), _formName(fN)
{
	_completeMsg = _formName + " " + _message + ": form name doesn't exist.";
}
Intern::FormDoesntExistException::~FormDoesntExistException() throw() {}
const char* Intern::FormDoesntExistException::what() const throw()
{
	return _completeMsg.c_str();
}
