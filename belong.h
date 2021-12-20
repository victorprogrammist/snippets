
#ifndef __BELONG_H__
#define __BELONG_H__

template <class T1, class T2>
bool belong(const T1 &v, const std::initializer_list<T2> &list) {
    auto itr = std::find(list.begin(), list.end(), v);
    return itr != list.end();
}

template <typename T, typename... Args>
bool belong(const T &v, const Args &... args) {
    return ((v == args) || ...);
}

#endif

