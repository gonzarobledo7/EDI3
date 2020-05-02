class ConsoleObserver : IObserver
{
    public void Update ( SubjectEvent subjectEvent )
    {
        Console.Writeline (" An event just happened!");
        Console.Writeline (" Event Type: " + subjectEvent.EventType );
        Console.Writeline (" Date: " + subjectEvent.EventDate);


    }
}