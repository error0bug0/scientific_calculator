from sympy import symbols, simplify, sympify

def complex_calculator(input_string,mod):
    expr = sympify(input_string,evaluate=mod)

    simplified_expr = simplify(expr,evaluate=mod)


    return simplified_expr
    

