/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:13:05 by flmuller          #+#    #+#             */
/*   Updated: 2025/01/30 11:41:14 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM
# define ROBOTOMY_REQUEST_FORM

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	public:
	/* constructors */
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm& obj);
		RobotomyRequestForm(const std::string& t);
		~RobotomyRequestForm();
	/* operators */
		RobotomyRequestForm	&operator=(const RobotomyRequestForm &src);
	/* getters */
		std::string getTarget() const;
	/* members */
		virtual void execute(Bureaucrat const & executor) const;
};

#endif