inp = input()
word = inp.split()
word = [w[::-1] for w in word]
print(' '.join(word))
