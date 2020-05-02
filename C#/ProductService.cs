class ProductService : ISubject
{
    private readonly IList observers;
    public ProductService() {
       observers = new List();
    }
    public void Subscribe(IObserver observer) {
        observers.Add(observer);
    }
 
    public void Unsubscribe(IObserver observer) {
        observers.Remove(observer);
    } 
    
    public void AddProduct(string productName) {
        //Business logic to validate and add a product.
        var subjectEvent = new SubjectEvent { 
            EventType = "ProductAdded",
            EventDate = DateTime.Now
        };
        NotifyObservers(subjectEvent);
    }
    public void NotifyObservers(SubjectEvent subjectEvent) {
        Console.WriteLine("Before notifying observers");
        foreach(IObserver observer in observers) {
            observer.Update(subjectEvent);
        }
        Console.WriteLine("After notifying observers");
     }
 }