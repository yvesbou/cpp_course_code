//
// Created by Yves Boutellier on 09.10.20.
//

#include "Task02.h"

#include <vector>
#include <cassert>

int main()
{
    std::vector<bool> v(1);
    std::vector<bool>::pointer pb = &v[0];
    assert(*pb == false);
    *pb = true;
    assert(v[0] == true);
    std::vector<bool>::const_pointer cbp = pb;
    assert(*cbp == true);
    v[0] = false;
    assert(*cbp == false);

    bool p = true;
    std::cout << typeid(p).name();
    if (typeid(v) == typeid(p)){
        std::cout << "aha";
        std::copy(v.begin(), v.end(), std::ostreambuf_iterator<char>(ofs));};
}