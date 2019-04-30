class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        ls = tokens
        tmp = list()
        
        for x in ls:
            if x == "+":
                a = tmp.pop()
                b = tmp.pop()
                # print(" + Front : {}, End : {}, append : {}".format(a,b,b+a))
                tmp.append(int(float(b)+float(a)))
                
            elif x == "-":
                a = tmp.pop()
                b = tmp.pop()
                tmp.append(int(float(b)-float(a)))
                
            elif x == "*":
                a = tmp.pop()
                b = tmp.pop()
                tmp.append(int(float(b)*float(a)))
                
            elif x == "/":
                a = tmp.pop()
                b = tmp.pop()
                tmp.append(int(float(b)/float(a)))
                
            else:
                x = int(x)
                # print("==append== {}".format(x))
                tmp.append(int(x))
        
        return tmp.pop()
        # stack = []
        # for item in tokens:
        #     if item not in ("+", "-", "*", "/"):
        #         stack.append(int(item))
        #     else:
        #         op2 = stack.pop()
        #         op1 = stack.pop()
        #         if item == "+":
        #             stack.append(op1 + op2)
        #         elif item == "-":
        #             stack.append(op1 - op2)
        #         elif item == "*":
        #             stack.append(op1 * op2)
        #         elif item == "/":
        #             stack.append(int(op1 *1.0 / op2))
        # return stack[0]
