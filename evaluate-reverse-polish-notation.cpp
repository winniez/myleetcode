/*
Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/
/*
Feb 9 2014
Solution:
- Scan input from front
-- convert and push integer into stack
-- once reaches an operator, pop out 2 integers from stack, perform operation, push result into stack
Note:
pay attention to the left and right operand, especially the - and / operation.
*/
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> container;
        int cur, tmp1, tmp2;
        for (int i = 0; i<tokens.size(); i++)
        {
            if (tokens[i] == "+")
            {
                tmp1 = container.top();
                container.pop();
                tmp2 = container.top();
                container.pop();
                cur = tmp2 + tmp1;
                container.push(cur);
            }
            else if (tokens[i] == "-")
            {
                tmp1 = container.top();
                container.pop();
                tmp2 = container.top();
                container.pop();
                cur = tmp2 - tmp1;
                container.push(cur);
            }
            else if (tokens[i] == "*")
            {
                tmp1 = container.top();
                container.pop();
                tmp2 = container.top();
                container.pop();
                cur = tmp2 * tmp1;
                container.push(cur);
            }
            else if (tokens[i] == "/")
            {
                tmp1 = container.top();
                container.pop();
                tmp2 = container.top();
                container.pop();
                cur = tmp2 / tmp1;
                container.push(cur);
            }
            else
            {
                // convert std::strin to c string and use atoi
                cur = atoi(tokens[i].c_str());
                container.push(cur);
            }
        }
        return container.top();
    }
};
