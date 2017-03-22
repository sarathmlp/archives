class Person:
    def __init__(self, name):
        print ('creating object')
        self.name = name
        self.age = 29

    def say_hi(self):
        print ('Name %s, Age %d' % (self.name, self.age))


p = Person('Sarath V.')
p.say_hi()
