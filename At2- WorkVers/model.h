//
// Created by mariia on 26/09/16.
//

#ifndef AUTODIFF_MODEL_H
#define AUTODIFF_MODEL_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

// node of the tree of mathematical expression
struct node
{
    // either a name of operation or a value of the operand (const or identifier)
    string value;
    // vector is empty if the node is terminal and non-empty if the node is operation node
    vector<node*> operands;

    inline node(const node &rhs)
            : value(rhs.value), operands(rhs.operands)
    {
    }

    inline node(const string value, const vector<node*> operands)
            : value(value), operands(operands)
    {
    }

    inline node(const string value)
            : value(value)
    {
    }

    inline node()
    {
    }

    inline node &operator =(const node &rhs)
    {
        value = rhs.value;
        operands = rhs.operands;

        return *this;
    }

};

extern vector<string> vars;
extern map<string, node*> funs;

node* push_node(string, vector<node*>);
string node_to_string_infix(node*);
bool is_terminal(node*);

void push_var(string);
void push_fun(string, node*);
vector<string> get_free_vars();


#endif //AUTODIFF_MODEL_H
