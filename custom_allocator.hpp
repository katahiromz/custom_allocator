#ifndef CUSTOM_ALLCATOR_HPP
#define CUSTOM_ALLCATOR_HPP

#include <cstdlib>  // for malloc and free
#include <memory>   // for std::allocator
#include <iostream> // for std::cout

namespace katahiromz {

template <typename T>
class custom_allocator : public std::allocator<T> {
public:
    typedef typename std::allocator<T>::size_type       size_type;
    typedef typename std::allocator<T>::pointer         pointer;
    typedef typename std::allocator<T>::const_pointer   const_pointer;
    typedef typename std::allocator<T>::reference       reference;
    typedef typename std::allocator<T>::const_reference const_reference;
    typedef typename std::allocator<T>::difference_type difference_type;

    custom_allocator() {}
    custom_allocator(const custom_allocator<T>& x) {}
    template <typename U>
    custom_allocator(const custom_allocator<U>& x) {}
    pointer allocate(size_type count, const_pointer hinst = NULL) {
        size_type size = count * sizeof(T);
        std::cout << "custom_allocator: allocate " << size << std::endl;
        return reinterpret_cast<pointer>(std::malloc(size));
    }
    void deallocate(pointer ptr, size_type count) {
        std::cout << "custom_allocator: free " << ptr << std::endl;
        std::free(ptr);
    }
    template <typename U>
    struct rebind { typedef custom_allocator<U> other; };
};

} // namespace katahiromz

#endif  // ndef CUSTOM_ALLCATOR_HPP
