#ifndef _SCOPEDPOINTER_H_
#define _SCOPEDPOINTER_H_

template<typename T>
class TCScopedPointer
{
public:
        typedef T elemnet_type;

        TCScopedPointer(T* p = 0)
        {
                m_pPointer = p;
        }

        ~TCScopedPointer()
        {
                delete m_pPointer;
        }

        T& operator*() const
        {
                return *m_pPointer;
        }

        T* operator->() const
        {
                return m_pPointer;
        }

        T* Get() const
        {
                return m_pPointer;
        }

private:
	TCScopedPointer(const TCScopedPointer& source) {}
        TCScopedPointer& operator=(const TCScopedPointer& source) {}

        T* m_pPointer;

};

template<typename T>
class TCScopedArrayPointer
{
public:
        typedef T elemnet_type;

        TCScopedArrayPointer(T* p = 0)
        {
                m_pPointer = p;
        }

        ~TCScopedArrayPointer()
        {
                delete[] m_pPointer;
        }

        T& operator[](unsigned long index) const
        {
                return m_pPointer[index];
        }

        T* Get() const
        {
                return m_pPointer;
        }	
private:

        TCScopedArrayPointer(const TCScopedArrayPointer& source) {}
        TCScopedArrayPointer& operator=(const TCScopedArrayPointer& source) {}

        T* m_pPointer;

};

#endif //_SCOPEDPOINTER_H_

