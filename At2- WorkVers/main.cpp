#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "model.h"
#include "input.h"
#include "a13xBack.h"
//#include "a13x.h"

extern "C"
{
    #include "./parser/parser.h"
}

extern "C" int yyparse();
extern "C" FILE *yyin;

using namespace std;

int main(int argc, char* argv[]) {

    string filename("input.txt");
    int ii=9;
    FILE *input = fopen(filename.c_str(), "r");
    // make sure it's valid:
    if (!input)
    {
        exit(EXIT_FAILURE); 
        // dsf
    }
    
    // set lex to read from it instead of defaulting to STDIN:
    yyin = input;
    // parse through the input until there is no more:
    do
    {
        yyparse();
    }
    while (!feof(yyin));

    cout << "\n\nNAMES:" << endl;
    for(string var : vars)
    {
        cout << var << endl;
    }

    cout << "\n\nFUNCTIONS:" << endl;
    for(auto it = funs.begin(); it != funs.end(); it++)
    {
        cout << it->first << " == " << node_to_string_infix(it->second) << endl;
    }

    vector<string> free_vars = get_free_vars();
    cout << "\n\nFREE VARIABLES:" << endl;
    for(string var : free_vars)
    {
        cout << var << endl;
    }

    cout << "\nINPUT OPTIONS:" << endl;
    int iAnswer;
    cin >> iAnswer;
    if (iAnswer == 1)
        //cout << "1\n";
        Input(1);
        else if (iAnswer == 2)
        //cout << "2\n";
        Input(2);
    else {
        cout << "\n You have made not right choice, sorry, good bye...";
    }

    double valResult = 0.0;
    string strResult;
    for(auto it = funs.begin(); it != funs.end(); it++)
    {
        cout << "*********\n** FUNCTION " << it->first << " *******\n";
        //strResult = Val(it->second, "t", true, valResult);        5
        //cout << "x = " << strResult << endl << " val = " << valResult << endl;
        cout << "1. Forward\n";
        strResult = Val(it->second, "x", true, valResult);
        cout << "x = " << strResult << endl << " val = " << setprecision(20)<< valResult << endl;
        //cout << it->first << " == " << node_to_string_infix(it->second) << endl;
        cout << "\n2. Back\n";
        strResult = "";
        ValBack(it->second, nullptr, strResult, valResult);
        //cout << "x = " << strResult << endl << " val = " << valResult << endl;
        cout << "\n\n";
    }

    cout << "\n\nend\n";
    return 0;
}