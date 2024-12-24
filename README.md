Final Report
Team Members and Group: 
Chum Phalla, Sam Sotheara (Group 1)
Project Title: Simple but not So Simple Calculator
1. Introduction
Brief description of the problem and its relevance.

Sometimes when we want to keep track of our calculations, we cannot see that in a normal calculator. Many simple calculators do not store the previous calculations we made. That is why this project aims to let the user view their calculations history in a basic calculator. We also want to include another operation, which is the logic operation, that most calculators do not have. We want to perform AND, OR, NOT logic in the calculator. Another problem is that calculators do not check for parentheses errors. This means that if you input expressions with invalid parentheses, the calculator will output an error message.

2. Problem Definition and Requirements
Define the problem in detail and list any requirements or constraints.

The calculator should keep track of the operations or expressions that have been inputted. It should also perform logic operations including AND, OR, NOT, XOR, XNOR, NAND. Another feature we added is validating parentheses in mathematical expressions and outputting an error message for invalid inputs. The calculator should support basic mathematical operations such as addition, subtraction, multiplication, and division. More advanced operations are also added like logarithms, square roots, factorials, and exponentials.
3. Abstract Data Type (ADT) Selection
Justify the choice of ADT(s) and how they fit the problem.

The List data structure will be used to store and manage the calculations history. It suits the problem we are trying to solve because we can easily add, delete, search, and display the history using List. We also use STACK (LIFO) to check the validity of parentheses. The stack helps by pushing opening parentheses and ensuring matching closing parentheses by popping.

4. Implementation Details
Provide a thorough explanation of your implementation, covering the following aspects:

4.1 Data Structure(s)
Specify the data structure(s) and justify their use in solving the problem.

-	Provide a clear API specification for the data structure(s), detailing methods, their parameters, and expected behavior.

Method	Description	Parameter	Returns
shortestPath	Computes the shortest path from a source node to destination node.	Node from
Node to	List of nodes

-	If applicable, include constraints or limitations of your data structure(s).
-	If needed, include a UML class diagram to represent relationships between your classes.

The primary data structure is the calculation history, which is stored using List ADT. We also use structs like Calculation and CalculationResult to store the calculation expressions and results.
API Specifications:
- void addHistory(string expression, double result) : add new expressions and calculations to history
- void displayHistory() : display all calculations in history
- void clearHistory() : delete all the calculations in history
- void searchHistory(string keyword) : search for specific keyword in history
- void deleteFromHistory(string keyword) : delete specific calculations with specific keyword from history

Another data structure used is the Stack ADT. It is used for checking parentheses validity. 
API specifications: 
- bool checkParentheses(const string& expr) : checks whethere the parentheses used are balanced.

Constraints:
- The calculator only provides a limited number of operations, so more other operations like cosine, sine, or power are not supported. 
4.2 Key algorithms
Describe 1 or 2 key algorithms used and how they integrate with the data structure(s).

-	Input/Output: What the algorithm takes as input and produces as output.
-	Step-by-Step Logic: Summarize the main steps and their purpose.

Key Algorithms Used:
- Input: a string expression with or without parentheses
- Output: a boolean indicating whether the parentheses are balanced
To do this: 
 - Traverse the expression character one by one
- push the opening parentheses onto the stack
- when a closing parentheses is encountered, check if it matches the top stack. If it doesn't match, the expression is unbalanced.
- If the stack is empty, the parentheses are balanced. 
5. Performance Analysis
Analyze the time and space complexity of your solution.

Time complexity:
-Parentheses Validation: O(n) where n is the length of the expression.
- Calculation History operations: O(1) for adding a calculation to history. But deleting and searching might be O(n) in the worst case.
Space Complexity:
-Stack for Parentheses validation: O(n) where n is the number of parentheses in the expression.
-Calculation History: O(n) where n is the number of calculations stored in history.

6. Results and Discussion
Summarize your findings and compare them with expectations. Include graphs or tables if applicable.

Overall, the calculator meets the basic expectations of a calculator. It can perform the 4 basic operations: addition, subtraction, multiplication, and division. It can also perform the more advanced operations like factorial, exponential, square root, logarithm, and all the logic expressions. The parentheses validation also works correctly when checking for expressions with unbalanced parentheses.

7. Challenges and Future Improvements
Discuss challenges faced during the project and potential improvements.

The main challenge in this calculator project is to implement checking for parentheses imbalance. It took quite some time to demonstrate that the program can check for the parentheses error. Another challenge is that at first we can only input expressions with no more than one operand. For example, we can only input 1 + 2 and not (1+2)*3. However, this was finally solved. There are also many other limitations to this program. For example, you cannot do logic gates with more than one pair of numbers at a time. You can only do 1&&1 but not 1&&1&&1 at the same time. This is the same with other operations. You cannot do (1+1)/sqrt(4). This has not been implemented yet.

Future improvements:
- Add support for more advanced mathematics like trigonometry (sine, cosine, tangent)
- Limiting the history size to optimize memory usage
- Extend the search function to search more than just numbers but whole expressions.
  
8. References

List any references used during the project.
https://cplusplus.com/forum/general/204570/
https://stackoverflow.com/questions/49641410/stack-implementation-to-check-c-parentheses
https://gist.github.com/mycodeschool/7207410
