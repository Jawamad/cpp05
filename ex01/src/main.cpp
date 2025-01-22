/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:44:32 by flmuller          #+#    #+#             */
/*   Updated: 2025/01/17 15:45:14 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"

int	main()
{
	try
	{
		std::cout << std::endl << "########-test no error-########"<< std::endl << std::endl;
		Bureaucrat robert("robert", 45);
		std::cout << robert << std::endl;
		std::cout << "decrement Grade" << std::endl;
		robert.decrementGrade();
		std::cout << robert.getGrade() << std::endl;
		std::cout << "decrement Grade" << std::endl;
		robert.incrementGrade();
		std::cout << robert.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test error bad 1st grade (too low)-########"<< std::endl << std::endl;
		Bureaucrat Regis("Regis", 151);
		std::cout << Regis << std::endl;
		std::cout << "decrement Grade" << std::endl;
		Regis.decrementGrade();
		std::cout << Regis.getGrade() << std::endl;
		std::cout << "decrement Grade" << std::endl;
		Regis.incrementGrade();
		std::cout << Regis.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test error bad 1st grade (too high)-########"<< std::endl << std::endl;
		Bureaucrat raymond("raymond", 0);
		std::cout << raymond << std::endl;
		std::cout << "decrement Grade" << std::endl;
		raymond.decrementGrade();
		std::cout << raymond.getGrade() << std::endl;
		std::cout << "increment Grade" << std::endl;
		raymond.incrementGrade();
		std::cout << raymond.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test error cannot increment grade-########"<< std::endl << std::endl;
		Bureaucrat Bertrand("Bertrand", 1);
		std::cout << Bertrand << std::endl;
		std::cout << "increment Grade" << std::endl;
		Bertrand.incrementGrade();
		std::cout << Bertrand.getGrade() << std::endl;
		std::cout << "decrement Grade" << std::endl;
		Bertrand.decrementGrade();
		std::cout << Bertrand.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << std::endl << "########-test error cannot decrement grade-########"<< std::endl << std::endl;
		Bureaucrat Boris("Boris", 150);
		std::cout << Boris << std::endl;
		std::cout << "decrement Grade" << std::endl;
		Boris.decrementGrade();
		std::cout << Boris.getGrade() << std::endl;
		std::cout << "increment Grade" << std::endl;
		Boris.incrementGrade();
		std::cout << Boris.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}