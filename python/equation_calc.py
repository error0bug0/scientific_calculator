from sympy import sympify
from sympy import Symbol
from sympy import solve
x=Symbol('x')

def solve_expression(expression):
    expr=sympify(expression)
    
 
    solution = solve(expr, x)
    return solution



def evaluate_expression(expression, value):
    expr=sympify(expression)
    expr = expr.subs(x, value)
    result = expr.evalf() 
    return result


def evaluate_solve_expression(expression,args):
    if len(args)==0:
        return solve_expression(expression)
    else :
        return evaluate_expression(expression, args[0])