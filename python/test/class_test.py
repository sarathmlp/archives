import coin

def main():

    coin1 = coin.Coin()
    print(coin1.getsideup())

    coin1.toss()
    print(coin1.getsideup())

    print(coin1)
    str(coin1)

if __name__ == "__main__":
    main()
