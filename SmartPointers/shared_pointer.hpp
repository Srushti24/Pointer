



template<typename T>
class SharedPointer{

    public:

    //Constructor
    SharedPointer():m_ptr(nullptr), count(new int(1))
    {

    }

    //Paramatized Constructor
     SharedPointer(T *ptr):m_ptr(ptr), count(new int(1))
    {

    }

    //Copy Constructor
    SharedPointer(const SharedPointer& p): m_ptr(p.m_ptr),
    count(p.count)
    {
        (*count)++;
    }

    //Copy assigment operator
    SharedPointer& operator=(const SharedPointer& p )
    {
         if (this != &p) {
            *count = *count> 0 ? *count-1: *count;
            if(*count == 0)
            {
                delete count;
                delete m_ptr;
            }
        m_ptr = p.m_ptr;
        count = p.count;
        (*count)++;
         }
         return *this;
    }


    //Move Constructor
    SharedPointer(SharedPointer&& p): m_ptr(p.m_ptr),
    count(p.count)
    {
         p.m_ptr = nullptr;
         p.count = nullptr;
    }

    //Move Assigment operator
    SharedPointer operator=(SharedPointer&& p)
    {
        if (this != &p) {
            (*count)--;
            if(*count == 0)
            {
                delete count;
                delete m_ptr;
            }
            m_ptr = p.m_ptr;
            count = p.count;
            p.m_ptr = nullptr;
            p.count = nullptr;

        }
        return *this;
    }

    // Destructor 
    ~SharedPointer()
    {
        (*count)--; 
        if(*count == 0 )
        {
            delete m_ptr;
            delete count;
        }
    }
    
    //Dereferencing
     T& operator *()
     {
        return *m_ptr;
     }


     //Pointing
     T* operator->()
     {
        return m_ptr;
     }
 
     //Return use_count
     int  use_count() const{
        return *count;
     }
    
    //calculate unique
     bool unique() const{
        return *count == 1;
     }

     //Reset
     void reset() {
        *count = *count > 0 ? *count -1: *count;
        if(*count == 0)
        {
            delete m_ptr;
            delete count;
        }
        m_ptr = nullptr;
        count = new int(1);
     }

    // Paramatized reset
     void reset(SharedPointer& new_ptr)
     {
        *count = *count > 0 ? *count -1: *count;
        if(*count == 0)
        {
            delete m_ptr;
            delete count;
        }
        m_ptr = new_ptr.m_ptr;
        count = new_ptr.count;
        *count++;
     }

     //release 
     T* release()
     {
        if(m_ptr)
        {
            T* temp_ptr = m_ptr;
            *count = *count > 0 ? *count -1: *count;
            if(*count == 0)
            {
                delete m_ptr;
                delete count;
            }
            m_ptr = nullptr;
            count = new int(1);
          return temp_ptr;  
        }
        return nullptr;

     }

    //Swap two function
     void swap(SharedPointer& other)
     {
        T* temp_ptr = m_ptr;
        T* temp_count = count;
        m_ptr =  other.m_ptr;
        count = other.count;
        other.m_ptr = temp_ptr;
        other.count = temp_count;
     }
    private:
    T* m_ptr;
    int* count;
};

template<typename T, typename... Args>
SharedPointer<T> make_shared(Args&&... args)
{
    return SharedPointer<T>(new T(std::forward<Args>(args) ...));
}