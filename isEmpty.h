#ifndef __IS_EMPTY_H__
#define __IS_EMPTY_H__

template <class T>
concept HasEmptyStdStyle = requires (T v) {
    { v.empty() } -> std::convertible_to<bool>;
};

template <HasEmptyStdStyle T>
inline bool isEmpty(const T &v) {
    return v.empty();
}

template <class T>
concept HasEmptyQtStyle = requires (T v) {
    { v.isEmpty() } -> std::convertible_to<bool>;
};

template <HasEmptyQtStyle T> requires (!HasEmptyStdStyle<T>)
inline bool isEmpty(const T& v) {
    return v.isEmpty();
}

template <class T> requires (!HasEmptyStdStyle<T> && !HasEmptyQtStyle<T>)
inline bool isEmpty(const T &v) {
    return v == T();
}

#endif // __IS_EMPTY_H__
