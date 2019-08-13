#ifndef COLOR_HPP
# define COLOR_HPP

struct Color
{
    double r;
    double g;
    double b;
    double a;

    void SetColour(double red, double green, double blue, double alpha)
    {
        this->r = red;
        this->g = green;
        this->b = blue;
        this->a = alpha;
    }
};

#endif