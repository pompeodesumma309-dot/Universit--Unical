L2=[1,2,-1]
print(L2)

L3=[-1]*8
print(L3)

#
def inc(a):
    a=a+2
    a=a-1

n=10
inc(n)
print(n)
#

def append(a,L):
    L.append(a)

lst=[-46,1,7]
append(23,lst)
print(lst)
#

def modifica_lista(L):
    L.append(-5)

if __name__ == "__main__":
    lst = [-46, 1, 7]
    modifica_lista(lst)
    print(lst)  # Output:  [-46, 1, 7]