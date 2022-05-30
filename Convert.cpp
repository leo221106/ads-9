#include "Convert.h"
#include <vector>
#include <stack>
#include <sstream>

std::string Convert::do_prefix(std::string s)
{
    std::stack<std::string> stack;
    std::stringstream ss(s);

    int ans = 0;
    std::string str;

    int i = 0, j = 0;

    for (std::string in; ss >> in;)
    {
        if (in[0] >= '0' && in[0] <= '9')
        {
            try
            {
                ans = stoi(in);
                str.insert(str.length(), in);
                break;
            }
            catch (const std::invalid_argument &ia)
            {
                return "Error";
            }
        }
        i++;

        if (stack.empty())
        {
            stack.push(in);
            continue;
        }

        std::string top = stack.top();

        if ((top == "*" || top == "/") && (in == "+" || in == "-"))
        {
            str.push_back('(');
        }

        stack.push(in);
    }

    std::string prev = "*";

    for (std::string num; ss >> num;)
    {
        if (stack.empty())
            return "Error";
        j++;
        std::string top = stack.top();

        if ((prev == "+" || prev == "-") && (top == "*" || top == "/"))
        {
            str.push_back(')');
        }

        str.push_back(' ');
        str.insert(str.length(), top);
        str.push_back(' ');
        str.insert(str.length(), num);

        int x = 0;

        try
        {
            x = stoi(num);
        }
        catch (const std::invalid_argument &ia)
        {
            return "Error";
        }

        ans = do_operate(top, ans, x);

        prev = top;
        stack.pop();
    }

    if (i != j)
        return "Error";

    str.insert(str.length(), " = ");
    str.insert(str.length(), std::to_string(ans));

    return str;
}

int Convert::do_operate(std::string op, int a, int b)
{
    if (op == "+")
        return a + b;
    if (op == "-")
        return a - b;
    if (op == "*")
        return a * b;
    if (op == "/")
        return a / b;

    return 0;
}
