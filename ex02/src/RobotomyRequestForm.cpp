/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:55:12 by flmuller          #+#    #+#             */
/*   Updated: 2025/01/30 17:14:25 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include <ctime>

/* constructors */
RobotomyRequestForm::RobotomyRequestForm() : AForm("robotomyRequestForm", 72, 45), _target(NULL){}
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm& obj) : AForm(obj)
{
	*this = obj;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& t): AForm("robotomyRequestForm", 72, 45), _target(t){}
RobotomyRequestForm::~RobotomyRequestForm(){}
	/* getters */
std::string RobotomyRequestForm::getTarget() const
{
	return _target;
}

/* operators */
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
	if (this == &obj)
		return *this;
	_target = obj._target;
	return (*this);
}
/* members */
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	int	random_number = rand() % 2;
	if (random_number)
		std::cout << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}