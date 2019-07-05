#include "Input.hpp"
#include <ctime>
#include <sys/select.h>
#define STDIN_FILENO 0

//Create a singolton access point.
//You can easily access anything therogh the following.
//Input::instance->WHAT_YOU_WANT();
Input *Input::instance = new Input();

Input::Input()
{
    ResetInput();
}

Input::Input(Input &obj)
{
    (void)obj;
}

Input::~Input()
{

}

/*
Input &Input::operator=(Input const &other)
{

}
*/

int kbhit(void)
{
    struct timeval tv;
    fd_set read_fd;

    /* Do not wait at all, not even a microsecond */
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    /* Must be done first to initialize read_fd */
    FD_ZERO(&read_fd);

    /* Makes select() ask if input is ready:
    * 0 is the file descriptor for stdin    */
    FD_SET(0, &read_fd);

    /* The first parameter is the number of the
    * largest file descriptor to check + 1. */
    if(select(1, &read_fd, NULL, /*No writes*/NULL, /*No exceptions*/&tv) == -1)
        return 0;  /* An error occured */

    /*  read_fd now holds a bit map of files that are
    * readable. We test the entry for the standard
    * input (file 0). */
    if(FD_ISSET(0, &read_fd))
        /* Character pending on stdin */
        return 1;
    /* no characters were pending */
    return 0;
}

void Input::ResetInput()
{
    this->keyCode = NUL;
}

void Input::SetKeycode(char c)
{
    this->keyCode = static_cast<KeyCode>(c);
}

KeyCode Input::GetPressedKey()
{
    return (this->keyCode);
}

void Input::DetermineInputs()
{
    char pressedKey = '\0';

    struct termios t_hide, t_show;
    tcgetattr(STDIN_FILENO, &t_show);
    t_hide = t_show;
    t_hide.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &t_hide);

    if(kbhit() != 0)
    {
        int ch = getchar();
        pressedKey = ch;
        SetKeycode(ch);
    }

    //KeyCode key = GetPressedKey();
    //tcsetattr(STDIN_FILENO, TCSANOW, &t_show);

    if (GetPressedKey() == NUL)
        return;

    if (GetPressedKey() == W)
        std::cout << "Up" << "\n";

    if (GetPressedKey() == A)
        std::cout << "Left" << "\n";

    if (GetPressedKey() == S)
        std::cout << "Down" << "\n";

    if (GetPressedKey() == D)
        std::cout << "Right" << "\n";

    ResetInput();
}