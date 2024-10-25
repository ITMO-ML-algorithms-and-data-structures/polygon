user_input = ''
for i in range(10**4//3+1):
    user_input += '(a)'
with open('dataset.txt', 'w', encoding='utf-8') as file:
    file.write(user_input)
