#include <iostream>
#include <fstream>

using namespace std;

struct node {
    char data;
    node *next, *prev;
};

void challenge1() {
    std::ifstream in("D02_input.txt");
    int match_pts;
    int score = 0;
    char home, away;

    // A B C
    // X Y Z
    if(in.good()) {
        in >> away >> home;
        while(!in.eof()) {
            if((home - ('X' - 'A')) != away) {
                if(home == 'X' && away == 'C' || home == 'Y' && away == 'A' || home == 'Z' && away == 'B') 
                {
                    match_pts = 2;
                } else { match_pts = 0; }
            } else { match_pts = 1; }
            
            score += match_pts*3 + (home - 'X' + 1);
            in >> away >> home;
        }
    }
    std::cout << score;
}

void challenge1_CDLL() {
    std::ifstream in("AOC2022_D2_input.txt");

    int score = 0;
    char home, away;

    node* head = new node{'A', NULL, NULL};
    head->next = new node{'B', NULL, head};
    head->next->next = new node{'C', head, head->next};
    head->prev = head->next->next;

    // A B C
    // A <- B <- C <- A
    // X Y Z
    if(in.good()) {
        in >> away >> home;
        while(!in.eof()) {
            home -= 'X' - 'A';
            
            // Search node with our move
            node *ptr = head;
            while(ptr->data != home) { ptr = ptr->next; }

            if(home != away) {
                if(away == ptr->prev->data) { score += 6; }
            } else { score += 3; }

            score += (ptr->data - 'A' + 1);

            // New item
            in >> away >> home;
        }
    }

    std::cout << score << endl;

}

int main() {
    challenge1_CDLL();
    std::ifstream in("AOC2022_D2_input.txt");
    
    node* head = new node{'A', NULL, NULL};
    head->next = new node{'B', NULL, head};
    head->next->next = new node{'C', head, head->next};
    head->prev = head->next->next;

    // A <- B <- C <- A
    int score = 0;
    char away, move;
    if(in.good()) {
        in >> away >> move;
        while(!in.eof()) {
            node* ptr = head;

            while(ptr->data != away) {
                ptr = ptr->next;
            }

            switch(move) {
                case 'X':
                    ptr = ptr->prev;
                    break;
                case 'Y':
                    score += 3;
                    break;
                case 'Z':
                    score += 6;
                    ptr = ptr->next;
                    break;
            }
            
            score += (ptr->data - 'A' + 1);
            in >> away >> move;
        }
    }
    cout << score;
}
