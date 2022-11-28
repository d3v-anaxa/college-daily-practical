#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#define TEMP_STR_LEN 50
using namespace std;

class parent {
        vector<std::string> hidden_skill{};
    public :
        vector<std::string> open_skill{};
        void add_parent_skill();
        void show_parent_skill();
};

void parent::add_parent_skill() {
    char yORn = 'y';
    string temp_skill;
    do {
        unsigned choice{}; 
        std::cout << "Write skill -> " && std::cin >> temp_skill;
        std::cout << "1. Add as hidden skill." << std::endl;
        std::cout << "2. Add as open skill." << std::endl << std::endl;
        std::cout << "Enter choice : " && std::cin >> choice;
        switch(choice) {
            case 1 :
                parent::hidden_skill.push_back(temp_skill);
                std::cout << "Added as hidden_skill" << std::endl;
                break;
            default:
                parent::open_skill.push_back(temp_skill);
                std::cout << "Added as open_skill [default] " << std::endl;
                break;
        }
        std::cout << "Do you want to continue ?? [Y/n]" && std::cin >> yORn;
    } while ( tolower(yORn) == 'y');
    std::cout << "Parent skills added successfully!" << std::endl;
}

void parent::show_parent_skill() {
    std::cout << "Parent hidden skill(s) : ";
    for (auto i : parent::hidden_skill) {
        std::cout << i;
    }   std::cout << std::endl;
    std::cout << "Parent open skill(s) : ";
    for (auto i : parent::open_skill) {
        std::cout << i;
    }   std::cout << std::endl;
}

class child : public parent {
    private :
        vector<std::string> inherited_skill{};
    public :
        void show_inherited_skill();
};

void child::show_inherited_skill() {
    parent::show_parent_skill();   
    child::inherited_skill.insert( child::inherited_skill.end(), parent::open_skill.begin(), parent::open_skill.end() );
    std::cout << "Inherited Skills are : ";
    for (auto i : child::inherited_skill) {
        std::cout << i ;
    }   std::cout << std::endl;
}

int main(void) {
    parent father;
    father.add_parent_skill();
    child elon;
    elon.show_inherited_skill();
}
