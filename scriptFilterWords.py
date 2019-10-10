n = 0
n12 = 0
wordlist = []

with open('sr_Latn.dic', 'r') as f:
    for word in f:
	n = n+1
        if len(word) < 13:
            n12 = n12+1
            word = word[:-1]
            word = word.lower()
            wordlist.append(word)

del(wordlist[0])
with open('sr_Latn.game.dic', 'w') as f:
    f.write(str(len(wordlist)))
    for word in wordlist:
        f.write("\n")
        f.write(word)
