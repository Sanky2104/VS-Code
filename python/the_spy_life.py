def reverse(s):
    if len(s) == 0:
        return s
    else:
        return reverse(s[1:]) + s[0]
string=input()
a=[]
new=reverse(string)
for i in new:
    if (i>='a' and i<='z') or (i>='A' and i<='Z') or i==' ':
        a.append(i)
for i in a:
    print(i,end="")