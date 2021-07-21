//
// Created by Yves Boutellier on 05.12.20.
//

#include <iostream>
#include <iterator>
#include <vector>
#include <forward_list>

//std::enable_if<B, T>::type
using namespace std;

template <typename In>
typename enable_if<!is_same<typename iterator_traits<In>::iterator_category, random_access_iterator_tag>::value, typename iterator_traits<In>::difference_type>::type
dist(In first, In last) {
    std::cout << "random" << std::endl;
    auto n = 0;
    while(first!=last) { ++first; ++n; }
    return n;}

template <typename Ran>
typename enable_if<is_same<typename iterator_traits<Ran>::iterator_category, random_access_iterator_tag>::value, typename iterator_traits<Ran>::difference_type>::type
dist(Ran fst, Ran lst) {
    std::cout << "random" << std::endl;
    return lst-fst; }


int main(){

    std::vector<int> v = {1,2,3,4,5,6,7,8};
    std::cout << dist(v.begin(), v.end()) << std::endl;

    std::forward_list<int> l = {1,2,3,4,5};
    std::cout << dist(l.begin(), l.end());

}