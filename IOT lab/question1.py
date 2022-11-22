#Reading file1 and file2 using w+ (to create new file as well)
source1 = open("file1.txt", "r")
source2 = open("file2.txt", "r")
destination = open("destination.txt", "a+")
destination2 = open("destination2.txt", "a+")
count = 0
#function to reverse the string and sort it in ascending order
def ascending_sortString(str):
    return ''.join(sorted(str))

def reverse_sort(word):
    word = word[::-1]
    word = ascending_sortString(word)
    return word

#writing to destination file
for line in source1:
    for word in line.split():
        if((count % 2) == 0):                           #Even word, gets reversed
            new_word = word[::-1]
            destination2.write(new_word+" ")
        if((count % 2) == 1):                                           #Odd word gets sorted
            new_word = ascending_sortString(word)
            destination2.write(new_word+" ")
        count += 1
    destination2.write("\n")
    count = 0

count = 0

for line in source2:
    for word in line.split():
        if((count % 2) == 0):                           #Odd word, gets reversed
            new_word = word[::-1]
            destination2.write(new_word+" ")
        else:                                           #Even word gets sorted
            new_word = ascending_sortString(word)
            destination2.write(new_word+" ")
        count += 1
    destination2.write("\n")
    count = 0

source1.close()
source2.close()
destination.close()
destination2.close()
