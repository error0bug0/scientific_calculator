from sympy import mathml, sympify
from storage import *
from calculus_calc import *
from complex_calc import *
from equation_calc import *
from calculate_matrix import *

def string_to_mathml(input_string,mode,page,args):
    if input_string == "":
        return ""
    else:
        # Evaluate the input string as a SymPy expression
        if(mode=="show"):
            
            if page=="2":
                sy_string = complex_calculator(input_string,False)
            else:
                sy_string = sympify(input_string,evaluate=False)
            sy_string = sympify(input_string,evaluate=False)

        elif(mode=="eval"):
            if page=="1" :
                sy_string = sympify(input_string,evaluate=True).xreplace(storage)
            elif page=="2":
                sy_string = complex_calculator(input_string,True)
            elif page=="3" or page=="4":
                sy_string = evaluate_matrix_expression(input_string)
                return sy_string
            elif page=="6":
                sy_string = calculus_calc(input_string,args)
            elif page=='7':
                sy_list = evaluate_solve_expression(input_string,args)
                if len(args)==0:
                    sy_string=""
                    for i in range(len(sy_list)):
                        sy_string += f"<msub><mi>x</mi><mi>{i+1}</mi></msub><mo>=</mo><mi>{sy_list[i]}</mi><mo>&nbsp;</mo>"
                        print(sy_string)
                    return sy_string
                else:
                    sy_string = evaluate_solve_expression(input_string,args)

        # Convert the SymPy expression to MathML
        mathml_string = mathml(sy_string, printer='presentation')
        if(mode=="show"):
            mathml_string = mathml_string.replace("&InvisibleTimes;", "*")
        mathml_string = mathml_string.replace("<mo>mn</mo><mn>1</mn>", "")
        mathml_string = mathml_string.replace("<mfenced>", "<mfenced><mo>&lpar;</mo>")
        mathml_string = mathml_string.replace("</mfenced>", "<mo>&rpar;</mo></mfenced>")
        print(mathml_string)
        return mathml_string



