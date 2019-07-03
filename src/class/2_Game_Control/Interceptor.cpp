#include "Interceptor.hpp"

//Create a singolton access point.
//You can easily access anything though the following.
//Interceptor::instance->WHAT_YOU_WANT();
Interceptor *Interceptor::instance = new Interceptor();

Interceptor::Interceptor()
{

}

Interceptor::Interceptor(Interceptor &obj)
{

}

Interceptor::~Interceptor()
{

}

Interceptor &Interceptor::operator=(Interceptor const &other)
{

}