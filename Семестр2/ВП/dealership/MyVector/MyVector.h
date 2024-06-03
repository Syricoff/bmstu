#ifndef VECTOR
#define VECTOR

#include <format>

template <typename T>
class Vector
{
public:
    template <typename U>
    class Iter
    {
    public:
        friend class Vector;

        Iter(const Iter &iter);

        friend bool operator==(const Iter &iter1, const Iter &iter2)
        {
            return iter1._obj == iter2._obj;
        }

        friend bool operator!=(const Iter &iter1, const Iter &iter2)
        {
            return iter1._obj != iter2._obj;
        }

        Iter &operator++();
        Iter operator++(int);
        Iter &operator--();
        Iter operator--(int);
        friend Iter operator+(const Iter &iter, const int n){
            return Vector<T>::Iter<U>(iter._obj + n);
        }

        friend Iter operator-(const Iter &iter, const int n){
            return Vector<T>::Iter<U>(iter._obj - n);
        }
        Iter &operator+=(const int n);
        Iter &operator-=(const int n);
        U &operator*() const;

    private:
        U *_obj{nullptr};

        Iter(U *obj);
        Iter(const U *obj);
    };

    typedef Iter<T> iterator;
    typedef Iter<const T> constIterator;

    Vector();
    Vector(const Vector &vector);
    ~Vector();

    void pushBack(const T &obj);
    void insert(const T &obj, const int index = 0);
    void popBack();
    void erase(const int index = 0);
    void clear();
    void sort(const bool reverse = 0);

    bool empty() const;
    int size() const;
    int capacity() const;

    T &at(const int index);
    const T &at(const int index) const;

    iterator begin();
    iterator end();
    constIterator begin() const;
    constIterator end() const;

    T &operator[](const int index);

private:
    T *_start{nullptr};
    int _length{0};
    int _capacity{0};

    void init();
    void increaseCapacity();
    void decreaseCapasity();
};

template <typename T>
inline Vector<T>::Vector() { init(); }

template <typename T>
inline Vector<T>::Vector(const Vector &vector) : Vector()
{
    for (int i = 0; i < vector._length; i++)
    {
        pushBack(vector.at(i));
    }
}

template <typename T>
inline Vector<T>::~Vector() { delete[] _start; }

template <typename T>
inline void Vector<T>::pushBack(const T &obj)
{
    if (_length == _capacity)
    {
        increaseCapacity();
    }
    _start[_length++] = obj;
}

template <typename T>
inline void Vector<T>::insert(const T &obj, const int index)
{
    if (_length == _capacity)
    {
        increaseCapacity();
    }
    if (index > _length || index < 0)
    {
        throw std::format("OutOfBoundsException: Vector index out of range ({})", index);
    }
    for (int i = _length; i >= 0; i--)
    {
        if (i == index)
        {
            _start[i] = obj;
            _length++;
            break;
        }
        _start[i] = _start[i - 1];
    }
}

template <typename T>
inline void Vector<T>::popBack()
{
    if (--_length == _capacity / 2 && _capacity > 1)
    {
        decreaseCapasity();
    }
}

template <typename T>
inline void Vector<T>::erase(const int index)
{
    if (index > _length || index < 0)
    {
        throw std::format("OutOfBoundsException: Vector index out of range ({})", index);
    }
    for (int i = index; i < _length; i++)
    {
        _start[i] = _start[i + 1];
    }
    if (--_length == _capacity / 2 && _capacity > 1)
    {
        decreaseCapasity();
    }
}

template <typename T>
inline void Vector<T>::clear()
{
    delete[] _start;
    init();
}

template <typename T>
inline void Vector<T>::sort(const bool reverse)
{
    for (int i = 0; i < _length - 1; i++)
    {
        for (int j = 0; j < _length - 1 - i; j++)
        {
            if (!reverse && _start[j] > _start[j + 1] || reverse && _start[j] < _start[j + 1])
            {
                std::swap(_start[j], _start[j + 1]);
            }
        }
    }
}

