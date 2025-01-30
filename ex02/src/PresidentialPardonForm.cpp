/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:09:51 by flmuller          #+#    #+#             */
/*   Updated: 2025/01/30 11:45:08 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"

/* constructors */
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target(NULL){}
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& obj) : AForm(obj)
{
	*this = obj;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string& t): AForm("PresidentialPardonForm", 25, 5), _target(t){}
PresidentialPardonForm::~PresidentialPardonForm(){}
	/* getters */
std::string PresidentialPardonForm::getTarget() const
{
	return _target;
}
/* members */
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	AForm::execute(executor);
	std::cout << executor.getName() << " execute the " << getName()<< " : "<< std::endl;
	std::cout << _target <<" has been pardoned by Zaphod Beeblebrox." << std::endl;
}
/* operators */
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
	if (this == &obj)
		return *this;
	_target = obj._target;
	return (*this);
}