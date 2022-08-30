l=[]
for i in range(5):
    a = int(input("Enter a number: "))
    l.append(a)
print("List: ",l)
a = int(input("Enter a number: "))
l.append(a)
print("List: ",l)
a = int(input("Enter a number: "))
pos = int(input("Enter the position: "))
l.insert(pos-1,a)
print("List: ",l)
for i in range(3):
    a = int(input("Enter a number: "))
    l.append(a)
print("List: ",l)