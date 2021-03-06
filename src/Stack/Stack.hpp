#ifndef _STACK_DEF_H_
#define _STACK_DEF_H_
#include <stdio.h>
#include <string.h>
#include <exception>
#include <stdexcept>

class StackEmptyException: public std::exception {
    virtual const char* what() const throw () {
        return "Pop called on empty stack";
    }

};

template<class s_Type>
class Stack {
  private:
    s_Type* data_;
    size_t current_;
    size_t max_;

    static const int cDefaultSize = 64;
    static const int cExpandChunkSize = 64;

    void expand() {

        s_Type* newData = new s_Type[max_ + cExpandChunkSize];

        for (unsigned int i = 0; i < max_; ++i) {
            newData[i] = data_[i];
        }

        delete[] data_;

        data_ = newData;
        max_ = max_ + cExpandChunkSize;
    }

  public:

    Stack() {

        data_ = new s_Type[cDefaultSize];
        current_ = 0;
        max_ = cDefaultSize;
    }

    ~Stack() {

        if (data_ != nullptr) {
            delete[] data_;
            current_ = 0;
            max_ = 0;
        }

    }

    void push(s_Type a) {

        if (current_ >= max_) {
            expand();
        }

        data_[current_] = a;
        current_++;
    }

    s_Type pop() {

        if (current_ == 0) {
            throw StackEmptyException();
        }

        current_--;
        return data_[current_];
    }

    s_Type get(unsigned int i) const {
        return data_[i];
    }

    size_t size() const {
        return current_;
    }

    void reset() {
        current_ = 0;
    }
};

#endif //_STACK_DEF_H_
