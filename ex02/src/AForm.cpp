/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:04:03 by flmuller          #+#    #+#             */
/*   Updated: 2025/01/27 16:48:20 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Form.hpp"

/* constructors */
AForm::AForm() : _name("standard form"), _sign(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(const std::string n, unsigned int const sg, unsigned int const eg): _name (n), _sign(false), _signGrade(sg), _execGrade(eg)
{
	if (sg < 1)
		throw GradeTooHighException("cannot initialise sign grade with this grade", _name);
	if (sg > 150)
		throw GradeTooLowException("cannot initialise sign grade with this grade", _name);
	if (eg < 1)
		throw GradeTooHighException("cannot initialise exec grade with this grade", _name);
	if (eg > 150)
		throw GradeTooLowException("cannot initialise exec grade with this grade", _name);
	std::cout << "Form " << _name << " has been created." << std::endl;
}
AForm::AForm(const AForm &obj): _name(obj.getName()), _sign(obj._sign), _signGrade(obj.getSignGrade()), _execGrade(obj.getExecGrade()) {}

AForm::~AForm(){}

/* getters*/
std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSign() const
{
	return _sign;
}

unsigned int AForm::getSignGrade() const
{
	return _signGrade;
}
unsigned int AForm::getExecGrade() const
{
	return _execGrade;
}

/* exceptions*/
AForm::GradeTooHighException::GradeTooHighException(const std::string &m, const std::string &fN): _message(m), _formName(fN)
{
	_completeMsg = _formName + " " + _message + ": grade too high.";
}
AForm::GradeTooHighException::~GradeTooHighException() throw() {}
const char* AForm::GradeTooHighException::what() const throw()
{
	return _completeMsg.c_str();
}
AForm::GradeTooLowException::GradeTooLowException(const std::string &m, const std::string &fN): _message(m), _formName(fN)
{
	_completeMsg = _formName + " " + _message + ": grade too low.";
}
AForm::GradeTooLowException::~GradeTooLowException() throw() {}
const char* AForm::GradeTooLowException::what() const throw()
{
	return _completeMsg.c_str();
}
/* members functions */
void AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > _signGrade)
		throw GradeTooLowException("cannot be signed by bureaucrat with this grade", _name);
	_sign = true;
	std::cout << bureaucrat.getName() << " have signed " << _name << " form." << std::endl;
}
std::ostream&	operator<<(std::ostream& o, const AForm& src)
{
	o << src.getName() << ", form signed " << src.getSign() << ", execution grade " << src.getExecGrade() << ", sign grade " << src.getSignGrade();
	return o;
}