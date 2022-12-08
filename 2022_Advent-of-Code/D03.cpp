#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream in("D03_input.txt");
    
    string rucksack;
    int sum_prior = 0;

    if(in.good()) {
        in >> rucksack;
        while(!in.eof()) {
            // Find similar element
            int mid = rucksack.length()/2;
            for(int idx = 0; idx < mid; idx++) {
                char current = rucksack[idx];
                for(int jdx = mid; jdx < rucksack.length(); jdx++) {
                    if(rucksack[jdx] == current) {
                        break;
                    }
                }
                if(current > 'Z') { sum_prior += current - 'a' + 1;
                } else { sum_prior += current - 'A';
                }
            }
            in >> rucksack;
        }
    }
    cout << sum_prior;
}
