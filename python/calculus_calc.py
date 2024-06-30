from sympy import sympify
from sympy import Symbol
from sympy import integrate
from sympy import diff
x=Symbol('x')

def calculus_calc(string,args):
    str=sympify(string)
    if args[0]=="integral_1":
        ans=integrate(str,(x,float(args[1]),float(args[2])))
    elif args[0]=="integral_2":
        ans=integrate(str,x)
    elif args[0]=="diff_1":
        ans=diff(str,x).xreplace({x:float(args[1])})
    elif args[0]=="diff_2":
        ans=diff(str,x)
    return ans

#print(calculus_calc("(1+cos(x))**0.5",["integral_1","0","1"]))