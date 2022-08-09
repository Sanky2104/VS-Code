n=int(input("Enter the number of elements: "))
l=[]
for i in range(n):
    a=int(input())
    l.append(a)
t=int(input("Number to be searched: "))
start=0
end=n
c=0
mid=int((start+end)/2)
while end>start:
    if l[mid]==t:
        flag=mid
        c+=1
        break
    if t > l[mid]:
        start=mid+1
    if t < l[mid]:
        end = mid-1
    mid=int((start+end)/2)
if(c==1):
    print(f"{t} is at position: {mid}")
else:
    print(f"{t} not found")