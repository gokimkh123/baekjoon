import math
import sys

while True:
    password = input()
    ans = ''
    if password == 'end': break

    a = set('aeiou')
    b = set('bcdfghjklmnpqrstvxz')
    if not any((i in a) for i in password):
        ans = ' not'

    for i in range(0, len(password) - 2):
        if password[i] in a  and password[i + 1] in a and password[i + 2] in a:
            ans = ' not'
            break
        elif password[i] in b  and password[i + 1] in b and password[i + 2] in b:
            ans = ' not'
            break

    for i in range(0, len(password) - 1):
        if password[i] == password[i + 1]:
            if (password[i] == 'e' and password[i + 1] == 'e') or (password[i] == 'o' and password[i + 1] == 'o'):
                continue
            ans = ' not'
            break

    print('<' + password + '> ' + 'is' + ans + ' acceptable.')
