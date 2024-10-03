# Реализовать функцию, которая определяет, являются
# ли две строки изоморфными

def isIsomorph(str1: str, str2: str):
    if len(str1)!=len(str2):
        return False
    else:
        alphabet1 = ''
        len_alphabet1 = 0
        alphabet2 = ''
        for i in range(len(str1)):
            flag = True
            for j in range(len_alphabet1):
                if alphabet1[j]==str1[i]:
                    flag = False
                    if alphabet2[j]!=str2[i]:
                        return False
            if flag:
                alphabet1 += str1[i]
                alphabet2 += str2[i]
                len_alphabet1 += 1
        return True
a = isIsomorph(input(),input())
print(a)