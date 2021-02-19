
template <class T1, class T2>
int tmplCmp(const T1& v1, const T1& v2) {
    if (v1 < v2) return -1;
    if (v1 == v2) return 0;
    return 1;
}

template <class T>
int tmplCmp(const T& v1, const T& v2) {
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

template <typename T1, typename T2, typename ...Args>
int tmplCmp(const T1 &v1, const T2 &v2, const Args& ...other) {
    int r = tmplCmp(v1, v2);
    if (r) return r;
    return tmplCmp(other...);
}

template <typename ...Args>
bool tmplEq(const Args &...params) {
    return !tmplCmp(params...);
}

template <typename ...Args>
bool tmplLess(const Args &...params) {
    return tmplCmp(params...) < 0;
}
