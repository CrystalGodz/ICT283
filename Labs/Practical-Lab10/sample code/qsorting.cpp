#include <iostream>
#include <cstdlib>
#include <climits> // for INT_MIN, INT_MAX

int cmpfunc (const void * a, const void * b)
{
    //int arg1 = *static_cast<const int*>(a);
    //int arg2 = *static_cast<const int*>(b);

    int arg1 = *(int*)(a);  // better approach is the one above
    int arg2 = *(int*)(b);

    if(arg1 < arg2) return -1;

    if(arg1 > arg2) return 1;

    return 0;
}

int main()
{
    int a[] = {INT_MAX, -2, 99, 0, -743, 2, INT_MIN, 4};
    constexpr std::size_t size = sizeof a / sizeof *a;

    std::qsort(a, size, sizeof (a[0]), cmpfunc);

    for(int ai : a)
        std::cout << ai << ' ';
}

/*
// commented out as it uses lambda function.
// need to be able to do the version above before looking at 
// the lambda function approach
// the lambda function is the last parameter of qsort
// the entire comparator function body is buried in the parameter of qsort.
#include <iostream>
#include <cstdlib>
#include <climits>

int main()
{
    int a[] = {-2, 99, 0, -743, 2, INT_MIN, 4};
    constexpr std::size_t size = sizeof a / sizeof *a;

    std::qsort(a, size, sizeof *a, [](const void* a, const void* b)
    {
        int arg1 = *static_cast<const int*>(a);
        int arg2 = *static_cast<const int*>(b);

        if(arg1 < arg2) return -1;
        if(arg1 > arg2) return 1;
        return 0;

    //  return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    //  return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
    }         );

    for(int ai : a)
        std::cout << ai << ' ';
}


*/
