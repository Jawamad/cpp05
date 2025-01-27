/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:39:02 by flmuller          #+#    #+#             */
/*   Updated: 2025/01/27 15:14:30 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const _name;
		bool _sign;
		unsigned int const _signGrade;
		unsigned int const _execGrade;
	public:
		/* constructors */
		Form();
		Form(const std::string n, unsigned int const sg, unsigned int const eg);
		Form(const Form& obj);
		~Form();
		/* operator */
		Form	&operator=(const Form &src);
		/* getters*/
		std::string getName() const;
		bool getSign() const;
		unsigned int getSignGrade() const;
		unsigned int getExecGrade() const;
		/* class */
		class GradeTooHighException : public std::exception
		{
			private:
				std::string _message;
				std::string _formName;
				std::string _completeMsg;
			public:
			GradeTooHighException(const std::string &m, const std::string &fN);
			virtual ~GradeTooHighException() throw();
			virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			private:
				std::string _message;
				std::string _formName;
				std::string _completeMsg;
			public:
			GradeTooLowException(const std::string &m, const std::string &fN);
			virtual ~GradeTooLowException() throw();
			virtual const char* what() const throw();
		};
		/* members functions */
		void beSigned(Bureaucrat const& bureaucrat);
};

std::ostream&	operator<<(std::ostream& o, const Form& src);

#endif