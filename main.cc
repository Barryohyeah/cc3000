#include <iostream>
#include "floor.h"
#include <fstream>
using namespace std;


int main(int argc, char *argv[]) {
    cin.exceptions(ios::eofbit | ios::failbit);
    std::string cmd;
    Floor f;
    std::string playerRace;

    try {
        cout << "Would you like to control the randomization of game?" << endl;
        while(true) {
            cout << "Yes/No:" << endl;
            cin >> cmd;
            if (cmd == "Yes") {
                f.controlRan();
                break;
            } else if (cmd == "No") {
                break;
            } else {
                cout << "Invalid Commend" << endl;
            }
        }
        cout << "Please pick a race to begin with:" << endl;
        cout << "Human (type H)  Drawf (type D)  Elves (type E)  Orc (type O)" << endl;
        while (true) {
            cin >> cmd;
            //cmd = "H";
            if (cmd == "H") {
                playerRace = cmd;
                f.setFloor(playerRace);
                break;
            } else if (cmd == "D") {
                playerRace = cmd;
                f.setFloor(playerRace);
                break;
            } else if (cmd == "E") {
                playerRace = cmd;
                f.setFloor(playerRace);
                break;
            } else if (cmd == "O") {
                playerRace = cmd;
                f.setFloor(playerRace);
                break;
            } else {
                cout << "Invalid race type, please choose from the following:" << endl;
                cout << "Human (type H)  Drawf (type D)  Elves (type E)  Orc (type O)" << endl;
            }
        }
        cout << f;
        cout << "'@' is your current location. Right now you are able to start your adventure, good luck!" << endl;
         //exit(1);
        while (true) {
            if (f.isWin()) {
                cout << "Congratulations! You have won!" << endl;
                break;
            } else if (f.isLose()) {
                cout << "You lose the Game!" << endl;
                break;
            } else {
                cin >> cmd;
                try {
                    if (cmd == "move") {
                        cout << "Please choose the direction to move:" << endl;
                        ifstream compass {"compass.txt"};
                        string s;
                        int len;
                        while (getline(compass, s)) {
                            vector<char> row;
                            len = s.length();
                            for (int i = 0; i < len; ++i) {
                                cout << s[i];
                            }
                            cout << endl;
                        }
                        
                        while (true) {
                            cin >> cmd;
                            if (cmd == "no"|| cmd == "so"|| cmd == "ea"|| cmd == "we"||
                                cmd == "ne"|| cmd == "nw"|| cmd == "se"|| cmd == "sw"){
                                    f.movePC(cmd, playerRace);
                                    if (f.isWin()) {
                                        
                                    }
                                    else {
                                        cout << f;
                                        break;
                                    }
                                } else {
                                    cout << "Invalid direction, Please choose from the following" << endl;
                                    cout << "(no|so|ea|we|ne|nw|se|sw)" << endl;
                                }
                        }
                    }
                    
                    if (cmd == "drink") {
                        f.drinkPotion();
                        cout << f;
                    }
                    
                    if (cmd == "attack") {
                        f.battle("human");
                        cout << f;
                    }
                    
                    if (cmd == "surrender") {
                        f.lose();
                        return 1;
                    }

                    if (cmd == "quit") {
                        return 1;
                    }
                } catch (InvalidCommand) { 
                    cout << "Invalid Command" << endl;
                }
            }
        }
    }
    catch (ios::failure &) {
    } // Any I/O failure quits
}