// Created by a13x on 01.11.16.
//

#include "a13x.h"

string makeAddition(node* ad_oper, string varName, bool der, double &valResult);
string makeMultiplication(node* ad_oper, string varName, bool der, double &valResult);
string makeDivision(node* ad_oper, string varName, bool der, double &valResult);
string makeSubtraction(node* ad_oper, string varName, bool der, double &valResult);
string makeTrigonometry(node* ad_oper, string varName, bool der, double &valResult);
string makePow(node* ad_oper, string varName, bool der, double &valResult);
// Преобразование числа в строку
//std::ostringstream strs;
//	strs << t;
//	return strs.str();

// Преобразует значение узла в текстовый вид
//
// Параметры:
//	n - узел, значение которого необходимо вывести
// 	useMapping - признак использования сложного отображения.
//					Если true, тогда переменная X будет выведена не как X,
//						а как число, введенное пользователем или автоматически.
//  nodeValue - посчитанное значение
// Возвращаемое значение:
//	Строка - значение узла
//
string nodeValueToStr(node* n, bool useMapping, double &nodeValue, string varName)
{
    bool bItValue = false;
    bool bItVar = false;
    int iIndexMasvar = -1;

    if(n->value.at(0) <= '9' && n->value.at(0) >= '0')
        bItValue = true;
    else
    {
        int i = 0;
        for(auto el: mas)
		{
			if(n->value.compare(el) == 0){ bItVar = true; break;}
            if(el.empty()) break;
			i++;
		}
        if(bItVar) iIndexMasvar = i;
    }
    
    // Если это число, то надо перевести строку в число
    if(bItValue)  {
        if(useMapping) {nodeValue = 0.0; return "";}
        else{
        nodeValue = atof(n->value.c_str()); return n->value;
        }
    }

    // Надо учесть, если это операнд, то вызвать Val

    // Если это переменная, то надо искать значение в mas/masvar
    if(bItVar)
    {
        //nodeValue = masvar[iIndexMasvar];
        if(useMapping)
        { 
            if(n->value.compare(varName) == 0){nodeValue = 1; return "1";}
            else{nodeValue = 0; return "";}
          //  std::ostringstream strs;
          //  strs << nodeValue;
          //  return strs.str();
        }else
        {
            nodeValue = masvar[iIndexMasvar];
            return n->value;
        }
    }
    
    if(n->operands.size()==0){
        // Если это не функция, а переменная функция, то ее необходимо сначала получить
        // из глобальной переменной и передать этот узел в функцию Val
        // TODO

        for(auto it = funs.begin(); it != funs.end(); it++)
        {
            if(it->first.compare(n->value)==0)
                if(useMapping){
                    string str = Val(it->second,varName, true, nodeValue);
                    if(!str.empty()) str = "(" + str + ")";
                    return str;
                }
                else
                    return "(" + Val(it->second,varName, false, nodeValue) + ")";                
        }
    }else
    {
        if(useMapping){
            string str = Val(n,varName, true, nodeValue);
            if(!str.empty()) str = "(" + str + ")";
            return str;
        }
        else
            return "(" + Val(n,varName, false, nodeValue) + ")";
    }
    
        
        

	//if(n->operands.size() != 0)
	//	return ""; // Это не лист, это функция.
	
	// Это либо число либо переменная либо переменная-функция (ПФ)


        // переменная или функция
        // в случае функции вызываем val для вычисления!
        //  Получается рекурсия через шаг (Val -> nodeValueToStr -> Val)
		
        // mas - массив имен свободных переменных
        //      заполняется в файле Input.cpp в функции Input
        // masvar - массив значений свободных переменных
        //      синхронизирован с mas по индексу
		

	
} // nodeValueToStr()

// Рекурсивная функция для вычисления частной производной (в текстовом и числовом виде)
//	методом "Forward mode"
//
// Parameters:
//	ad_oper - узел. При первом вызове - корень дерева.
//	varName - имя переменной, по которой дифференциируем
//	der - признак дифференциации
//	valResult - [OUT] - вычисленное значение производной
//
// Возвращаемое значение:
// 	Строка - текстовое представление производной
string Val(node* ad_oper, string varName, bool der, double &valResult){
    string str, rstr;

    // (sin U)` = cos U * U`;
    // (cos U)` = (-sin U) * U`
    // (tg U)` = (1/cos^2 U) * U`
    // (ctg U)` = -(1/sin^2 U) * U`
    // (exp U)` = exp U * U`
    // (lg U)` = (1/U*ln10) * U`

    if (ad_oper->value.compare("+") == 0)
        str = makeAddition(ad_oper, varName, der, valResult);
    else if(ad_oper->value.compare("-") == 0)
        str = makeSubtraction(ad_oper, varName, der, valResult);    
    else if(ad_oper->value.compare("*") == 0)
        str = makeMultiplication(ad_oper, varName, der, valResult);
    else if(ad_oper->value.compare("/") == 0)
        str = makeDivision(ad_oper, varName, der, valResult);
    else if(ad_oper->value.compare("^") == 0)
        str = makePow(ad_oper, varName, der, valResult);
    else if(ad_oper->value.compare("sin") == 0
        || ad_oper->value.compare("cos") == 0
        || ad_oper->value.compare("tg") == 0
        || ad_oper->value.compare("ctg") == 0
        || ad_oper->value.compare("exp") == 0
        || ad_oper->value.compare("log") == 0)
        str = makeTrigonometry(ad_oper, varName, der, valResult);

    return str;
}

