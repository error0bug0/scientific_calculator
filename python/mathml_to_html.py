from string_to_mathml import string_to_mathml
import os

html_template = """<!DOCTYPE html>
<html><head><title>MathML</title></head><body>
       <math xmlns='http://www.w3.org/1998/Math/MathML'>
       {}
    </math>
    </body></html>
      
   """
 # 调用函数并获取 MathML 代码
page=input()
str=input()
mode=input()
args=[]
print(page,str,mode)
if page=="6" and mode=="eval":
#current_working_directory = os.getcwd()
   calculus_mode=input()
   args.append(calculus_mode)
   if calculus_mode=="integral_1":
      data_low=input()
      args.append(data_low)
      data_high=input()
      args.append(data_high)
   elif calculus_mode=="diff_1":
      data_value=input()
      args.append(data_value)
if page=="7" and mode=="eval":
   judge_mode=input()
   print(judge_mode)
   if judge_mode=="function":
      value=input()
      args.append(value)
      
# 输出当前的工作目录
#print("当前的工作目录是:", current_working_directory)
mathml_code = (string_to_mathml(str,mode,page,args))
 # 将 MathML 代码插入到 HTML 模板中
html_output = html_template.format(mathml_code) 

input_file_path = f"../../html/input_formula{page}.html"
output_file_path = f"../../html/output_formula{page}.html"
#"C:/Users/Administrator/Desktop/scientific_calculator/html/output_formula4.html"

# 或者，将 HTML 输出保存到文件中
if mode=='show':
   with open(input_file_path, "w") as file:   
      file.write(html_output)
elif mode=='eval':
   with open(output_file_path, "w") as file:   
      file.write(html_output)
print("success")

    
