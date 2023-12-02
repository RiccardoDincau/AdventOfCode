#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Numero argomenti invalido" << endl;
        exit(0);
    }

    fstream in_f;
    in_f.open(argv[1], ios::in);

    int s = 0;
    char buffer[100];

    while (in_f.getline(buffer, 100)) {
        int i = 0;
        char c = buffer[i];

        char calib_value[3] = "\0";

        while (c != '\0') {
            if (c >= '0' && c <= '9') {
                if (calib_value[0] == '\0') {
                    calib_value[0] = c;
                }
                calib_value[1] = c;
            }
            i++;
            c = buffer[i];
        }

        calib_value[3] = '\0';
        s += atoi(calib_value);
    }

    cout << "s: " << s << endl;

    return 0;
}