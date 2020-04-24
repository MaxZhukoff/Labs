#ifndef PRG_6_TEMPLATE_H
#define PRG_6_TEMPLATE_H

template<class T>
class GreaterThan {
public:
    GreaterThan(T value) : value(value) {
        this->value = value;
    }
    bool operator() (T num)const {
        return num > value;
    }
private:
    T value;
};

template<class InputIt, class UnaryPredicate>
bool None_of(InputIt first, InputIt last, UnaryPredicate p) {
    for (; first != last; ++first) {
        if (p(*first)) {
            return false;
        }
    }
    return true;
}

template<class InputIt, class Compare>
bool Is_sorted(InputIt begin, InputIt end, Compare comp) {
    InputIt first = begin;
    InputIt last = end;

    if (first != last) {
        InputIt next = first;
        while (++next != last) {
            if (!comp(*next)) {
                first = next;
                continue;
            }

            if (*next < *first)
                return false;
            first = next;
        }
    }
    return true;
}

template<class InputIt, class T>
InputIt Find_backward(const InputIt& begin, const InputIt& end, const T& value) {
    InputIt first = begin;
    InputIt last = end;
    while (first < last) {
        --last;
        if (*last == value) {
            return last;
        }
    }
    return end;
}

#endif