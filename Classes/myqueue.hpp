#ifndef MYQUEUE_HPP
#define MYQUEUE_HPP

#if __cplusplus >= 20110311L

template<typename _Tp=int>
class myqueue{
private:
    _Tp *q;
    unsigned long long f=0, r=0, ms;

public:
    myqueue(long long size) : ms(size+1) {
        q = new _Tp[ms];
    }
    
    ~myqueue() { delete[] q; }

    bool empty() const { return f == r; }
    bool full() const { return (r+1)%ms == f; }

    int push(const _Tp& x) {
        if(full()) return -1;
        q[r] = x;
        r = (r+1)%ms;
        return 0;
    }

    int pop() {
        if(empty()) return -1;
        f = (f+1)%ms;
        return 0;
    }

    _Tp front() const {
        return empty() ? _Tp(-1) : q[f];
    }

    long long size() const {
        return (r - f + ms) % ms;
    }

    void clear() { f = r = 0; }

    myqueue(const myqueue&) = delete;
    myqueue& operator=(const myqueue&) = delete;
};

#endif // _cplusplus >= 20110311L

#endif // MYQUEUE_H
