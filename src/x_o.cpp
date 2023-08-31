#include "includes.hpp"
using namespace std;

void Game();
char check_winner(char* place);
int move();
int comp_move(char* place, char comp, char gamer);
void print(char* place);
bool legal(char* place, int pole);

   void Game() {
       char place[] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
        bool kross, player;
        int pole;
        char gamer, comp;
        char winner;
        srand((unsigned)time(0));
        player = rand() % 2;
        if (player) {
            gamer = 'X';
            comp = 'O';
        }
        else {
            gamer = 'O';
            comp = 'X';
        }
        print(place);
        do {
            if (player) {
                pole = move() - 1;
                place[pole] = gamer;
                player = !player;
            }
            else {
                pole = comp_move(place, comp, gamer);
                place[pole] = comp;
                player = !player;
            }
            print(place);
            winner = check_winner(place);
        } while (winner == ' ');
        if (winner == gamer) {
            cout << "congratulations";
	    system("stop");
        }
        else if (winner == comp) {
            cout << "i`m sory i win";
	    system("stop");

        }
        else {
            cout << "nothing scary";
	    system("stop");

        }        
   }
    
    char check_winner(char* place) {
        //4
        if (place[4] != ' ' && (((place[4] == place[0]) && (place[4] == place[8])) || ((place[4] == place[2]) && (place[4] == place[6])) || ((place[4] == place[3]) && (place[4] == place[5])) || ((place[4] == place[1]) && (place[4] == place[7])))) {
            return place[4];
        }
        //0
        if (place[0] != ' ' && (((place[1] == place[0]) && (place[0] == place[2])) || ((place[3] == place[0]) && (place[6] == place[0])))) {
            return place[0];
        }
        //8
        if (place[8] != ' ' && (((place[6] == place[8]) && (place[7] == place[8])) || ((place[8] == place[2]) && (place[5] == place[8])))) {
            return place[8];
        }
        //nobody
        if (place[0] != ' ' && place[1] != ' ' && place[2] != ' ' && place[3] != ' ' && place[4] != ' ' && place[5] != ' ' && place[6] != ' ' && place[7] != ' ' && place[8] != ' ') {
            return 'N';
        }
        return ' ';
    }

    int move() {
        cout << "-------------" << endl;
        cout << "| 1 | 2 | 3 |" << endl;
        cout << "-------------" << endl;
        cout << "| 4 | 5 | 6 |" << endl;
        cout << "-------------" << endl;
        cout << "| 7 | 8 | 9 |" << endl;
        cout << "-------------" << endl;
        cout << "write the place which you want to place your figure ";
        int move;
        cin >> move;
        return move;
    }

    bool legal(char* place, int pole) {
        if (place[pole] == ' ') {
            return true;
        }
        return false;
    }

    int comp_move(char* place, char comp, char gamer) {
        char* copy = new char[9];
        for (int i = 0; i < 9; i++) {
            copy[i] = place[i];
        }
        //win
        for (int i = 0; i < 9; i++) {
            if (legal(copy, i)) {
                copy[i] = comp;
                if (comp == check_winner(copy)) {
                    delete[] copy;
                    return i;
                }
                copy[i] = ' ';
            }
        }
        //not lose
        for (int i = 0; i < 9; i++) {
            if (legal(copy, i)) {
                copy[i] = gamer;
                if (gamer == check_winner(copy)) {
                    delete[] copy;
                    return i;
                }
                copy[i] = ' ';
            }
        }
        //center
        if (legal(copy, 4)) {
            delete[] copy;
            return 4;
       }
        //angles
        if (legal(copy, 0)) {
            delete[] copy;
            return 0;
        }
        if (legal(copy, 2)) {
            delete[] copy;
            return 2;
        }
        if (legal(copy, 6)) {
            delete[] copy;
            return 6;
        }
        if (legal(copy, 8)) {
            delete[] copy;
            return 8;
        }
        //lines
        if (legal(copy, 1)) {
            delete[] copy;
            return 1;
        }
        if (legal(copy, 3)) {
            delete[] copy;
            return 3;
        }
        if (legal(copy, 5)) {
            delete[] copy;
            return 5;
        }
        if (legal(copy, 7)) {
            delete[] copy;
            return 7;
        }
    }

    void print(char* place) {
        cout << "| " << place[0] << " | " << place[1] << " | " << place[2] << " |" << endl;
        cout << "| " << place[3] << " | " << place[4] << " | " << place[5] << " |" << endl;
        cout << "| " << place[6] << " | " << place[7] << " | " << place[8] << " |" << endl;
        cout << endl;
    }










int main()
{
    Game();
    std::cout << "Hello World!\n";
}
