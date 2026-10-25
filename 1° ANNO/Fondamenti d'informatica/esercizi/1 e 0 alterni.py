num=int(input("inserisci un numero:"))
for i in range(0,num):
    for j in range(0, num):
        if i % 2==0 and j%2==0 or i%2!=0 and j%2!=0:
            print(1,end="")
        else: 
            print(0,end="")
    print()


     

          


