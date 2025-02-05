/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:07:18 by flmuller          #+#    #+#             */
/*   Updated: 2025/01/31 13:54:23 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include <fstream>

std::string tree =
"       # #### ####\n"
"      ### \\/#|### |/####\n"
"     ##\\/#/ \\||/##/_/##/_#\n"
"   ###  \\/###|/ \\/ # ###\n"
"  ##_\\_#\\_\\## | #/###_/_####\n"
" ## #### # \\ #| /  #### ##/##\n"
"  __#_--###`  |{,###---###-~\n"
"            \\ }{\n"
"             }}{\n"
"             }}{\n"
"        ejm  {{}}\n"
"       , -=-~{ .-^- _\n"
"             `}\n"
"              {\n";

/* constructors */
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target(NULL){}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm& obj) : AForm(obj)
{
	*this = obj;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& t): AForm("ShrubberyCreationForm", 145, 137), _target(t){}
ShrubberyCreationForm::~ShrubberyCreationForm(){}
	/* getters */
std::string ShrubberyCreationForm::getTarget() const
{
	return _target;
}
/* members */
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::ofstream file((_target + "_shrubbery").c_str());
	file << tree;
	file.close();
	std::cout << executor.getName() << " plants some shrubbery " << getName() << std::endl;
}
/* operators */
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this == &obj)
		return *this;
	_target = obj._target;
	return (*this);
}