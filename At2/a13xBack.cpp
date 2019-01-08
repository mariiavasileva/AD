#include "a13xBack.h"

string doubleToStr(double t);

void ValBack(node* current_oper, node* prevOper, string strPrevDer, double retValue)
{
    // TODO
	for(auto it = funs.begin(); it != funs.end(); it++)
	{
		if(it->first.compare(current_oper->value) == 0){
			//retValue = tempValue;
			ValBack(it->second, prevOper, strPrevDer, retValue);
			//itFunc = true;
			return;
		}
	}

    string retCurrentDer = "";
	string childF = "", retD = "";
	double currentValue = 0.0, tempValue = 0.0;

	// Расчет текущей производной
	if (prevOper != nullptr)
	{		
		if(prevOper->value.compare("+") == 0)
        {
			retCurrentDer = "1";
			retValue *= 1.;
			tempValue = retValue;			
        }else if(prevOper->value.compare("-") == 0)
		{ 
			retCurrentDer = "(-1)";
			retValue *= -1.;
			tempValue = (-1) * retValue;
        }else if(prevOper->value.compare("*") == 0)        
		{
			currentValue = 1.0;
            double nodeValue = 0.0;
			for (auto el: prevOper->operands)
			{				
				if(el == current_oper) continue;

				if (!retCurrentDer.empty()) retCurrentDer += '*';
				 
				retCurrentDer += nodeValueToStr(el, false, nodeValue, "");								
				currentValue *= nodeValue;								
			}

			tempValue = retValue * currentValue;			
		}
        else if(prevOper->value.compare("/") == 0)
		{
			// w1 / w2
			double retValueS = 0.0;
			string secondValue = "";
			double dblSecondValue = 0.0;
			
			if(prevOper->operands[0] == current_oper)
			{
				secondValue = prevOper->operands[1]->value;				
				//Это w1, тогда получаем 1/w2
				retCurrentDer = "(1/" + secondValue + ")";
				nodeValueToStr(prevOper->operands[1], false, dblSecondValue, "");
				currentValue = 1 / dblSecondValue;
			}
			else{
				secondValue = prevOper->operands[0]->value;

				retD = nodeValueToStr(current_oper, false, retValueS, "");
				retCurrentDer = "(-(" + secondValue + ")/(";
				// Это w2, тогда (-w1/(w2)^2)
				retCurrentDer += retD;
				retCurrentDer += ")^2)";

				currentValue = -dblSecondValue / pow(retValueS, 2.0);
			}

			tempValue = retValue * currentValue;
		}
		else if(prevOper->value.compare("^") == 0)
        {		
			double retValueS = 0.0, tempValue2 = 0.0;			
			retD = nodeValueToStr(current_oper, false, retValueS, "");
			
			nodeValueToStr(prevOper->operands[1], false, tempValue2, "");

			retCurrentDer = "(" + prevOper->operands[1]->value + 
							"*" + retD + "^" + doubleToStr(tempValue2 - 1.0) + ")";
			
			currentValue = tempValue2 * pow(retValueS, tempValue2 - 1.0);
			tempValue = retValue * currentValue;
		}		
		else if(prevOper->value.compare("sin") == 0)
		{
			double retValueS = 0.0;
			retD = nodeValueToStr(current_oper, false, retValueS, "");
			retCurrentDer = "cos(" + retD + ")";
			currentValue = cos(retValueS);
			tempValue = retValue * currentValue;
		}
		else if(prevOper->value.compare("cos") == 0)
		{
			double retValueS = 0.0;
			retD = nodeValueToStr(current_oper, false, retValueS, "");
			retCurrentDer = "(-sin(" + retD + "))";
			currentValue = -sin(retValueS);
			retValue *= currentValue;
		}
		else if(prevOper->value.compare("tg") == 0)
		{
			double retValueS = 0.0;
			retD = nodeValueToStr(current_oper, false, retValueS, "");
			retCurrentDer = "(1/(cos(" + retD + ")^2)";
			
			currentValue = 1/pow(cos(retValueS), 2.0);
			tempValue = retValue * currentValue;
		}
		else if(prevOper->value.compare("ctg") == 0)
		{
			double retValueS = 0.0;
			retD = nodeValueToStr(current_oper, false, retValueS, "");
			retCurrentDer = "(-1/sin(" + retD + ")^2)";

			currentValue = -1/pow(sin(retValueS), 2.0);
			tempValue = retValue * currentValue;
		}
		else if(prevOper->value.compare("exp") == 0)
		{
			double retValueS = 0.0;
			retD = nodeValueToStr(current_oper, false, retValueS, "");
			retCurrentDer = "exp(" + retD + ")";

			currentValue = exp(retValueS);
			tempValue = retValue * currentValue;
		}
		else if(prevOper->value.compare("log") == 0)
		{
			double retValueS = 0.0;
			retD = nodeValueToStr(current_oper, false, retValueS, "");
			retCurrentDer = "(1/(ln10 * " + retD + "))";

			currentValue = 1 / (log(10) * retValueS);
			tempValue = retValue * currentValue;
		}
    }

	// Добавление текущей переменной к предыдущей
	if (prevOper == nullptr)
	{
		retCurrentDer = '1';
		retValue = 1.0;
		tempValue = retValue;
	}
	else
		retCurrentDer = strPrevDer + "*" + retCurrentDer;

	// Переходим на следующие узлы
	int indexElement = 0;
    if(current_oper->operands.size() > 0)
	{
		retValue = tempValue;
	    for (auto el: current_oper->operands)
		{
			if(el->value.at(0) <= '9' && el->value.at(0) >= '0') continue;
			//for(auto it = funs.begin(); it != funs.end(); it++)
			//	if(it->first.compare(el->value) == 0){					
			//		ValBack(it->second, current_oper, retCurrentDer, retValue);
			//		break;
			//	}else
		    	ValBack(el, current_oper, retCurrentDer, retValue);
		}
	}
    else
	{
		//bool itFunc = false;
        //for(auto it = funs.begin(); it != funs.end(); it++)
        //{
        //   if(it->first.compare(current_oper->value) == 0){
		//		retValue = tempValue;
        //        ValBack(it->second, prevOper, retCurrentDer, retValue);
		//		itFunc = true;
        //       break;
        //    }
        //}
		//if(!itFunc)
		//{
		setprecision(20);
			cout << current_oper->value << " == " << retCurrentDer << " == " <<doubleToStr(tempValue) << endl;
			//if(!strPrevDer.empty()) strPrevDer += " //+// ";
		//}
    }
}

string doubleToStr(double t)
{
	std::ostringstream strs;
	strs << t;
	return strs.str();
}