/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:13:10 by flmuller          #+#    #+#             */
/*   Updated: 2025/02/06 11:52:49 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM
# define SHRUBBERY_CREATION_FORM

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
	/* constructors */
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm& obj);
		ShrubberyCreationForm(const std::string & t);
		~ShrubberyCreationForm();
	/* operators */
		ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &src);
	/* getters */
		std::string getTarget() const;
	/* members */
		virtual void execute(Bureaucrat const & executor) const;
		static AForm*	createForm(std::string target);
};

#endif