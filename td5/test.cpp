include <algorithm>

#include <iostream>
#include <string>

int main() {
    std::string hw( "Hello World" );
    std::cout << hw << std::endl;
    std::reverse( hw.begin(), hw.end() );
    std::cout << hw << std::endl;
}
