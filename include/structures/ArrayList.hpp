// Copyright [2016] <Filipe Borba>

#ifndef ARRAYlIST_HPP_
#define ARRAYLIST_HPP_


template<typename T>
class ArrayList {
 public:
     ArrayList()
         : data_{new T[kDefaultSize]}, size_{kDefaultSize}, last_{-1}
     {}

    explicit ArrayList(int size) : data_{new T[size]}, size_{size} {}

    void pushFront(const T& value) { insert(value, 0); }

	T popFront() { return erase(0); }

	void pushBack(const T& value) { insert(last_ + 1, value); }
    
	T popBack() { return erase(last_); }

	void insert(int position, const T& value) {
        if (full()) {
            throw Full{};
        }
        if (position < 0 || last_ + 1 < position) {
            throw OutOfRange{};
        }
        ++last_;
        for (int i = last_; i > position; --i) {
            data_[i] = data_[i-1];
        }
        data_[position] = value;
    }

	void insert(const T& value) {
        if (full()) {
            throw Full{};
        }
        int pos = 0;
        while (pos <= last_ && value > data_[pos]) {
            ++pos;
        }
        insert(pos, value);
    }

	T erase(int position) {
        if (empty()) {
            throw Empty{};
        }
        if (position < 0 || last_ + 1 < position) {
            throw OutOfRange{};
        }
        T value = data_[position];
        --last_;
        for (int i = position; i <= last_; ++i) {
            data_[i] = data_[i+1];
        }
        return value;
    }

	void clear() { last_ = -1;}

    T at(int position) const {
        if (position < 0 || size_ <= position) {
            throw OutOfRange{};
        }
        return data_[position];
    }

	int position(const T& value) const {
        for (int i = 0; i <= last_; ++i) {
            if (data_[i] == value) {
                return i;
            }
        }
        throw OutOfRange{};
    }

    int size() { return size_; }

    bool empty() const { return last_ == -1; }

	bool full() const { return last_ == size_ - 1; }

    class Empty {};
    class Full {};
    class OutOfRange {};

 protected:
    enum { kDefaultSize = 100 };

 private:
    T* data_;
    const int size_;
    int last_;
};

#endif
