# Prefix, infix, postfix -:
# Infix -: <operand> <operator> <operand> 4 * 2 + 3, 5 - 6 / 3
# Prefix (Polish Notation) -: <operator> <operand> <operand>  + * 4 2 3   According to precedance first 4*2 so take its operator and shift in front, then resultant + 3, take operator and shift in front; - 5 / 6 3
# Postfix (Reverse Polish Notation) -: <operand> <operand> <operator> 4 2 * 3 +   According to precedance first 4*2 so take its operator and shift in back, then resultant + 3, take operator and shift in back; 5 6 3 / -

def operators(s, x, y) :
    if s == '+' :
        return x + y
    elif s == '-' :
        return x - y
    elif s == "*" :
        return x * y
    elif s == "//" :
        return x // y
    elif s == "/" :
        return x / y

def prefix_eval(lis) :
    stack = []
    a = {'+', '-', '*', '//', '/'}
    for i in range(len(lis) - 1, -1, -1) :
        if lis[i] in a :
            x = stack.pop()
            y = stack.pop()
            stack.append(operators(lis[i], x, y))
        else :
            stack.append(lis[i])
    return stack[0]

def postflix_eval(lis) :
    stack = []
    a = {'+', '-', '*', '//', '/'}
    for i in range(len(lis)) :
        if lis[i] in a:
            y = stack.pop()
            x = stack.pop()
            stack.append(operators(lis[i], x, y))
        else :
            stack.append(lis[i])
    return stack[0]

# Move from left to right.
# If operand output it
# If operator -:  If the precedence of the scanned operator is greater than the precedence of the operator in the stack (or the stack is empty or the stack contains a ‘(‘ ), push it. Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack. (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.) 
# If the scanned character is an ‘(‘, push it to the stack.
# If the scanned character is an ‘)’, pop the stack and output it until a ‘(‘ is encountered, and discard both the parenthesis.
# Repeat
# At last pop and output from the stack until it is not empty
def precedence(a, b):
    l = ['^', '*', '/', '+', '-']
    for i in l :
        if i == a :
            return 1
        elif i == b :
            return 0
        
def infix_to_postfix(lis) :
    a = {'+', '-', '*', '//', '/', '^'}
    stack = []
    ans = []
    for i in lis:
        if i == '(':
            stack.append(i)
        elif i == ')' :
            while stack[-1] != '(' :
                ans.append(stack.pop())
            stack.pop()
        elif i in a :
            if (len(stack) != 0) and (stack[-1] in a):
                if (stack[-1] != i) and precedence(i, stack[-1]) :
                    stack.append(i)
                else :
                    while 1 :
                        if (len(stack) == 0) or (stack[-1] == ')') or (stack[-1] == '(') :
                            break
                        if (stack[-1] == i) or precedence(stack[-1], i) :
                            ans.append(stack.pop())
                        else :
                            break
                    stack.append(i)
            else :
                stack.append(i)
        else :
            ans.append(i)
    while (len(stack) != 0) :
        ans.append(stack.pop())
    return ans

def infix_to_prefix (lis) :
    # same as infix_to_postfix, difference is that it is traversed from last and '(' replaced by ')' and vice-versa
    a = {'+', '-', '*', '//', '/', '^'}
    stack = []
    ans = []
    for j in range(len(lis) - 1, -1, -1):
        i = lis[j]
        if i == ')':
            stack.append(i)
        elif i == '(' :
            while stack[-1] != ')' :
                ans.append(stack.pop())
            stack.pop()
        elif i in a :
            if (len(stack) != 0) and (stack[-1] in a):
                if (stack[-1] != i) and precedence(i, stack[-1]) :
                    stack.append(i)
                else :
                    while 1 :
                        if (len(stack) == 0) or (stack[-1] == ')') or (stack[-1] == '(') :
                            break
                        if (stack[-1] == i) or precedence(stack[-1], i) :
                            ans.append(stack.pop())
                        else :
                            break
                    stack.append(i)
            else :
                stack.append(i)
        else :
            ans.append(i)
    while (len(stack) != 0) :
        ans.append(stack.pop())
    ans.reverse()
    return ans

a = ['-', '+', 7, '*', 4, 5, '+', 2, 0]
# print(prefix_eval(a))
b = [4, 6, '+', 2, '//', 5, '*', 7, '+']
# print(postflix_eval(b))
exp = "a+b*(c^d-e)^(f+g*h)-i"
exp2 = "(a-b/c)*(a/k-l)"
# print(''.join(infix_to_postfix(exp)))
# print(''.join(infix_to_postfix(exp2)))
print(''.join(infix_to_prefix(exp2)))