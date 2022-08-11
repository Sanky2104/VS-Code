a = int(input("Enter a number: "))
print(f"\nOriginal number: {a}")
a=[int(x) for x in str(a)]
a.reverse()
print("Reversed number: ", end="")
for i in a:
    print(i, end="")