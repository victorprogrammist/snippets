#ifndef ISEMPTY_H
#define ISEMPTY_H

#include <QString>

template <class T>
concept HasEmpty = requires (T v) {
    { v.empty() } -> std::convertible_to<bool>;
};

template <HasEmpty T>
inline bool isEmpty(const T &v) {
    return v.empty();
}

template <class T> requires (!HasEmpty<T>)
inline bool isEmpty(const T &v) {
    return v == T();
}

template <>
inline bool isEmpty<QString>(const QString &v) {
    return v.isEmpty();
}

#endif // ISEMPTY_H
