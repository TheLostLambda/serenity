#pragma once

#include "Weakable.h"

namespace AK {

template<typename T>
class WeakPtr {
    friend class Weakable<T>;
public:
    WeakPtr() { }
    WeakPtr(std::nullptr_t) { }

    template<typename U>
    WeakPtr& operator=(WeakPtr<U>&& other)
    {
        m_link = reinterpret_cast<WeakLink<T>*>(other.leakLink());
        return *this;
    }

    operator bool() const { return ptr(); }

    T* ptr() { return m_link ? m_link->ptr() : nullptr; }
    const T* ptr() const { return m_link ? m_link->ptr() : nullptr; }

    T* operator->() { return ptr(); }
    const T* operator->() const { return ptr(); }

    T& operator*() { return *ptr(); }
    const T& operator*() const { return *ptr(); }

    bool isNull() const { return !m_link || !m_link->ptr(); }
    void clear() { m_link = nullptr; }

    WeakLink<T>* leakLink() { return m_link.leakRef(); }

private:
    WeakPtr(RetainPtr<WeakLink<T>>&& link) : m_link(std::move(link)) { }

    RetainPtr<WeakLink<T>> m_link;
};

template<typename T>
inline WeakPtr<T> Weakable<T>::makeWeakPtr()
{
    if (!m_link)
        m_link = adopt(*new WeakLink<T>(static_cast<T&>(*this)));
    return WeakPtr<T>(m_link.copyRef());
}

}

using AK::WeakPtr;

