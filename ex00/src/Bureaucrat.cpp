/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:39:32 by flmuller          #+#    #+#             */
/*   Updated: 2025/02/06 11:03:13 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

/* constuctors */
Bureaucrat::Bureaucrat() : _name("someone"), _grade(150){}

Bureaucrat::Bureaucrat(const std::string &n, const unsigned int g): _name(n)
{
	if (g < 1 )
		throw GradeTooHighException("cannot be initialise with this grade", _name);
	else if (g > 150)
		throw GradeTooLowException("cannot be initialise with this grade", _name);
	_grade = g;
	std::cout<< "A new Bureaucrat named "<<_name<< " is hired to the company at "<<_grade<<" grade."<<std::endl;
}
Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
}

/* destructors */
Bureaucrat::~Bureaucrat() {}

/* operator */
Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	if (this != &src)
		_grade = src._grade;
	return *this;
}

/* getters */
std::string	Bureaucrat::getName() const
{
	return _name;
}

unsigned int	Bureaucrat::getGrade() const
{
	return _grade;
}

/* members */
void	Bureaucrat::incrementGrade()
{
	if (_grade == 1)
		throw GradeTooHighException("Grade cannot be higher", _name);
	else
		_grade--;
}
void	Bureaucrat::decrementGrade()
{
	if (_grade == 150)
		throw GradeTooLowException("Grade cannot be lower", _name);
	else
		_grade++;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string &m, const std::string &bN): _message(m), _bureaucratName(bN)
{
	_completeMsg =_bureaucratName + " " + _message + ", grade too high.";
}
Bureaucrat::GradeTooHighException::~GradeTooHighException() throw(){}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return _completeMsg.c_str();
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string &m, const std::string &bN): _message(m), _bureaucratName(bN)
{
	_completeMsg = _bureaucratName + " " + _message + ", grade too low.";
}
Bureaucrat::GradeTooLowException::~GradeTooLowException() throw(){}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return _completeMsg.c_str();
}

std::ostream&	operator<<(std::ostream& o, const Bureaucrat& src)
{
	o<<src.getName()<<", bureaucrat grade "<<src.getGrade();
	return o;
}