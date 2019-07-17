#ifndef GRAPHIC_LIBRARY_EXCEPTIONS_HPP
# define GRAPHIC_LIBRARY_EXCEPTIONS_HPP

    #include <string>

    class GraphicLibraryExceptions
    {
    public:
        struct CreateWindowFailedException : public std::exception
        {
            virtual const char * what() const throw();
        };

        struct InitFailedException : public std::exception
        {
            virtual const char * what() const throw();
        };

        struct RenderInitFailed : public std::exception
        {
            virtual const char * what() const throw();
        };
        
    };

#endif // !GRAPHIC_LIBRARY_EXCEPTIONS_HPP
