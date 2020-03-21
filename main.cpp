#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include "Base.h"
#include "Ellipse.h"
#include "Section.h"

class FigureSystem {
public:
    vector<BaseClass*> figures;
    void menu();

private:
    void addFigure();
    void draw();
    void totalSquare();
    void totalPerimeter();
    void centerOfMass();
    void totalSize();
    void sortFigures();
    void controller(int);
    bool state = true;
};

void FigureSystem::menu() {
    while (state) {
        cout << "�������� 䨣���: '1'" << endl;
        cout << "���ଠ�� � ��� 䨣���: '2'" << endl;
        cout << "������� �㬬� ��� ���頤��: '3'" << endl;
        cout << "������� �㬬� ��� ��ਬ��஢: '4'" << endl;
        cout << "������� 業�� ����: '5'" << endl;
        cout << "������� ࠧ��� ��� 䨣��: '6'" << endl;
        cout << "����஢�� 䨣�� �� ����: '7'" << endl;
        cout << "�����襭�� ࠡ���: '8'" << endl;
        int command;
        cin >> command;
        std::cin.ignore(32767, '\n');
        controller(command);
    }
}

void FigureSystem::addFigure() {
    int command;
    cout << "����� 䨣��� ���������?" << endl;
    cout << "Section : '1'" << endl;
    cout << "Ellipse : '2'" << endl;
    cin >> command;
    switch (command) {
    case 1:
        figures.push_back(new Section());
        figures[figures.size() - 1]->initFromDialog();
        break;
    case 2:
        figures.push_back(new Ellipse());
        figures[figures.size() - 1]->initFromDialog();
        break;
    default:
        cout << "�������⭠� �������" << endl;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
}

void FigureSystem::draw() {
    for (auto figure : figures) {
        figure->draw();
    }
}

void FigureSystem::totalSquare() {
    double result = 0;
    for (auto figure : figures) {
        result += figure->square();
    }

    cout << "�㬬� ���頤�� ��� 䨣��: " << result << endl;
}

void FigureSystem::totalPerimeter() {
    double result = 0;
    for (auto figure : figures) {
        result += figure->perimeter();
    }

    cout << "�㬬� ��ਬ��஢ ��� 䨣��: " << result << endl;
}

void FigureSystem::centerOfMass() {
    Vector2D result(0, 0);
    double massSum = 0;
    for (auto figure : figures) {
        const double mass = figure->mass();

        Vector2D pos = figure->position();
        if (mass == 0) {
            result = result + pos;
        }
        else {
            result = result + pos * mass;
            massSum += mass;
            result = result / massSum;
        }
    }
    cout << "����� ���� ��⥬�: " << result << endl;
}

void FigureSystem::totalSize() {
    int result = 0;
    for (auto figure : figures) {
        result += figure->size();
    }
    cout << "��騩 ࠧ��� ��� 䨣��: " << result << endl;
}

void FigureSystem::sortFigures() {
    sort(figures.begin(), figures.end());
}

void FigureSystem::controller(int command) {
    switch (command) {
    case 1:
        addFigure();
        break;
    case 2:
        draw();
        break;
    case 3:
        totalSquare();
        break;
    case 4:
        totalPerimeter();
        break;
    case 5:
        centerOfMass();
        break;
    case 6:
        totalSize();
        break;
    case 7:
        sortFigures();
        break;
    case 8:
        exit(0);
    default:
        cout << "�������⭠� �������" << endl;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
}

int main() {
    FigureSystem menu;
    menu.menu();
    return 0;
}