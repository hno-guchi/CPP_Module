#ifndef SAMPLE_HPP
# define SAMPLE_HPP

#include <iostream>

class ISample {
	public:
		ISample();
		ISample(const std::string& name);
		ISample(const ISample& src);

		ISample&	operator=(const ISample& rhs);

		virtual void	message() const = 0;

		virtual	~ISample();
};

class Sample : public ISample {
	public:
		Sample();
		Sample(const std::string& name);
		Sample(const Sample& src)

		Sample&	operator=(const Sample& rhs);

		virtual void	message() const;
	private:
		std::string	name;
};

#endif
