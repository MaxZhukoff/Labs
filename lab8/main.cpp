#include "Kub.h"

using namespace std;

int menu(){
    system("cls");
    std::cout << "1. Save or read file." << std::endl;
    std::cout << "2. Normal?" << std::endl;
    std::cout << "3. Show kubik." << std::endl;
    std::cout << "4. Spin turn." << std::endl;
    std::cout << "5. Scrol." << std::endl;
    std::cout << "6. Find result." << std::endl;
    std::cout << "7. Exit." << std::endl;
    int var;
    std::cin >> var;
    return var;
}

int secmenu(){
    std::cout << "1. Save." << std::endl;
    std::cout << "2. Read." << std::endl;
    int znach;
    std::cin >> znach;
    return znach;
}

int main(){
    int i;
    Kub cube;
    int var;
    bool flag = true;
    do{
        var = menu();
        if(var == 1){
            int znach;
            znach = secmenu();
            if(znach == 1){
                cube.save();
            }else if(znach == 2){
                cube.read();
            }
        }else if(var == 2){
            flag = cube.check();
            if(flag == false){
                cout << "Bad Kub." << endl;
            }else{
                flag = cube.find(0, 0);
                if(flag == true){
                    cout << "OK" << endl;
                }else{
                    cout << "Bad Kub." << endl;
                }
            }
        }else if(var == 3){
            cube.show();
        }else if(var == 4){
            cube.myspin();
        }else if(var == 5){
            cube.scrol();
        }else if(var == 6){
            cube.setString();
            flag = cube.check();
            if(flag == true){
                flag = cube.find(0, 0);
                if(flag == true){
                    cube.getString();
                    cout << endl;
                }else{
                    cout << "Bad angle or edge." << endl;
                }
            }else{
                cout << "Take new kub." << endl;
            }
        }
        if(var != 7){
            system("pause");
        }
    }while(var != 7);
    return 0;
}