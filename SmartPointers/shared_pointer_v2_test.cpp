#include "Box.hpp"
#include "shared_pointer_v2.hpp"
#include <cassert>

void testSharedPointerWithContext() {
    SharedPointerV2<int> temp;
    {
        auto temp1 = SharedPointerV2<int>(new int{5});
        temp       = temp1;
    }
    assert(*temp == 5);
}

void testMoveOpt() { // Testing move operator
    SharedPointerV2<int> s1(new int{6});
    assert(s1.get() != nullptr);
    SharedPointerV2<int> s2 = std::move(s1);
    assert(*s2 == 6);
    assert(s1.get() == nullptr);
}

void testCopyAssignOpWithObj() { // Testing copy Assignment operator when an object is passed
    SharedPointerV2<Box> s1(new Box{6});
    auto                 s2 = s1;
    assert(s1->m_len == 6);
    assert(s2.getCount() == 2);
}

void testCopyAssignNoObj() { // Testing copy Assignment when no object is passed
    SharedPointerV2<Box> s1;
    auto                 s2 = s1;
    assert(s1.getCount() == 0);
}

void testCopyCrtNoObj() { // Testing copy constructor when no object is passed
    SharedPointerV2<Box> s1;
    SharedPointerV2<Box> s2(s1);
    assert(s1.getCount() == 0);
}

void testCopyCrtObj() { // Testing copy constructor when object is passed
    SharedPointerV2<Box> s1(new Box(7));
    assert(s1.getCount() == 1);
    SharedPointerV2<Box> s2(s1);
    assert(s2.getCount() == 2);
}

void testMoveCrt() { // Testing move constructor
    SharedPointerV2<Box> s1(new Box(7));
    assert(s1->m_len == 7);
    assert(s1.getCount() == 1);
    SharedPointerV2<Box> s2(std::move(s1));
    assert(s2->m_len == 7);
    assert(s1.get() == nullptr);
    assert(s1.getCount() == 0);
}

void testParamCrtWithObj() { // Testing param constructor with an object passed
    SharedPointerV2<Box> s1(new Box(7));
    assert(s1->m_len == 7);
    assert(s1.getCount() == 1);
}

void testParamCrtWithNullObj() { // Testing param constructor with a null passed
    SharedPointerV2<int> s1(new int{});
    // assert(s1.getCount() == 0);
}
void testMultipleCrt() {
    SharedPointerV2<int> sp(new int{6});
    assert(sp.getCount() == 1);
    assert(*sp == 6);
    auto sp2 = std::move(sp);
    assert(sp.getCount() == 0);
    assert(sp.get() == nullptr);
    assert(*sp2 == 6);
    assert(sp2.getCount() == 1);
    sp = std::move(sp2);
    assert(sp.getCount() == 1);
    assert(sp2.get() == nullptr);
    assert(*sp == 6);
    assert(sp2.getCount() == 0);
    sp2 = sp;
    assert(sp.getCount() == 2);
    assert(sp2.getCount() == 2);
    assert(*sp == 6);
    assert(*sp2 == 6);
    auto sp3 = sp2;
    assert(sp3.getCount() == 3);
}

void testMultipleNullCrt() {
    auto sp = SharedPointerV2<int>();
    assert(sp.get() == nullptr);
    assert(sp.getCount() == 0);
    auto sp2 = sp;
    assert(sp2.get() == nullptr);
    assert(sp2.getCount() == 0);
    auto sp3 = SharedPointerV2<int>({new int(7)});
    sp       = sp3;
    assert(*sp == 7);
    assert(sp.getCount() == 2);
    sp2 = std::move(sp3);
    assert(*sp2 == 7);
    assert(sp2.getCount() == 2);
    assert(sp3.get() == nullptr);
    assert(sp3.getCount() == 0);
}

void testMultipleContextDelete() {
    auto sp1 = SharedPointerV2<int>(new int{6});
    {
        auto sp2 = sp1;
        {
            auto sp3 = std::move(sp2);
            {
                auto sp4 = sp3;
                assert(*sp4 == 6);
                assert(sp4.getCount() == 3);
            }
            assert(sp3.getCount() == 2);
        }
        assert(sp2.getCount() == 0);
    }
    assert(sp1.getCount() == 1);
}

void testChangingObjectValues() {
    struct S {
        S(int a, int b, int c) : a(a), b(b), c(c) {}
        ~S() {}
        int a;
        int b;
        int c;
    };
    SharedPointerV2<S> sp1(new S(2, 3, 4));
    auto               sp2 = sp1;
    sp2->a                 = 6;
    sp2->b                 = 9;
    assert(sp1->a == 6);
    assert(sp1->b == 9);
}

void testSharedPtrWithStruct() {
    int a = 0;
    int b = 0;
    struct S {
        S(int& a, int& b) : a_(a), b_(b) { a_++; }
        ~S() { b_++; }
        int& a_;
        int& b_;
    };
    {
        std::vector<SharedPointerV2<S>> temp;
        for (size_t i = 0; i < 5; i++) {
            SharedPointerV2<S> sTemp(new S(a, b));
            temp.push_back(sTemp);
        }
    }
    assert(a == 5);
    assert(b == 5);
}