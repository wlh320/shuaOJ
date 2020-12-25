from copy import deepcopy
def play(init, stop):
    data = deepcopy(init)
    isize = len(data)
    spoken = {}
    for turn in range(1, stop+1):
        speak = 0
        if turn <= isize:
            speak = data[turn - 1]
            spoken[speak] = turn
        else:
            x = data[-1]
            if x in spoken:
                speak = turn - 1 - spoken[x]
            spoken[x] = turn - 1
            data.append(speak)
    print(data[-1])


init = [0,5,4,1,10,14,7]
play(init, stop=2020)
play(init, stop=3000_0000)
