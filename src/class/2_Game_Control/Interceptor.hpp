#ifndef INTERCEPTOR_HPP
# define INTERCEPTOR_HPP

# include <string>

class Interceptor
{
	public:
		Interceptor();
		Interceptor(Interceptor &obj);
		virtual ~Interceptor();
		Interceptor &operator=(Interceptor const &other);
		static Interceptor *instance;
};

#endif