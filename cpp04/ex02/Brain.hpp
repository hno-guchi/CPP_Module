/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnoguchi <hnoguchi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:47:02 by hnoguchi          #+#    #+#             */
/*   Updated: 2023/05/26 11:28:20 by hnoguchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include "color.hpp"
#include "debugMessage.hpp"

# define IDEARS_SIZE 100

class Brain {
	public:
		// CONSTRUCTER
		Brain();
		Brain(const std::string& idea);
		Brain(const Brain& src);

		// OPERATOR
		Brain&	operator=(const Brain& rhs);

		// GETTER
		std::string		getIdea(const unsigned int& index) const;
		unsigned int	getIdeaArraySize() const;
		unsigned int	getLastIndex() const;

		// SETTER
		void	setIdea(const std::string& idea);

		// SUBJECT FUNC

		// DESTRUCTER
		virtual ~Brain();

	private:
		// SUBJECT ATTRIBUTE
		std::string		ideas_[IDEARS_SIZE];

		// MY ATTRIBUTE
		unsigned int	ideasSize_;
		unsigned int	currentIndex_;
};

#endif
