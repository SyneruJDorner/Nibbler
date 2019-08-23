#ifndef RENDER_ENGINE_EXCEPTIONS_HPP
# define RENDER_ENGINE_EXCEPTIONS_HPP

    #include <string>

    class RenderEngineExceptions
    {
    public:
        struct LibraryNotFoundException : public std::exception
        {
            virtual const char * what() const throw();
        };

        struct CannotLoadSymbolException : public std::exception
        {
            virtual const char * what() const throw();
        };
    };

#endif // !RENDER_ENGINE_EXCEPTIONS_HPP
