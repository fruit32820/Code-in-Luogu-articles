#ifndef MYSTACK_HPP
#define MYSTACK_HPP

#if __cplusplus >= 20110311L

template<typename _Tp=int>
class mystack{
private:
    _Tp *buf;
    unsigned long long ptr=0, ms;

public:
    mystack(long long size) : ms(size) {
        buf = new _Tp[ms];
    }
    
    ~mystack() { delete[] buf; }

    bool empty() const { return !ptr; }
    bool full() const { return ptr == ms; }

    int push(const _Tp& x) {
        if(full()) return -1;
        buf[ptr++] = x;
        return 0;
    }

    int pop() {
        if(empty()) return -1;
        ptr--;
        return 0;
    }

    _Tp top() const {
        return empty() ? _Tp(-1) : buf[ptr-1];
    }

    long long size() const { return ptr; }
    void clear() { ptr = 0; }

   
    mystack(const mystack&) = delete;
    mystack& operator=(const mystack&) = delete;
};

#endif // _cplusplus >= 20110311L

#endif // MYSTACK_H
