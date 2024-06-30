index=int(input())
print(index)
if index==0:
    str="from sympy import Symbol\n"

    fill_str="storage={"
    row=int(input())
    for i in range(row):
        key=input()
        value=input()
        if key!='':
            str+=f"{key}=Symbol('{key}')\n"
            fill_str+=f"{key}:{value},"
    fill_str+="}"
    str+=fill_str
    print(str)
    with open('../../python/storage.py','w') as file:
        file.write(str)
else:
    str="from sympy import Matrix\n"

    
    row=int(input())
    for i in range(row):
        key=input()
        value=input()
        if key!='':
            str+=f"{key}=Matrix({value})\n"
    print(str)
    with open('../../python/storage_matrix.py','w') as file:
        file.write(str)