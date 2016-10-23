#include "tcpconnector.h"
#include "menu_option.h"
#include "send_program.h"
#include "client_menu.h"
#include "retrieve_corrected.h"
#include "expression/evaluate_program.h"
#include <stdlib.h>
#include <iostream>


using namespace std;

int main(int argc, char* argv[]){
    if (argc != 3) {
        cout << "usage: " << argv[0] << " <port> <ip>\n";
        exit(1);
    }

    ClientMenu menu;
    shared_ptr<MenuOption> sp1(new SendProgram("Send a file", argv[2], atoi(argv[1])));
    shared_ptr<MenuOption> sp2(new EvaluateProgram("Evaluate a program"));
    shared_ptr<MenuOption> sp3(new RetrieveCorrected("Retrieve corrections", argv[2], atoi(argv[1])));
    menu.addOption(sp1);
    menu.addOption(sp2);
    menu.addOption(sp3);
    string choix = "";
    int iChoix;
    do{
        cout << menu << endl;
        cin >> choix;
        iChoix = atoi(choix.c_str());
        if(iChoix > 0 && iChoix <= menu.getOptionsNumber()){
            menu.executeOption(iChoix-1);
        } else {
            std::cout << "Not valid choice!" << endl;
            std::cout << "Closing..." << endl;
        }
    } while(iChoix > 0 && iChoix <= menu.getOptionsNumber());
    return 0;
}
