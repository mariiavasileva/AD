//
// Created by mariia on 26/09/16.
//

#include "model.h"

vector<string> vars;
map<string, node*> funs;

void push_var(string var)
{
    if(find(vars.begin(), vars.end(), var) == vars.end())
    {
        vars.push_back(var);
    }
}

void push_fun(string name, node* root)
{
    if(funs.find(name) == funs.end())
    {
        funs.insert(make_pair(name, root));
    }
    else
    {
        stringstream s;
        s << "Function " << name << " has already been defined";
        throw invalid_argument(s.str());
    }
}

node* push_node(string value, vector<node*> operands)
{
    return new node(value, operands);
}

// getting a string representation of the node in infix notation
string node_to_string_infix(node* n)
{
    stringstream s;
    // checking whether n is an operation node
    if(n->operands.size() > 1)
    {
        for(int i = 0; i < n->operands.size() - 1; i++)
        {
            s << node_to_string_infix(n->operands.at(i));
            s << n->value;
        }
        s << node_to_string_infix(n->operands.at(n->operands.size() - 1));
    }
    else if(n->operands.size() == 1)
    {
        s << n->value << "(" << node_to_string_infix(n->operands.front()) << ")";
    }
    else
    {
        s << n->value;
    }
    return s.str();
}

vector<string> get_free_vars()
{
    vector<string> result;
    for(string var : vars)
    {
        if(funs.find(var) == funs.end())
        {
            result.push_back(var);
        }
    }
    return result;
}

bool is_terminal(node* n)
{
    return n->operands.empty();
}