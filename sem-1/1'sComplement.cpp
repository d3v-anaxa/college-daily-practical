#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

std::string complement1 (string binarystr) {
    std::string complement1 {};
    for (size_t i = 0; i < binarystr.length(); ++i ) {
        switch (binarystr[i]) {
            case '0' : 
                complement1 += '1';
                break;
            case '1' :
                complement1 += '0';
                break;
            case '.' :
                complement1 += '.';
                break;
            default :
                std::cout << "Invalid Binary String" << std::endl;
                exit(EXIT_FAILURE);
        }
    }
    std::cout << "1's Complement : " << complement1 << std::endl;
    return complement1;
}

int main (void) {
    std::string binarystr {};
    std::cout << "Enter binary string : " && std::cin >> binarystr;
    complement1(binarystr);
    return 0;
}
