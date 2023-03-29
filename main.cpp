#include <iostream>
#include <cmath>

using namespace std;

struct Polar
{
    double distance;
    double angle;
};

struct Rect
{
    double x;
    double y;
};

void show_polar(const Polar *pda);
void rect_to_polar(const Rect* pxy, Polar* pda);

int main() {

    Rect rplace;
    Polar pplace;

    cout << "Enter the x and y values";
    while (cin>>rplace.x >> rplace.y)
    {
        rect_to_polar(&rplace, &pplace);
        show_polar(&pplace);
        cout << "Next two numbers (q to quit): ";
    };

    cout << "Done.n";

    return 0;
}

void show_polar(const Polar *pda)
{
    const double Rad_to_deg = 57.29577951;

    cout << "distance = " << pda->distance;
    cout << ", angle =" <<pda->angle * Rad_to_deg << " degrees" << endl;
}

void rect_to_polar(const Rect* pxy, Polar* pda)
{
    pda->distance = std::sqrt(pxy->x * pxy->y + pxy->y * pxy->y);
    pda->angle = std::atan2(pxy->y, pxy->x);
}