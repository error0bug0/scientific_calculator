from sympy import Matrix, sympify, symbols, simplify,mathml
from storage_matrix import *

# 定义矩阵字典来存储矩阵
matrices = {}

def add_matrix(name, matrix_str):
    try:
        matrices[name] = Matrix(sympify(matrix_str))
    except Exception as e:
        print(f"Error adding matrix {name}: {str(e)}")

def cross(a:Matrix, b:Matrix):
    return a.cross(b)

def trace(a):
    return a.trace()

def det(a):
    return a.det()

def dot(a:Matrix, b:Matrix):
    return a * b

def inv(a:Matrix):
    return a.inv()

def transpose(a:Matrix):
    return a.T


def evaluate_matrix_expression(expression_str):  
    expr=eval(expression_str)
    #expr = sympify(expr,locals={'cross':cross,'trace':trace,'det':det,})
    expr =mathml(expr,printer='presentation')
    expr=expr.replace('<mfenced close="]" open="[">','<mo>[</mo>')
    expr=expr.replace('</mfenced>','<mo>]</mo>')
    print(expr)
    return expr
        # 将矩阵符号替换为实际矩阵
        #expr = parse_expr(expression_str, local_dict=matrices)
       #result = expr.evalf()
        #return result
    #except Exception as e:
    #    return f"Error evaluating expression: {str(e)}"

#ar=input()
#evaluate_matrix_expression(ar)
    
   


# 运行如python calculate.py "[[1, 2, 3]] [[4, 5, 6]] [[0, 0, 0]] "cross(vecA,vecB+vecC)+Matrix([[1,2,3]])
#Matrix([[1,1,1]]).cross(Matrix([[1,2,3]]))+Matrix([[1,2,3]])
#cross(Matrix([[1,2,3]]),Matrix([[1,1,1]]))