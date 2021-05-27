
struct CntrObj {

    static uint &cObj() {
        static uint r = 0;
        return r;
    }

    CntrObj() { ++cObj(); }
    CntrObj(const CntrObj &) { ++cObj(); }
    CntrObj(CntrObj &&) { ++cObj(); }
    ~CntrObj() { --cObj(); }
    CntrObj &operator=(const CntrObj &) { return *this; }
    CntrObj &operator=(CntrObj&&) { return *this; }
};
