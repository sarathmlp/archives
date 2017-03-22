import random

class Coin:

    def __init__(self):
        self.__sideup = 'Heads'

    def toss(self):
        if (random.randint(0,1)) == 1:
            self.__sideup = 'Heads'
        else:
            self.__sideup = 'Tail'

    def getsideup(self):
        return self.__sideup

    def __str__(self):
        return self.__sideup

def main():

    coin = Coin()
    print(coin.getsideup())

    coin.toss()
    print(coin.getsideup())

    print(coin)
    str(coin)

if __name__ == "__main__":
    main()
