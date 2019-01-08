//
// Created by mike on 29/09/16.
//

#include "input.h"

double masvar[10];
double funvar[10];
string funcname[10]; //All fuction names
string multi[10];  //All strings from file
string mas[10];
int con = 0;

void Input(int a) {

    if (a == 1) {

        vector<string> free_vars = get_free_vars();
        for (string var : free_vars) {
            std::cout << var << " = ";
            cin >> masvar[con];
            mas[con] = var;
            con++;
        }
    }
    else {
        cout << "a=2";
    }
    Reading();
}

void Reading() {

    ifstream infiless("input.txt");
    string currentString;
    int fon = 0;

    while (!infiless.eof()) {
        currentString.clear();
        getline(infiless, currentString);   //cicle itself
        if (currentString.size() > 0) {
            unsigned long pos = currentString.find('=');
            string res = currentString.substr(0, pos);
            funcname[fon] = currentString.substr(0, pos);
            //cout<<"funcname["<<fon<<"]"<<"="<<funcname[fon]<<endl;
            //currentString.erase(0, 2);
            unsigned long post = currentString.find(';');
            
            multi[fon] = currentString.substr(pos + 1, post - 2);
            std::cout << "\nFunction: " << multi[fon] << endl; 
            fon++;
        }
    }

    // for (int i = 0; i < fon; i++) {
    //    std::cout << "funcname - " << funcname[i] << " " << "string - " << multi[i] << endl;
    // }

    infiless.close();

    for (unsigned int i = 0; i < fon; i++) {

        double ku = Calculating(multi[i], fon);
        cout << funcname[i] << " == " << ku << endl;
        funvar[i] = ku;

    }
}

double Calculating(string astr, int num) {
    typedef exprtk::symbol_table<double> symbol_table_t;
    typedef exprtk::expression<double> expression_t;
    typedef exprtk::parser<double> parser_t;
    typedef exprtk::parser_error::type error_t;

    //cout << "\n CALCULATING---" << astr << endl;
    std::string expression_str;
    expression_str = astr;
    symbol_table_t symbol_table;

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    for (int i = 0; i < con; i++) {
        symbol_table.add_variable(mas[i], masvar[i]);
    }

    for (int i = 0; i < num; i++) {
        symbol_table.add_variable(funcname[i], funvar[i]);
    }

    parser_t parser;

    if (!parser.compile(expression_str, expression)) {
        printf("Error: %s\tExpression: %s\n",
               parser.error().c_str(),
               expression_str.c_str());

        for (std::size_t i = 0; i < parser.error_count(); ++i) {
            error_t error = parser.get_error(i);
            printf("Err: %02d Pos: %02d Type: [%14s] Msg: %s\tExpression: %s\n",
                   static_cast<unsigned int>(i),
                   static_cast<unsigned int>(error.token.position),
                   exprtk::parser_error::to_str(error.mode).c_str(),
                   error.diagnostic.c_str(),
                   expression_str.c_str());
        }
    }

    double result = expression.value();
   // printf(" result: %20.10f\n", result);
    return result;
}

