#include <iostream>
#include <fstream>
#include <string>

int main() {
    int mx_cal = -1, cur_cal;
    int top_cal[3] = {-1, -1, -1};

    std::string temp;
    std::ifstream input("D01_input.txt");

    if(input.good()) {
        while(getline(input, temp)) {
            if(temp == "") {
                mx_cal = cur_cal;
                
                int idx = 0;
                while(idx < 3 && mx_cal < top_cal[idx]) { idx++; }
                if(idx < 3) { top_cal[idx] = mx_cal; }

                cur_cal = 0;
            } else {
                cur_cal += std::stoi(temp);
            }
        }
    }
    
    int sum = 0;
    for(int cal: top_cal) {
        sum += cal;
    }

    std::cout << sum;
}
