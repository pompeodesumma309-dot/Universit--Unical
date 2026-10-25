lst=[1,2,3]
for elem in lst:
    elem=elem+1
print(lst)

#Esempio: split_list([1, 2, 3, 4, 5, 6, 7], 3) restituisce [[1, 2, 3], [4, 5, 6], [7]].
def split_list(lst,n):
    newlist=[]
    for i in range(0,len(lst),n):
        newlist.append(lst[i:i+n])
    return newlist

lst=[1,2,3,4,5,6,7,8,9,10]
n=int(input("inserisci un numero:"))
result=split_list(lst,n)
print(result)

#find_most_frequent([1, 2, 2, 3, 1, 2, 3, 2, 3, 3]) restituisce 2.
def find_most_frequent(lst):
    max = 0
    result = None
    for elem in lst:
        count = lst.count(elem)
        if count > max:
            max = count
            result = elem
    return result


print(find_most_frequent([2,3,3,3,2,2,3]))



  



            

            