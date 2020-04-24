#include "Vector.h"
#include "template.h"

int main() {
    std::cout << "\t//3. none_of//" << std::endl;
    int num_check;
    std::cout << "Enter the number to check " << std::endl;
    std::cin >> num_check;
    std::vector<int> container1 {0, 1, 2, 3, 4};
    if (None_of(container1.cbegin(), container1.cend(), GreaterThan(num_check))) {
        std::cout << "Greater than "<< num_check << " is not" << std::endl;
    }
    else {
        std::cout << "Greater than "<< num_check << " is" << std::endl;
    }
    Vector v1_1(5, 5, 4, 4); //1.41
    Vector v2_1(0, 0, 0, 0); //0
    Vector v3_1(90, 90, 5, 5); //120.2
    Vector v4_1(90, 90, 5, 5); //120.2
    std::vector<Vector> vec_1{v1_1, v2_1, v3_1};
    if (None_of(vec_1.begin(), vec_1.end(), GreaterThan(v4_1))) {
        std::cout << "In VECTOR greater than v4_1 is not" << std::endl;
    }
    else {
        std::cout << "In VECTOR greater than v4_1 is" << std::endl;
    }

    ///////////////////////////////////////////
    std::cout << "\t//5. is_sorted//" << std::endl;
    int value_check;
    std::cout << "Enter the value to check " << std::endl;
    std::cin >> value_check;
    std::vector<int> container2 {0, 5, -10, 10, 11, 12};
    bool res = Is_sorted(container2.begin(), container2.end(), GreaterThan(value_check));
    if (res) {
        std::cout << "Sorted" << std::endl;
    }
    else {
        std::cout << "Not sorted" << std::endl;
    }
    Vector v1_2(95, 0, 0, 0); //95
    Vector v2_2(-1, 0, -4, 0); //3
    Vector v3_2(90, 90, 5, 5); //120
    Vector v4_2(0, 0, 0, 0); //0
    std::vector<Vector> vec_2 {v1_2, v2_2, v3_2};
    bool res_vec = Is_sorted(vec_2.begin(), vec_2.end(), GreaterThan(v2_2));
    if (res_vec) {
        std::cout << "VECTORS sorted" << std::endl;
    }
    else {
        std::cout << "VECTORS unsorted" << std::endl;
    }

    ///////////////////////////////////////////
    std::cout << "\t//8. find_backward//" << std::endl;
    int find_element;
    std::cout << "Enter the number to search " << std::endl;
    std::cin >> find_element;
    std::vector<int> container3 {0, 1, 2, 3, 4};
    std::vector<int>::const_iterator it3;
    it3 = Find_backward(container3.cbegin(), container3.cend(), find_element);
    if (it3 != container3.cend()) {
        std::cout << "container contains: " << find_element << std::endl;
    }
    else {
        std::cout << "container does not contain: " << find_element << std::endl;
    }
    Vector v1_3(5, 5, 4, 4); //1.41
    Vector v2_3(0, 0, 0, 0); //0
    Vector v3_3(90, 90, 5, 5); //120.2
    Vector v4_3(5, 5, 4, 4); //1.41
    std::vector<Vector> vec_3{v1_3, v2_3, v3_3};
    std::vector<Vector>::const_iterator it_3;
    it_3 = Find_backward(vec_3.begin(), vec_3.end(), v4_3);
    std::cout << "WITH VECTOR:" << std::endl;
    if (it_3 != vec_3.end()) {
        std::cout << "container contains: v4_3" << std::endl;
    }
    else {
        std::cout << "container does not contain: v4_3"  << std::endl;
    }

    return 0;
}