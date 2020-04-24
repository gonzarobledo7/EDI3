#include "Subject.h"
#include "IObserver.h"

class Notifier
{
public:
		
	void Notify ()
        {
            list<Observer*>::iterator it;
            for (it = m_observers.begin() ; it != m_observers.end(); ++it)
            {
                (*it)->Update();
            }
        }
	
	Notifier();
	~Notifier();
	
};