#include <iostream>
#include <string>
#include <array>

bool anagram(const std::string s, const std::string t){
    if (s.length() != t.length()) {
        return false;
    }
    std::array<int, 256> charCount{};
    for (char c : s) {
        charCount[static_cast<unsigned char>(c)]++;
    }
    for (char c : t) {
        charCount[static_cast<unsigned char>(c)]--;
        if (charCount[static_cast<unsigned char>(c)] < 0) {
            return false;
        }
    }

    return true;
}

int main(){
    std::string s,t;
    std::cout << "s: ";
    std::cin >> s;
    std::cout << "t: ";
    std::cin >> t;
    if (anagram(s, t)) std::cout << "True\n";
    else std::cout << "False\n";
    
    system("pause");
    return 0;
}
