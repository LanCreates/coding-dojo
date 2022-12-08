#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream IN("D06_input.txt");
string STREAM;

int detect_last_start_packet(int start_length) {
    int first = 0, last = 0;
    bool has_same, is_start = false;

    if(IN.good()) {
        while(last < STREAM.length() && !is_start) {
            // tambah 1 huruf
            last++;
            int idx = first;

            // Lakukan pengecekan, asumsikan berbeda semua
            // jika semua karakter berbeda, has_same = false
            // Ini akan berhenti di posisi huruf yang sama dengan huruf baru
            has_same = false;
            cout << "Checking for: " << STREAM[last]  << " | ";
            while(idx < last && !has_same) {
                has_same = STREAM[last] == STREAM[idx];
                cout << STREAM[idx];
                idx++;
            }
            cout << " (Actual: " << STREAM.substr(first, last - first + 1) << ")" << endl;
            
            // Jika ada huruf yang sama, misalkan di tengah, maka hingga huruf itu terlewat
            // (first >= posisi huruf tadi) has_same akan selalu bernilai salah. Jadi kita
            // bisa skip beberapa pengecekan dengan mulai mengecek dari posisi huruf yang
            // sama tadi
            if(has_same) { first = idx;}
            is_start = !has_same && (last - first == start_length);
        }
    }
    
    // Jika tidak ada yang valid, print -1 dan last + 1 jika sebaliknya
    if(!is_start) { return -1;
    } else { return last + 1;
    }
}

int main() {
    IN >> STREAM;
    int start_length;
    cout << "Start length? "; cin >> start_length; start_length--;
    printf("Last character of start of packet is on position %d\n", detect_last_start_packet(start_length));
}

