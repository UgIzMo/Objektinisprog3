#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <algorithm> // Include for std::swap

template <typename T>
class Vector
{
private:
    T *m_data; // Renamed member variable to avoid conflict
    size_t capacity_;
    size_t length;

public:
    // Member types
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;

    // Constructor
    Vector() : m_data(nullptr), capacity_(0), length(0) {}

    // Destructor
    ~Vector()
    {
        delete[] m_data;
    }

    // Copy constructor
    Vector(const Vector &other) : m_data(nullptr), capacity_(0), length(0)
    {
        *this = other;
    }

    // Copy assignment operator
    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            clear();
            reserve(other.size());
            for (size_t i = 0; i < other.size(); ++i)
            {
                push_back(other.m_data[i]); 
            }
        }
        return *this;
    }

    // Move constructor
    Vector(Vector &&other) noexcept : m_data(nullptr), capacity_(0), length(0)
    {
        *this = std::move(other);
    }

    // Move assignment operator
    Vector &operator=(Vector &&other) noexcept
    {
        if (this != &other)
        {
            clear();
            m_data = other.m_data; 
            capacity_ = other.capacity_;
            length = other.length;
            other.m_data = nullptr; 
            other.capacity_ = 0;
            other.length = 0;
        }
        return *this;
    }

    // Push back an element
    void push_back(const T &value)
    {
        if (length >= capacity_)
        {
            reserve(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        m_data[length++] = value; 
    }

    // Pop back an element
    void pop_back()
    {
        if (length > 0)
        {
            --length;
        }
    }

    // Clear the vector
    void clear()
    {
        length = 0;
    }

    // Reserve capacity for elements
    void reserve(size_t new_capacity)
    {
        if (new_capacity > capacity_)
        {
            T *new_data = new T[new_capacity];
            for (size_t i = 0; i < length; ++i)
            {
                new_data[i] = std::move(m_data[i]); 
            }
            delete[] m_data;
            m_data = new_data; 
            capacity_ = new_capacity;
        }
    }

    // Get the capacity of the vector
    size_t capacity() const
    {
        return capacity_;
    }

    // Resize the vector
    void resize(size_t new_size)
    {
        reserve(new_size);
        length = new_size;
    }

    // Get size of the vector
    size_t size() const
    {
        return length;
    }

    // Check if the vector is empty
    bool empty() const
    {
        return length == 0;
    }

    // Access element at index using []
    T &operator[](size_t index)
    {
        if (index >= length)
            throw std::out_of_range("Index out of range");
        return m_data[index]; 
    }

    // Access element at index using [] (const version)
    const T &operator[](size_t index) const
    {
        if (index >= length)
            throw std::out_of_range("Index out of range");
        return m_data[index]; 
    }

    // Get iterator to the beginning of the vector
    T *begin()
    {
        return m_data; 
    }

    // Get const iterator to the beginning of the vector
    const T *begin() const
    {
        return m_data; 
    }

    // Get iterator to the end of the vector
    T *end()
    {
        return m_data + length; 
    }

    // Get const iterator to the end of the vector
    const T *end() const
    {
        return m_data + length; 
    }

    // Access the first element
    T &front()
    {
        if (length == 0)
            throw std::out_of_range("Vector is empty");
        return m_data[0]; 
    }

    // Access the first element (const version)
    const T &front() const
    {
        if (length == 0)
            throw std::out_of_range("Vector is empty");
        return m_data[0]; 
    }

    // Access the last element
    T &back()
    {
        if (length == 0)
            throw std::out_of_range("Vector is empty");
        return m_data[length - 1]; 
    }

    // Access the last element (const version)
    const T &back() const
    {
        if (length == 0)
            throw std::out_of_range("Vector is empty");
        return m_data[length - 1]; 
    }

    // Direct access to the underlying contiguous storage
    T *data()
    {
        return m_data; 
    }

    // Direct access to the underlying contiguous storage (const version)
    const T *data() const
    {
        return m_data; 
    }

    // Swap the contents of two vectors
    void swap(Vector &other) noexcept
    {
        std::swap(m_data, other.m_data); 
        std::swap(capacity_, other.capacity_);
        std::swap(length, other.length);
    }
};

#endif // VECTOR_H
