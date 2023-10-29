def Insertion_sort(array):
    for i in range(1,len(array)):
        key = array[i]
        j = i-1
        while(key < array[j] and j >=0):
            array[j+1]=array[j]
            j=j-1
        array[j+1]=key
    return array

array = [4,4,0,12,1,1,1,1,1,40,1000,40,22,42,51,1]
sorted_array = Insertion_sort(array)
for i in range(0,len(array)):
    print(sorted_array[i]," ")
    



