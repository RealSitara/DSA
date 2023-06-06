'''
Consider telephone book database of N clients. Make use of a hash table implementation
to quickly look up client's telephone number. Make use of two collision handling
techniques and compare them using number of comparisons required to find a set of
telephone numbers
'''
list1 = []
list2 = []

for i in range(0, 10):
    list1.append(-1)
for i in range(0, 10):
    list2.append(-1)

linear_comparisons = 0
quadratic_comparisons = 0


def hash1(key):
    return key % 10


def hash2(key):
    for i in range(1, 10):
        ind = (hash1(key) + i * i) % 10
        if list2[ind]!=-1 :
           global quadratic_comparisons
           quadratic_comparisons = quadratic_comparisons+1
        else :
            break
    return ind


def linear_prob():
    global linear_comparisons
    print("\nlinear Probing :  ")
    n = int(input("\nHow many records you want to enter? "))
    for i in range(n):
        key = int(input("\nEnter the key you want to append: "))
        if list1[hash1(key)] == -1:
            list1[hash1(key)] = key
        elif list1[hash1(key)] != -1:
            linear_comparisons += 1
            for i in range(hash1(key), 10):
                if list1[i] == -1:
                    list1[i] = key
                    break
                linear_comparisons += 1


def quadratic_prob():
    global quadratic_comparisons
    print("\nQuadractic Probing :  ")
    n = int(input("\nHow many records you want to enter? "))
    for i in range(n):
        key = int(input("\nEnter the keys you want to append: "))
        if list2[hash1(key)] == -1:
            list2[hash1(key)] = key
        elif list2[hash1(key)] != -1:
            quadratic_comparisons += 1
            list2[hash2(key)]=key
            '''for i in range(hash1(key), 10):
                if list2[i] == -1:
                    list2[i] = key
                    break
                quadratic_comparisons += 1'''



quadratic_prob()
linear_prob()

print("\nLinear Probing:")
print("Number of Comparisons:", linear_comparisons)
print("Final List:", list1)

print("\nQuadratic Probing:")
print("Number of Comparisons:", quadratic_comparisons)
print("Final List:", list2)