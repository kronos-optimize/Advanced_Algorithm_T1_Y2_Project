#include <iostream>
#include <cmath>
#include <list>
#include <stack>
#include <string>
#include <bits/stdc++.h>

using namespace std;

struct Calculation{
    string expression;
    double result;
};

struct CalculationResult{
    bool success;
    double value;
    string errorMessage;
};

class Calculator{
private:
    list<Calculation> history;

    bool parenthesesPair(char open, char close){
        if (open == '(' && close == ')'){
            return true;
        }else{
            return false;
        }
    }

    bool checkBalancedParentheses(string expr){
        stack<char>string;
        for(int i = 0; i < expr.length(); i++){
            if(expr[i] == '('){
                string.push(expr[i]);
            }else if(expr[i] == ')'){
                if(string.empty() || !parenthesesPair(string.top(), expr[i])){
                    return false;
                }else{
                    string.pop();
                }
            }
        }
        return string.empty();
    }

public:
    CalculationResult calculate(double operand1, char op, double operand2){
        CalculationResult result;
        switch(op){
            case '+':
                result.success = true;
                result.value = operand1 + operand2;
                break;

            case '-':
                result.success = true;
                result.value = operand1 - operand2;
                break;
            
            case '*':
                result.success = true;
                result.value = operand1 * operand2;
                break;  

            case '/':
                if(operand2 == 0){
                    result.success = false;
                    result.errorMessage = "Cannot divide by 0";
                }else{
                    result.success = true;
                    result.value = operand1 / operand2;
                }
                break;

            default:
                result.success = false;
                result.errorMessage = "Error: Invalid operation.";
                break;
        }

        if (result.success) {
            string historyEntry = to_string(operand1) + " " + op + " " + to_string(operand2) + " = " + to_string(result.value);
            addHistory(historyEntry, result.value);
        }
        return result;
    }

    bool checkParentheses(string expr){
        if(!checkBalancedParentheses(expr)){
            cout << "Error: Parentheses are not balanced." << endl;
            return false;
        }
        return true;
    }

    CalculationResult logarithm(double value){
        CalculationResult result;
        if(value <= 0){
            result.success = false;
            result.errorMessage = "Error: Cannot calculate logarithm of a non-positive number.";
        }else{
            result.success = true;
            result.value = log(value);
            addHistory("log(" + to_string(value) + ") = " + to_string(result.value), result.value);
        }
        return result;
    }

    CalculationResult squareRoot(double value){
        CalculationResult result;
        if(value < 0){
            result.success = false;
            result.errorMessage = "Error: Cannot calculate square root of a negative number.";
        }else{
            result.success = true;
            result.value = sqrt(value);
            addHistory("sqrt(" + to_string(value) + ") = " + to_string(result.value), result.value);
        }
        return result;
    }

    CalculationResult factorial(int value){
        CalculationResult result;
        if(value < 0){
            result.success = false;
            result.errorMessage = "Error: Cannot calculate factorial of a negative number.";
        }else{
            result.success = true;
            result.value = 1;
            for(int i = 1; i <= value; i++){
                result.value *= i;
            }
            addHistory(to_string(value) + "! = " + to_string(result.value), result.value);
        }
        return result;
    }

    CalculationResult exponential(double value){
        CalculationResult result;
        result.success = true;
        result.value = exp(value);
        addHistory("exp(" + to_string(value) + ") = " + to_string(result.value), result.value);
        return result;
    }

    bool logicAnd(int operand1, int operand2){
        bool result = operand1 && operand2;
        string expression = to_string(operand1) + " && " + to_string(operand2) + " = " + to_string(result);
        addHistory(expression, result);
        return result;
    }

    bool logicOr(int operand1, int operand2){
        bool result = operand1 || operand2;	
        string expression = to_string(operand1) + " || " + to_string(operand2) + " = " + to_string(result);
        addHistory(expression, result);
        return result;
    }

    bool logicNot(int operand){
        bool result = !operand;
        string expression = "!" + to_string(operand) + " = " + to_string(result);
        addHistory(expression, result);
        return result;
    }

    bool logicXor(int operand1, int operand2){
        bool result = operand1 ^ operand2;
        string expression = to_string(operand1) + " xor " + to_string(operand2) + " = " + to_string(result);
        addHistory(expression, result);
        return result;
    }

    bool logicXnor(int operand1, int operand2){
        bool result = !(operand1 ^ operand2);
        string expression = to_string(operand1) + " xnor " + to_string(operand2) + " = " + to_string(result);
        addHistory(expression, result);
        return result;
    }

    bool logicNand(int operand1, int operand2){
        bool result = !(operand1 && operand2);
        string expression = to_string(operand1) + " nand " + to_string(operand2) + " = " + to_string(result);
        addHistory(expression, result);
        return result;
    }
    
    void addHistory(string expression, double result){
        history.push_back({expression, result});
    }

    void displayHistory(){
        if(history.empty()){
            cout << "No history available." << endl;
            return;
        }
        cout << "History:" << endl;
        for(const auto &entry : history){
            cout << entry.expression << endl;
        }
    }

    void clearHistory(){
        history.clear();
        cout << "History cleared." << endl;
    }

