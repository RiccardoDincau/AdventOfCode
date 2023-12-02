#include <iostream>
#include <fstream>

using namespace std;

void insert_num(int *nums, int num);
int find_last(int *nums);
int search_number(char* str);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Numero argomenti invalido" << endl;
        exit(0);
    }

    fstream in_f;
    in_f.open(argv[1], ios::in);

    int s = 0;
    char buffer[300];

    while (in_f.getline(buffer, 300)) {
        int n = search_number(buffer);
        cout << n << endl;
        s += n;
    }

    cout << "s: " << s << endl;

    return 0;
}

int search_number(char* str) {
    int numbers_found[200] = {};
    char* numbers[] = {"one", "two", "three", "four", "five", "six",
         "seven", "eight", "nine"};
    
    int numbers_length[] = {3, 3, 5, 4, 4, 3, 5, 5, 4};
    int numbers_prog[9] = {};

    int i = 0;
    char c = str[i];

    while (c != '\0') {
        cout << c;
        for (int j = 0; j < 9; j++) {
            // cout << (c == numbers[j][numbers_prog[j]]) << " ";
            // cout << "j: " << j << " " << numbers[j][0] << " " << numbers_prog[j] << endl << " " << numbers[j][numbers_prog[j]] << endl;
            if (c != numbers[j][numbers_prog[j]]) {
                numbers_prog[j] = 0;
            }

            if (c == numbers[j][numbers_prog[j]]) {
                numbers_prog[j]++;
                
            }

            if (numbers_prog[j] == numbers_length[j]) {
                insert_num(numbers_found, j + 1);
                // cout << j + 1 << "++ ";
            }
            
            // cout << "j: " << j << " " << numbers[j] << " " << numbers_prog[j] << " " << numbers[j][numbers_prog[j]] << " " << (c == numbers[j][numbers_prog[j]]) <<  endl;
        }

        if (c >= '0' && c <= '9') {
            // cout << int(c - '0') << "-- ";
            insert_num(numbers_found, int(c - '0'));
        }

        i++;
        c = str[i];
    }
    cout << endl;

    return numbers_found[0] * 10 + find_last(numbers_found);
}

void insert_num(int *nums, int num) {
    int i = 0;
    while (i < 200 && nums[i] != 0) {
        i++;
    }
    nums[i] = num;
}

int find_last(int *nums) {
    int i = 0;
    while (i < 200 && nums[i] != 0) {
        i++;
    }
    return nums[i - 1];
}