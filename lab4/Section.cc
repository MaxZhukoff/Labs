#include <iostream>
#include "Section.h"

using namespace std;

Section::Section(Vector2D A, Vector2D B) :
        A(A), B(B)
{
}

Section::Section() {
}

double Section::mass() const {
    return this->square();
}

Vector2D Section::position() const {
    return (A + B) / 2;
}

bool Section::operator==(const IPhysObject& other) const {
    return mass() == other.mass();
}

bool Section::operator<(const IPhysObject& other) const {
    return mass() < other.mass();
}

double Section::square() const {
    return 0;
}

double Section::perimeter() const {
    return length;
}

unsigned Section::size() {
    return sizeof(*this);
}

const char* Section::className() {
    return "Section";
}

void Section::initFromDialog() {
    cout << "‘®§¤ ­¨¥ ®¡ê¥ªâ  '®âà¥§®ª' " << endl;
    cout << "‚¢¥¤¨â¥ ª®®à¤¨­ âë ¯¥à¢®© â®çª¨ ç¥à¥§ ¯à®¡¥«: ";
    cin >> x1 >> y1;
    A = Vector2D(x1, y1);
    cout << "‚¢¥¤¨â¥ ª®®à¤¨­ âë ¢â®à®© â®çª¨ ç¥à¥§ ¯à®¡¥«: ";
    cin >> x2 >> y2;
    B = Vector2D(x2, y2);
    length = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

void Section::draw() {
    cout << "Žâà¥§®ª ­  â®çª å: " << endl;
    cout << A << " " << B <<  " " << endl;
    cout << "„«¨­  ®âà¥§ª : " << length << endl;
}
