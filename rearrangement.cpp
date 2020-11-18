#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>



int main()
{
    std::vector<std::string> v{ std::istream_iterator<std::string>{std::cin}, {} };
    sort(begin(v), end(v));

    do {
        copy(begin(v), end(v), std::ostream_iterator<std::string>{std::cout, ", "});
        std::cout << std::endl;
    } 
    while (next_permutation(begin(v), end(v)));  //перестановка 

    return 0;
}