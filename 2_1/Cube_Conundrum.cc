#include <iostream>
#include <fstream>

using namespace std;

void add_to_str(char * str, char c);
void reset_str(char * str);

int main(int argc, char * argv[]) {
    if (argc != 2) {
        cout << "NUmero argomenti invalido" << endl;
        exit(0);
    }
    fstream f_in;
    f_in.open(argv[1], ios::in);


    int s = 0;
    char buffer[400];
    char num[4] = "";

    while (f_in.getline(buffer, 400)) {
        int i = 0;
        while (buffer[i] != ' ') {
            i++;
        }   
        i++;
        reset_str(num);
        while (buffer[i] >= '0' && buffer[i] <= '9') {
            add_to_str(num, buffer[i]);
            i++;
        }

        int id = atoi(num);

        while (buffer[i] != ' ') {
            i++;
        }

        bool valid = true;
        while (buffer[i] != '\0') {
            reset_str(num);
            while (buffer[i] >= '0' && buffer[i] <= '9') {
                add_to_str(num, buffer[i]);
                i++;
            }
            i++;
            char col = buffer[i];
            int n = atoi(num);
            switch (col) {
                case 'b': {
                    if (n > 14) {
                        valid = false;
                    }
                    break;
                }
                case 'r': {
                    if (n > 12) {
                        valid = false;
                    }
                    break;
                }
                case 'g': {
                    if (n > 13) {
                        valid = false;
                    }
                    break;
                }
                default: {
                    // cout << "bho" << endl;
                }
            }
        }

        if (valid) {
            s += id;
        }

    }

    cout << "s: " << s << endl;

    return 0;
}

void add_to_str(char * str, char c) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    if (i < 4) {
        str[i] = c;
    }
}

void reset_str(char * str) {
    for (int i = 0; i < 4; i++) {
        str[i] = '\0';
    }
}
