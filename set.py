'''
To create ADT that implement the set concept.
a. Add (new Element) -Place a value into the set
b. Remove (element) Remove the value
c. Contains (element) Return true if element is in collection
d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection
e.Intersection of two sets
f. Union of two sets
g. Difference between two sets
h. Subset
'''
l=[]

def add(key):
    if key not in l :
        l.append(key)
    else :
        print(f'{key} is already in set')

def remove(key):
    if key in l :
        l.remove(key)
    else :
        print(f'{key} is not found in set')

def avail(key):
    if key in l :
        return True
    else :
        return False

def size():
    return len(l)

def subset() :
    l2=[]
    x=int(input("Enter the No. of elements to enter in second list : "))
    for i in range(0,x):
        l2.append(int(input()))
    counter=0
    for i in l2 :
        if i in l :
            counter+=1
    if counter==len(l2):
        print(f'{l2} is subset of {l}')

def union():
    l2=[]
    x=int(input("Enter the No. of elements to enter in second list : "))
    for i in range(0,x):
        l2.append(int(input()))
    l.append(l2)
    print(f'Union : {l}')

def difference() :
    l2=[]
    x=int(input("Enter the No. of elements to enter in second list : "))
    for i in range(0,x):
        l2.append(int(input()))
    l3=[]
    for i in l :
        if i not in l2 :
            l3.append(i)
    print(f'Difference : {l3}')

def intersection() :
    l4=[]
    l5=[]
    x=int(input("Enter the No. of elements to enter in second list : "))
    for i in range(0,x):
        l4.append(int(input()))
    for i in l :
        if i in l4 :
            l5.append(i)
    print(f'intersection : {l5}')

ch=10
while(ch!=0) :
    ch=int(input("\n1.Add Element\n2.Remove\n3.Contains4.Size\n5.Intersection\n6.Union\n7.Difference\n8.Subset\nEnter your choice : "))
    if ch==1 :
        #key=int(input("Enter the no you want to add : "))
        #add(key)
        for i in range(1,10):
            add(i)
    elif ch==2:
        key=int(input("Enter the no you want to remove : "))
        remove(key)
    elif ch==3:
        key=int(input("Enter the no you want to check : "))
        if avail(key) :
            print("key found !")
        else :
            print("key not found !")
    elif ch==4:
        size()
    elif ch==5:
        intersection()
    elif ch==6:
        union()
    elif ch==7:
        difference()
    elif ch==8:
        subset()

