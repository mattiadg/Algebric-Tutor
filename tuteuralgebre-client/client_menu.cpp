#include "client_menu.h"
#include <cstddef>
#include <iostream>

ClientMenu::ClientMenu()
{
    //ctor
}

ClientMenu::~ClientMenu()
{
    //dtor
}

void ClientMenu::addOption(std::shared_ptr<MenuOption> option)
{
    if(option != NULL){
        options.push_back(option);
    }
}

void ClientMenu::executeOption(int pos)
{
    options[pos]->execute();
}

int ClientMenu::getOptionsNumber()
{
    return options.size();
}

std::ostream& operator<<(std::ostream& os, const ClientMenu& menu){
    int i = 1;
    os << "Choose an option:" << endl;
    for(shared_ptr<MenuOption> option : menu.options ){
        os << i++ << ") " << *option << std::endl;
    }
    return os;
}
