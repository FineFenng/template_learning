#pragma once
#include <type_traits>
#include <utility>

template<typename FROM, typename TO>
struct IsConvertibleHelper: {
public:
    using Type = decltype(Test<FROM>(nullptr));

private:
    static void AU(TO);
    template<typename U, typename = decltype(AU(std::declval<U>())>
    static std::true_type Test(void*);

    template<typename>
    static std::false_type Test(...);

};

template<typename FROM, typename TO>
struct IsConvertibleTrait : IsConvertibleHelper<FROM, TO>::Type {
};

