// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {

    int inputX;
    int inputY;
    int p_X = 4;
    int p_Y = 7;
    int max = 7;
    string p = "S";
    string brett[8][8] = {
        {" ", " ", " ", " ", " ", " ", " ", " ", },
        {" ", " ", " ", " ", " ", " ", " ", " ", },
        {" ", " ", " ", " ", " ", " ", " ", " ", },
        {" ", " ", " ", " ", " ", " ", " ", " ", },
        {" ", " ", " ", " ", " ", " ", " ", " ", },
        {" ", " ", " ", " ", " ", " ", " ", " ", },
        {" ", " ", " ", " ", " ", " ", " ", " ", },
        {" ", " ", " ", " ", " ", " ", " ", " ", },
    };

    brett[p_Y][p_X] = p;

    while (true)
    { 
        system("cls");
        cout << "    ";
        for (int dumm = 1; dumm <= max + 1; dumm++) {
            cout << "  " << dumm << " ";
        }

        cout << endl;

        for (int y = 0; y <= 7; y++) {
            cout << " " << y + 1 << " ";
            for (int x = 0; x <= 7; x++) {
                cout << " | " << brett[y][x];
                if (x == 7) {
                    cout << " |";
                }
            }
            cout << endl;
            cout << endl;
        }
        cout << "Sie sind bei " << "(" << p_X + 1 << "/" << p_Y + 1 << ")" << endl;

        cout << "Bitte geben sie X wert ein" << endl;
        cin >> inputX;
        cout << "Bitte geben Sie Y Wert ein" << endl;
        cin >> inputY;

        inputX--;
        inputY--;

        if ((inputX >= 1 && inputX <= 8) && (inputY >= 1 && inputY <= 8)) {
            if ((inputX == p_X - 1 && inputY == p_Y - 2) || (inputX == p_X + 1 && inputY == p_Y - 2) || (inputX == p_X + 1 && inputY == p_Y + 2) || (inputX == p_X - 1 && inputY == p_Y + 2) || (inputX == p_X + 2 && inputY == p_Y - 1) || (inputX == p_X + 2 && inputY == p_Y + 1) || (inputX == p_X - 2 && inputY == p_Y + 1) || (inputX == p_X - 2 && inputY == p_Y - 1)) {
                brett[p_Y][p_X] = " ";
                brett[inputY][inputX] = p;
                p_Y = inputY;
                p_X = inputX;
            }
            else {
                cout << "Keine gültige Bewegung" << endl;
            }
        } else {
            cout << "Nicht gültige Eingabe" << endl;
        }

    }

    return 0;
}