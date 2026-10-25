def num_primi(num):
  if num<=1:
    return False
  for i in range(2,int(num**0.5)+1):
    if num%i==0:
      return False
  return True

"""""
def filter_prime(lst):
  newlist=[]
  for num in lst:
    if num_primi(num):
      newlist.append(num)
  return newlist
"""

def filter_prime(lst):
    return [num for num in lst if num_primi(num)]

stringa=int(input("quanti numeri vuoi inserire:"))
mia_lista=[]
for i in range(stringa):
  num2=int(input("Inserisci numero:"))
  mia_lista.append(num2)
  
print(filter_prime(mia_lista))


#scrivere un filds_couple(target,lst)
def find_couples(lst, target):
  output = []
  for num1 in lst:
    for num2 in lst:
       if num1 != num2 and num1 + num2 == target and (num1, num2) not in output and (num2, num1) not in output:
         output.append((num1, num2))
  return output

stringa=int(input("quanti numeri vuoi inserire:"))
mia_lista=[]
for i in range(stringa):
  num1=int(input("Inserisci numero:"))
  mia_lista.append(num1)
num3=int(input("inserisci target:"))

print(find_couples(mia_lista, num3))

""""
#esercizio 3
def substitue(lst, sublst, new_sublist):
   lista_finale=[]
   avanti=0
   for num1 in range(len(lst)):
     if avanti>0:  #serve per saltare gli elementi di una lista che fanno gia parte di una sottolista sosituita
       avanti-=1   #se AVANTI è maggiore di 0 significa che devo saltare questo elemento
       continue    
     if lst[num1:num1+len(sublst)] == sublst:
       lista_finale.extend(new_sublist)
       avanti=len(sublst)-1
     else:
         lista_finale.append(lst[num1])
   return lista_finale
       
print(substitue([1, 2, 3, 4,9, 2, 3, 5], [2, 3], [9, 3, 9]))   
"""

def substitute(lst, sublst, new_sublst):
    i = 0
    new_list = []
    while i < len(lst):
        if lst[i:i+len(sublst)] == sublst:
            new_list.extend(new_sublst)
            i += len(sublst)
        else:
            new_list.append(lst[i])
            i += 1    
    return new_list

print(substitute([1, 2, 3, 4, 2, 3, 5], [2, 3], [9, 3, 9]))


def max_sum_non_adjacent(lst):
   if len(lst)<5:
      return None
   Max_somma=0
   for i in range(len(lst)):
      for j in range(i+2,len(lst)):
         for z in range(j+2,len(lst)):
          if lst[i]+lst[j]+lst[z]>Max_somma:
            Max_somma=lst[i]+lst[j]+lst[z]
   return Max_somma
print(max_sum_non_adjacent([1, 8, 3, 10, 6]))
                     
         
      
      
   




num = 0
is_prime = False
new_lst = []
def filtra(lst):
    for i in range(len(lst)):
        num = lst[i]
        prime(num)
        if is_prime == True:
            if lst[i - 1] % 2 == 0 and lst[i + 1] % 2 == 1:
                new_lst.append(lst[i])
    return filtra(new_lst)
        
def prime(num):
    if num < 2:
        is_prime == False
    for i in range(2,num):
        if num % i == 0:
            is_prime == True
    return is_prime