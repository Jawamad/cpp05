/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:22:44 by flmuller          #+#    #+#             */
/*   Updated: 2025/02/05 14:42:29 by flmuller         ###   ########.fr       */
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
	size_t result;
	std::string	listOfForm[3] = {"Shrubbery", "Robotomy", "Presidential"};
	for (size_t i = 0; i < 3; i++)
	{
		if (name == listOfForm[i])
		{
			result = i;
			break;
		}
	}
	std::cout << "Intern create ";
	switch (result)
	{
	case 0:
		std::cout << "a Shrubbery Creation Form" << std::endl;
		return new ShrubberyCreationForm(target);
		break;
	case 1:
		std::cout << "a Robotomy request Form" << std::endl;
		return new RobotomyRequestForm(target);
		break;
	case 2:
		std::cout << "a Presidential Pardon Form" << std::endl;
		return new PresidentialPardonForm(target);
		break;
	default:
		throw FormDoesntExistException(name, "cannot be create");
		break;
	}
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
