string=input()
a=[]
l=len(string)
count=0
for i in string:
    if i not in a :
        a.append(i)
        count=count+1
if count==l:
    print("Unique")
else:
    print("Deja Vu")