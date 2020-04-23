/*********************************CONCRET CLOCK TIMER************************************/

/**
ClockTimer is a concrete subject for storing and maintaining the time of day. It notifies
its observers every second. ClockTimer provides the interface for retrieving individual time
units such as the hour, minute, and second.
**/
#include "Subject.h"
#include "DigitalClock.h"
#include "AnalogCliock.h"


class ClockTimer
{
    public:
        ClockTimer()
        {
            m_hours = 0;
            m_minutes = 0;
            m_seconds = 0;
            m_subject = new Subject();
        }

        ~ClockTimer()
        {
            cout << "Destroy Subject!" << endl;
            delete m_subject;
        }

        int GetHour( void )
        {
            return this->m_hours;
        }

        int GetMinute( void )
        {
            return this->m_minutes;
        }

        int GetSecond( void )
        {
            return this->m_seconds;
        }

        Subject* getSubject() 
        {
            return m_subject;
        }

        void Tick ()
        {
         // No update internal time-keeping state, only a demo.
         // ...
             m_seconds++;
            if(m_seconds == 60)
            {
                m_seconds = 0;
                m_minutes++;
                if(m_minutes == 60)
                {
                    m_seconds = 0;
                    m_minutes = 0;
                    m_hours++;
                    if(m_hours == 24)
                    {
                        m_seconds = 0;
                        m_minutes = 0;
                        m_hours = 0;
                    }
                }
            }
            m_subject->Notify();
        }

    private:
        int m_hours;
        int m_minutes;
        int m_seconds;
        Subject* m_subject;
};
