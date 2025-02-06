/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:01:40 by flmuller          #+#    #+#             */
/*   Updated: 2025/02/06 11:52:37 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM
# define PRESIDENTIAL_PARDON_FORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
	public:
	/* constructors */
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm& obj);
		PresidentialPardonForm(const std::string& t);
		~PresidentialPardonForm();
	/* getters */
		std::string getTarget() const;
	/* operators */
		PresidentialPardonForm	&operator=(const PresidentialPardonForm &src);
	/* members */
		virtual void execute(Bureaucrat const & executor) const;
		static AForm*	createForm(std::string target);
};

#endif