template <typename T>
inline bool Vector<T>::empty() const { return _length == 0; }

template <typename T>
inline int Vector<T>::size() const { return _length; }

template <typename T>
inline int Vector<T>::capacity() const { return _capacity; }

template <typename T>
inline T &Vector<T>::at(const int index)
{
    if (index >= _length || index < 0)
    {
        throw std::format("OutOfBoundsException: Vector index out of range ({})", index);
    }
    return _start[index];
}

template <typename T>
inline const T &Vector<T>::at(const int index) const
{
    if (index >= _length || index < 0)
    {
        throw std::format("OutOfBoundsException: Vector index out of range ({})", index);
    }
    return _start[index];
}

template <typename T>
inline Vector<T>::iterator Vector<T>::begin() { return iterator(_start); }

template <typename T>
inline Vector<T>::iterator Vector<T>::end() { return iterator(_start + _length); }

template <typename T>
inline Vector<T>::constIterator Vector<T>::begin() const { return constIterator(_start); }

template <typename T>
inline Vector<T>::constIterator Vector<T>::end() const { return constIterator(_start + _length); }

template <typename T>
inline T &Vector<T>::operator[](const int index) { return _start[index % _length]; }

template <typename T>
inline void Vector<T>::init()
{
    _length = 0;
    _capacity = 2;
    _start = new T[_capacity];
}

template <typename T>
inline void Vector<T>::increaseCapacity()
{
    T *newVector = new T[(_capacity *= 2)];
    for (int index = 0; index < _length; index++)
    {
        newVector[index] = _start[index];
    }
    delete[] _start;
    _start = newVector;
}

template <typename T>
inline void Vector<T>::decreaseCapasity()
{
    if (_capacity <= 1)
    {
        throw std::format("TooSmallCapacityException: Vector capacity less than 1 ({})", _capacity);
    }
    if (_length > _capacity / 2)
    {
        throw std::format("DataLossException: Vector capacity less than length (cap: {}; len: {})", _capacity, _length);
    }
    T *newVector = new T[(_capacity /= 2)];
    for (int index = 0; index < _length; index++)
    {
        newVector[index] = _start[index];
    }
    delete[] _start;
    _start = newVector;
}

template <typename T>
template <typename U>
inline Vector<T>::Iter<U>::Iter(const Iter& iter) : Iter(iter._obj) {}

template <typename T>
template <typename U>
inline Vector<T>::Iter<U> &Vector<T>::Iter<U>::operator++()
{
    ++_obj;
    return *this;
}

template <typename T>
template <typename U>
inline Vector<T>::Iter<U> Vector<T>::Iter<U>::operator++(int) { return iter(_obj++); }

template <typename T>
template <typename U>
inline Vector<T>::Iter<U> &Vector<T>::Iter<U>::operator--()
{
    ++_obj;
    return *this;
}

template <typename T>
template <typename U>
inline Vector<T>::Iter<U> Vector<T>::Iter<U>::operator--(int) { return iter(_obj--); }

template <typename T>
template <typename U>
inline Vector<T>::Iter<U> &Vector<T>::Iter<U>::operator+=(const int n)
{
    _obj += n;
    return *this;
}

template <typename T>
template <typename U>
inline Vector<T>::Iter<U> &Vector<T>::Iter<U>::operator-=(const int n)
{
    _obj -= n;
    return *this;
}

template <typename T>
template <typename U>
inline U &Vector<T>::Iter<U>::operator*() const { return (*_obj); }

template <typename T>
template <typename U>
inline Vector<T>::Iter<U>::Iter(U *obj) : _obj(obj) {}

template <typename T>
template <typename U>
inline Vector<T>::Iter<U>::Iter(const U *obj) : _obj(obj) {}
#endif // !VECTOR