string makeAddition(node* ad_oper, string varName, bool der, double &valResult)
{
    string str, rstr;
    double retValue = 0.0, tempValue = 0.0; 
    
    for(auto operand : ad_oper->operands)
    {		
        if (der)
        {
            rstr = nodeValueToStr(operand, true, tempValue, varName);
            
            if(!rstr.empty()){
                if (!str.empty()) str += '+';
                str += rstr;
                retValue += tempValue;
            }            
        }
        else {
            if (!str.empty()) str += '+';
            // Вывести значение переменной, функции или просто число.
            rstr = nodeValueToStr(operand, false, tempValue, varName);
            str += rstr;
            retValue += tempValue;					
        }        
    }

    valResult = retValue;
    return str;
} // makeAddition()

string makeMultiplication(node* ad_oper, string varName, bool der, double &valResult)
{
    string str = "", rstr = "", rstr2 = "";
    double retValue = 0.0, tempValue = 0.0, tempValue2 = 0.0;
    node *first, *second = nullptr;

    first = ad_oper->operands[0];
    second = ad_oper->operands[1];

    // xy
    
    if(der)
    {
        str = nodeValueToStr(first, true, retValue, varName);
        if(retValue != 0.0){
            rstr = nodeValueToStr(second, false, tempValue, varName);
            retValue *= tempValue;
            if(!str.empty()) str += "*";
            str += rstr;
        }

        rstr = nodeValueToStr(second, true, tempValue, varName);
        if(tempValue != 0.0){
            rstr2 = nodeValueToStr(first, false, tempValue2, varName);
            if(tempValue*tempValue2 != 0.0)
            {
                retValue += (tempValue*tempValue2);
                if(!rstr.empty()) rstr += "*";
                rstr+=rstr2;
                
                if(!str.empty() && !rstr.empty()) str += "+";            
                str += rstr;
            }
        }
    }else
    {
        str = nodeValueToStr(first, false, retValue, varName);

        // Надо получить второе значение
        rstr = nodeValueToStr(second, false, tempValue, varName);
        retValue *= tempValue;
        if(!str.empty()) str += "*";
        str += rstr;
    }

    valResult = retValue;
    return str;
} // makeMultiplication()

string makeDivision(node* ad_oper, string varName, bool der, double &valResult)
{
    string str = "", rstr = "", rstr2 = "";
    double retValue = 0.0, tempValue = 0.0, tempValue2 = 0.0;
    node *first, *second = nullptr;

    first = ad_oper->operands[0];
    second = ad_oper->operands[1];

    if(der)
    {
        str = nodeValueToStr(first, true, retValue, varName);
        if(retValue != 0.0){
            rstr = nodeValueToStr(second, false, tempValue, varName);
            retValue *= tempValue;
            if(!str.empty()) str += "*";
            str += rstr;
        }

        rstr = nodeValueToStr(second, true, tempValue, varName);
        if(tempValue != 0.0){
            rstr2 = nodeValueToStr(first, false, tempValue2, varName);
            if(tempValue*tempValue2 != 0.0)
            {
                retValue -= (tempValue*tempValue2);
                if(!rstr.empty()) rstr += "*";
                rstr+=rstr2;
                
                if(!rstr.empty()) str += "-";
                str += rstr;
            }
        }

        if(!str.empty() && str.compare("()") != 0){
            // V^2
            rstr = nodeValueToStr(second, false, tempValue2, varName);
            tempValue2 *= tempValue2;
            retValue = retValue / tempValue2;
            rstr = "(" + rstr + ")^2";
            str = "(" + str + ")/" + rstr;
        }

    }else
    {
        str = nodeValueToStr(first, false, retValue, varName);
        // Надо получить второе значение
        rstr = nodeValueToStr(second, false, tempValue, varName);
        retValue /= tempValue;        
        str += "/" + rstr;
    }

    valResult = retValue;
    return str;
} // makeDivision()

