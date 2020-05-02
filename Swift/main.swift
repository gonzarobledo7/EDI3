/**

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*/
protocol Observer {
    var id : Int { get } // property to get an id
    func update<T>(with newValue: T)
}

protocol Observable {
    associatedtype T
    var value : T { get set }
    var observers : [Observer] { get set }
    
    func addObserver(observer: Observer)
    func removeObserver(observer: Observer)
    func notifyAllObservers<T>(with newValue: T)
}

class Variable<T> : Observable {
    
    private var _value : T! = nil
    private var _observers : [Observer] = []
    
    var value : T {
        get {
            return self._value
        }
        set {
            self._value = newValue
            self.notifyAllObservers(with: newValue)
        }
    }
    
    var observers : [Observer] {
        get {
            return self._observers
        }
        set {
            self._observers = newValue
        }
    }
    
    func addObserver(observer: Observer) {
        observers.append(observer)
    }
    
    func removeObserver(observer: Observer) {
        observers = observers.filter({$0.id != observer.id})
    }
    
    func notifyAllObservers<T>(with newValue: T) {
        for observer in observers {
            observer.update(with: newValue)
        }
    }
}

class MyObserver : Observer {
    
    private var _id : Int = 0
    
    var id: Int {
        get {
            return self._id
        }
    }
    
    init(id: Int) {
        self._id = id
    }
    
    func update<T>(with newValue: T) {
        print("Whoaa, observer #\(self.id) updated with new value : ", newValue)
    }
}

var obs1 = MyObserver(id: 1)
var obs2 = MyObserver(id: 2)
var obsv = Variable<String>()
obsv.addObserver(observer: obs1)
obsv.addObserver(observer: obs2)
obsv.value = "Hello world"
obsv.removeObserver(observer: obs1)
obsv.value = "Obs1 removed, yey"