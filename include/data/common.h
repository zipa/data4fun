#ifndef _DM_COMMON_H_
#define _DM_COMMON_H_

#include <iostream>
#include <string>
#include <type_traits>

namespace DataModel
{

template <typename T>
class Point
{
    static_assert(std::is_arithmetic<T>::value, "The type should be numerical.");
public:
    Point() {}
    Point(const Point<T>& obj)
    {
        x_ = obj.x_;
        y_ = obj.y_;
        y_ = obj.z_;
    }
    ~Point() {}
    Point<T>& operator=(const Point<T>& obj)
    {
        x_ = obj.x_;
        y_ = obj.y_;
        y_ = obj.z_;
        return *this;
    }
    Point<T>& operator=(Point<T>&& obj)
    {
        return *this;
    }

    inline T x() { return x_; }
    inline void x(const T& value) { x_ = value; }
    inline T y() { return y_; }
    inline void y(const T& value) { y_ = value; }
    inline T z() { return z_; }
    inline void z(const T& value) { z_ = value; }

private:
    T x_ { 0 };
    T y_ { 0 };
    T z_ { 0 };
};

}

 #endif // _DM_COMMON_H_