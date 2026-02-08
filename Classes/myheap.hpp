#ifndef MYHEAP_HPP
#define MYHEAP_HPP

#if __cplusplus >= 201103L

#include<algorithm>
#include<stdexcept>

template<typename T=int, typename Compare=std::greater<T> >
class myheap{
private:
    unsigned long long ms;
    T *p;
    unsigned long long len;
    Compare comp;

    void fix(int pos) {
        while(pos > 1 && comp(p[pos], p[pos>>1])){
            swap(p[pos], p[pos>>1]);
            pos >>= 1;
        }
    }

    void repair(int pos) {
        int l = pos << 1, r = l + 1, t = pos;
        while(l <= len) {
            if(comp(p[l], p[t])) t = l;
            if(r <= len && comp(p[r], p[t])) t = r;
            if(t != pos) {
                swap(p[pos], p[t]);
                pos = t;
                l = pos << 1;
                r = l + 1;
            } else break;
        }
    }

    bool valid(unsigned long long pos) const {
        return pos >= 1 && pos <= len;
    }

public:
    myheap(unsigned long long size_max) : ms(size_max), len(0) {
        if(!size_max) throw std::invalid_argument("Max size can not be 0.");
        p = new T[ms + 1];
    }

    ~myheap() { delete[] p; }

    myheap(const myheap&) = delete;
    myheap& operator=(const myheap&) = delete;

    T get(unsigned long long pos) const {
        if(!valid(pos)) throw std::out_of_range("Access location does not exist.");
        return p[pos];
    }

    void modify(unsigned long long pos, const T& x) {
        if(!valid(pos)) throw std::out_of_range("Modify location does not exist.");
        p[pos] = x;
        fix(pos);
        repair(pos);
    }

    void erase(unsigned long long pos) {
        if(!valid(pos)) throw std::out_of_range("Delete location does not exist.");
        if(pos == len) { len--; return; }
        p[pos] = p[len--];
        fix(pos);
        repair(pos);
    }

    void push(const T& val) {
        if(len >= ms) throw std::overflow_error("Heap is full, cannot insert.");
        p[++len] = val;
        fix(len);
    }

    T top() const {
        if(!len) throw std::underflow_error("Heap is empty, no top.");
        return p[1];
    }

    void pop_top() {
        if(!len) throw std::underflow_error("Heap is empty, cannot delete.");
        p[1] = p[len--];
        repair(1);
    }

    bool full() const { return len >= ms; }
    bool empty() const { return !len; }
    unsigned long long size() const { return len; }
    void clear() { len = 0; }
};

#endif // __cplusplus >= 201103L

#endif // MYHEAP_HPP

