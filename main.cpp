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
        cout << "Добавить фигуру: '1'" << endl;
        cout << "Информация о всех фигурах: '2'" << endl;
        cout << "Получить сумму всех площадей: '3'" << endl;
        cout << "Получить сумму всех периметров: '4'" << endl;
        cout << "Получить центр масс: '5'" << endl;
        cout << "Получить размер всех фигур: '6'" << endl;
        cout << "Сортировка фигур по массе: '7'" << endl;
        cout << "Завершение работы: '8'" << endl;
        int command;
        cin >> command;
        std::cin.ignore(32767, '\n');
        controller(command);
    }
}

void FigureSystem::addFigure() {
    int command;
    cout << "Какую фигуру добаваить?" << endl;
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
        cout << "Неизвестная команда" << endl;
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

    cout << "Сумма площадей всех фигур: " << result << endl;
}

void FigureSystem::totalPerimeter() {
    double result = 0;
    for (auto figure : figures) {
        result += figure->perimeter();
    }

    cout << "Сумма периметров всех фигур: " << result << endl;
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
    cout << "Центр масс системы: " << result << endl;
}

void FigureSystem::totalSize() {
    int result = 0;
    for (auto figure : figures) {
        result += figure->size();
    }
    cout << "Общий размер всех фигур: " << result << endl;
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
        cout << "Неизвестная команда" << endl;
        std::cin.clear();
        std::cin.ignore(32767, '\n');
    }
}

int main() {
    FigureSystem menu;
    menu.menu();
    return 0;
}