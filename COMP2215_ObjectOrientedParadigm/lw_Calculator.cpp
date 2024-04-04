#include <iostream>
#include <fstream>
#include "Operation.h"
using namespace std;

int main() {
    const string INPUT_FILE = "InputFile.txt";
    const string OUTPUT_FILE = "OutputFile.txt";

    ifstream fInput(INPUT_FILE);
    ofstream fOutput(OUTPUT_FILE);

    const unsigned short MAX_OPERATIONS = 20;

    Operation* oper_ary[MAX_OPERATIONS];

    int num_opers = 0;
    char op;
    double left, right;

    while (fInput >> op >> left >> right && num_opers < MAX_OPERATIONS) {
        switch (op) {
        case '+':
            oper_ary[num_opers] = new Add(left, right);
            break;
        case '-':
            oper_ary[num_opers] = new Subtract(left, right);
            break;
        case '*':
            oper_ary[num_opers] = new Multiply(left, right);
            break;
        case '/':
            oper_ary[num_opers] = new Divide(left, right);
            break;
        default:
            cerr << "Invalid operator: " << op << endl;
            continue;
        }
        fOutput << oper_ary[num_opers]->Result() << endl;
        num_opers++;
    }

    for (int i = 0; i < num_opers; i++) {
        delete oper_ary[i];
    }

    fInput.close();
    fOutput.close();


    return 0;
}