string makeSubtraction(node* ad_oper, string varName, bool der, double &valResult)
{
    string str = "", rstr;
    double retValue = 0.0, tempValue = 0.0;    
    
    for(auto operand : ad_oper->operands)
    {	
        if (der)
        {            
            rstr = nodeValueToStr(operand, true, tempValue, varName);

            if(!rstr.empty()){
                if (!str.empty()) str += '-';
                str += rstr;
                retValue += tempValue;
            }
        }
        else {
            if (!str.empty()) str += '-';
            // Вывести значение переменной, функции или просто число.
            rstr = nodeValueToStr(operand, false, tempValue, varName);
            str += rstr;
            retValue += tempValue;					
        }
    }

    valResult = retValue;
    return str;
} // makeSubtraction()

string makeTrigonometry(node* ad_oper, string varName, bool der, double &valResult)
{
    // (sin U)` = cos U * U`;
    // (cos U)` = (-sin U) * U`
    // (tg U)` = (1/cos^2 U) * U`
    // (ctg U)` = -(1/sin^2 U) * U`
    // (exp U)` = exp U * U`
    // (lg U)` = (1/U*ln10) * U`

    string str = "", rstr;
    double retValue = 0.0, tempValue = 0.0;

    rstr = nodeValueToStr(ad_oper->operands[0], false, tempValue, varName);

    if (ad_oper->value.compare("cos") == 0)		
        str += der ? "(-sin" : "cos";
    else if (ad_oper->value.compare("sin") == 0)
        str += der ? "cos" : "sin";
    else if (ad_oper->value.compare("tg") == 0)
        str += der ? "(1/(cos" : "tg";
    else if (ad_oper->value.compare("ctg") == 0)
        str += der ? "(-1/(sin" : "ctg";
    else if (ad_oper->value.compare("exp") == 0)
        str += "exp";
    else if (ad_oper->value.compare("log") == 0)
        str += der ? "(1/(ln10 * " : "log";
    
    str += '(';
    str += rstr;
    str += ')';
    if ((ad_oper->value.compare("tg") == 0 || ad_oper->value.compare("ctg") == 0) && der) str += ")^2)";
    if (ad_oper->value.compare("cos") == 0 && der) str += ')';
    if (ad_oper->value.compare("log") == 0 && der) str += "))";

    if (ad_oper->value.compare("cos") == 0)
        retValue = der ? -sin(tempValue) : cos(tempValue);
    else if (ad_oper->value.compare("sin") == 0)
        retValue = der ? cos(tempValue) : sin(tempValue);
    else if (ad_oper->value.compare("tg") == 0)
        retValue = der ? 1 / pow(cos(tempValue), 2) : tan(tempValue);
    else if (ad_oper->value.compare("ctg") == 0)
        // В радиане 57.29578 градусов
        retValue = der ? -1 / pow(sin(tempValue), 2) : cos(tempValue) / sin(tempValue);
    else if (ad_oper->value.compare("exp") == 0)
        retValue = exp(tempValue);
    else if (ad_oper->value.compare("log") == 0)
        retValue = 1 / (log(10) * tempValue);

    if (der)
    {
        rstr = nodeValueToStr(ad_oper->operands[0], true, tempValue, varName);
        retValue *= tempValue;

        if (!rstr.empty())
        {
            if (rstr.compare("0")==0)
                str.clear();
            else if (rstr.compare("1")!=0)
            {
                str += '*';
                str += "(" + rstr + ")";
            }
        }
        else
            str.clear();
    }

    valResult = retValue;
    return str;
} // makeTrigonometry()

string makePow(node* ad_oper, string varName, bool der, double &valResult)
{
    string str = "", rstr;
    double retValue = 0.0, tempValue = 0.0, tempValue2 = 0.0;
    // (U^k)` = U`*(k*U^(k-1))
    if(der)
    {
        str = nodeValueToStr(ad_oper->operands[0], true, retValue, varName);
        if(str.empty() || str.compare("()") == 0) {valResult = retValue; return "";}
        
        rstr = nodeValueToStr(ad_oper->operands[0], false, tempValue, varName); 

        nodeValueToStr(ad_oper->operands[1], false, tempValue2, "");
        tempValue = tempValue2 * pow(tempValue, tempValue2 - 1);
        retValue *= tempValue;

        std::ostringstream streamTempValue2;
        streamTempValue2 << (tempValue2-1);        

        rstr = ad_oper->operands[1]->value + rstr + "^" + streamTempValue2.str();
        str += "*(" + rstr + ")";

        // TODO
    }else{
        str = nodeValueToStr(ad_oper->operands[0], false, tempValue, varName);
        rstr = nodeValueToStr(ad_oper->operands[1], false, tempValue2, "");
        str += "^" + rstr;
        retValue = pow(tempValue,tempValue2); 
    }

    valResult = retValue;
    return str;
} // makePow()