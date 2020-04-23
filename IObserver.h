/**********************************OBSERVER INTERFACE************************************/
/**An abstract class defines the Observer interface:**/


class IObserver
{
    public:
        virtual ~Observer(){};
        virtual void Update() = 0;

}