    void searchHistory(string keyword){
        if(history.empty()){
            cout << "No history available." << endl;
            return;
        }
        bool found = false;
        cout << "Search results:" << endl;
        for(const auto &entry : history){
            if(entry.expression.find(keyword) != string::npos){
                cout << entry.expression << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No matching entries found." << endl;
        }
    }

    void deleteFromHistory(string keyword){
        if(history.empty()){
            cout << "No history available." << endl;
            return;
        }
        bool deleted = false;
        for(auto iteration = history.begin(); iteration != history.end();){
            if(iteration->expression.find(keyword) != string::npos){
                iteration = history.erase(iteration);
                cout << "Deleted entries containing: " << keyword << endl;
                deleted = true;
            }else{
                ++iteration;
            }
        }
        if (!deleted) {
            cout << "No matching entries found to delete." << endl;
        }
    }
};

int main(){
    Calculator calculator;
    int option;

    do{
        cout << "\n--- Simple Calculator ---" << endl;
        cout << "1. Basic Calculation (e.g., 2 + 3)" << endl;
        cout << "2. Logarithm (log(x))" << endl;
        cout << "3. Square Root (sqrt(x))" << endl;
        cout << "4. Factorial (x!)" << endl;
        cout << "5. Exponential (e^x)" << endl;
        cout << "6. Logic" << endl;
        cout << "7. View History" << endl;
        cout << "8. Clear History" << endl;
        cout << "9. Search History" << endl;
        cout << "10. Delete From History" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        if(option < 0 || option > 10) {
            cout << "Invalid option. Please try again." << endl;
            continue;
        }


        switch(option){
            case 1:{
                string expression;
                cout << "Enter expression: ";
                cin.ignore();
                getline(cin, expression);
                
                if (!calculator.checkParentheses(expression)) {
                    break;
                }

                expression.erase(remove_if(expression.begin(), expression.end(), ::isspace), expression.end());
                size_t openPos = expression.find('(');
                if (openPos != string::npos) {
                    size_t closePos = expression.find(')');
                    string innerExpr = expression.substr(openPos + 1, closePos - openPos - 1);

                    size_t innerOpPos = string::npos;
                    for (size_t i = 0; i < innerExpr.length(); i++) {
                        if (innerExpr[i] == '+' || innerExpr[i] == '-' || 
                            innerExpr[i] == '*' || innerExpr[i] == '/') {
                            innerOpPos = i;
                            break;
                        }
                    }
                    
                    string num1 = innerExpr.substr(0, innerOpPos);
                    string num2 = innerExpr.substr(innerOpPos + 1);
                    char op = innerExpr[innerOpPos];
                    
                    double operand1 = stod(num1);
                    double operand2 = stod(num2);
                    
                    CalculationResult innerResult = calculator.calculate(operand1, op, operand2);
                    if (!innerResult.success) {
                        cout << innerResult.errorMessage << endl;
                        break;
                    }
                    
                    expression.replace(openPos, closePos - openPos + 1, to_string(innerResult.value));
                }
                
                size_t opPos = string::npos;
                for (size_t i = 0; i < expression.length(); i++) {
                    if (expression[i] == '+' || expression[i] == '-' || 
                        expression[i] == '*' || expression[i] == '/') {
                        opPos = i;
                        break;
                    }
                }
                
                if (opPos == string::npos) {
                    cout << "Invalid expression" << endl;
                    break;
                }

                string num1 = expression.substr(0, opPos);
                string num2 = expression.substr(opPos + 1);
                char op = expression[opPos];

                try {
                    double operand1 = stod(num1);
                    double operand2 = stod(num2);
                    
                    CalculationResult result = calculator.calculate(operand1, op, operand2);
                    if (result.success) {
                        cout << "Result: " << result.value << endl;
                    } else {
                        cout << result.errorMessage << endl;
                    }
                } catch (...) {
                    cout << "Invalid expression" << endl;
                }
                break;
            }

            case 2:{
                double value;
                cout << "Enter value for logarithm: ";
                cin >> value;
                cout << "Result: " << calculator.logarithm(value).value << endl;
                break;
            }

            case 3:{
                double value;
                cout << "Enter value for square root: ";
                cin >> value;
                cout << "Result: " << calculator.squareRoot(value).value << endl;
                break;
            }

            case 4:{
                int value;
                cout << "Enter value for factorial: ";
                cin >> value;
                cout << "Result: " << calculator.factorial(value).value << endl;
                break;
            }

            case 5:{
                double value;
                cout << "Enter value for exponential: ";
                cin >> value;
                cout << "Result: " << calculator.exponential(value).value << endl;
                break;
            }

            case 6:{
                int operand1, operand2;
                string op;
                cout << "Enter logic expression using 1s and 0s (e.g., 1 && 0): ";
                cin >> operand1 >> op;

                if(op == "&&"){
                    cin >> operand2;
                    cout << "Result: " << calculator.logicAnd(operand1, operand2) << endl;
                }else if(op == "||"){
                    cin >> operand2;
                    cout << "Result: " << calculator.logicOr(operand1, operand2) << endl;
                }else if(op == "!"){
                    cout << "Result: " << calculator.logicNot(operand1) << endl;
                }else if(op == "xor"){
                    cin >> operand2;
                    cout << "Result: " << calculator.logicXor(operand1, operand2) << endl;
                }else if(op == "xnor"){
                    cin >> operand2;
                    cout << "Result: " << calculator.logicXnor(operand1, operand2) << endl;
                }else if(op == "nand"){
                    cin >> operand2;
                    cout << "Result: " << calculator.logicNand(operand1, operand2) << endl;
                }else{
                    cout << "Invalid operation." << endl;
                }

                break;
            }

            case 7:
                calculator.displayHistory();
                break;

            case 8:
                calculator.clearHistory();
                break;
            
            case 9:{
                string keyword;
                cout << "Enter keyword to search: ";
                cin >> keyword;
                calculator.searchHistory(keyword);
                break;
            }

            case 10:{
                string keyword;
                cout << "Enter keyword to delete: ";
                cin >> keyword;
                calculator.deleteFromHistory(keyword);
                break;
            }

            case 0:
                cout << "Exiting calculator..." << endl;
                break;
            
            default:
                cout << "Invalid option. Please try again." << endl;
        }

    }while(option!=0);

    return 0;
}
