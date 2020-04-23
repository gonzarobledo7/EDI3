/*********************************SUBJECT ABSTRACT CLASS**********************************/
/**Similarly, an abstract class defines the Subject interface:**/
#include "IObserver.h"

class Subject
{
    public:
        Subject(){};
        virtual ~Subject(){}
        void Attach (Observer* o)
        {
            m_observers.push_front(o);
        }
        void Detach (Observer* o)
        {
            m_observers.remove(o);
        }
        void Notify ()
        {
            list<Observer*>::iterator it;
            for (it = m_observers.begin() ; it != m_observers.end(); ++it)
            {
                (*it)->Update();
            }
        }

    private:
        list<Observer*> m_observers;
};