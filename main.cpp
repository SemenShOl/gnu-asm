#include <iostream>
#include <stdio.h>
#include <bitset>
#include <iomanip>

void show_pointer(void *p)
{
    char *p1 = reinterpret_cast<char *>(p);
    unsigned short *p2 = reinterpret_cast<unsigned short *>(p);
    double *p3 = reinterpret_cast<double *>(p);

    std::cout << "pointers:" << std::endl;
    std::cout << "p1 = " << p << "\np2 = " << p2 << "\np3 = " << p3 << std::endl;
    std::cout << std::endl;

    std::cout << "offset pointers:" << std::endl;
    std::cout << "(p1 + 1) = " << reinterpret_cast<void *>(p1 + 1) << "\n(p2 + 1) = " << (p2 + 1) << "\n(p3 + 1) = " << (p3 + 1) << std::endl;
    std::cout << std::endl;
}

void print_pointer(void *p)
{
    // std::cout << *p << std::endl;
    // Нельзя вывести *p, т. к. указатель не типизирован
    char *p1 = reinterpret_cast<char *>(p);
    unsigned short *p2 = reinterpret_cast<unsigned short *>(p);
    double *p3 = reinterpret_cast<double *>(p);

    std::cout << std::hex << "\n*p1 = " << int((unsigned char)*p1) << "\n*p2 = " << *p2 << "\n*p3 = " << *p3 << std::endl;
}

void print_dump(void *p, size_t N)
{
    unsigned char *uc_ptr = reinterpret_cast<unsigned char *>(p);

    for (size_t i = 0; i < N; i++)
        std::cout << std::hex << static_cast<unsigned>(*(uc_ptr + i)) << " ";
    std::cout << std::endl;
}

void print16(void *p)
{
    unsigned short *us_ptr = reinterpret_cast<unsigned short *>(p);
    short *s_ptr = reinterpret_cast<short *>(p);

    std::cout << "unsigned short: " << std::endl;
    std::cout << "hex: " << std::hex << *us_ptr << std::endl;      // hex
    std::cout << "bin: " << std::bitset<16>(*us_ptr) << std::endl; // bin
    std::cout << "dec: " << std::dec << *us_ptr << std::endl;      // dec
    std::cout << std::endl;

    std::cout << "singned short: " << std::endl;
    std::cout << "hex: " << std::hex << *s_ptr << std::endl;      // hex
    std::cout << "bin: " << std::bitset<16>(*s_ptr) << std::endl; // bin
    std::cout << "dec: " << std::dec << *s_ptr << std::endl;      // dec
    std::cout << std::endl;
}

void print32(void *p)
{
    unsigned int *us_ptr = reinterpret_cast<unsigned int *>(p);
    int *s_ptr = reinterpret_cast<int *>(p);
    float *f_ptr = reinterpret_cast<float *>(p);

    std::cout << "unsigned int: " << std::endl;
    std::cout << "hex: " << std::hex << *us_ptr << std::endl;      // hex
    std::cout << "bin: " << std::bitset<32>(*us_ptr) << std::endl; // bin
    std::cout << "dec: " << std::dec << *us_ptr << std::endl
              << std::endl; // dec

    std::cout << "signed int: " << std::endl;
    std::cout << "hex: " << std::hex << *s_ptr << std::endl;      // hex
    std::cout << "bin: " << std::bitset<32>(*s_ptr) << std::endl; // bin
    std::cout << "dec: " << std::dec << *s_ptr << std::endl
              << std::endl; // dec

    std::cout << "float: " << std::endl;
    std::cout << std::fixed << std::setprecision(2) << *f_ptr << std::endl;
    std::cout << std::scientific << *f_ptr << std::endl
              << std::endl;
}

void print64(void *p)
{
    unsigned long *ul_ptr = reinterpret_cast<unsigned long *>(p);
    long *l_ptr = reinterpret_cast<long *>(p);
    double *d_ptr = reinterpret_cast<double *>(p);

    std::cout << "Unsigned long: " << std::endl;
    std::cout << "hex: " << std::hex << *ul_ptr << std::endl;      // hex
    std::cout << "bin: " << std::bitset<64>(*ul_ptr) << std::endl; // bin
    std::cout << "dec: " << std::dec << *ul_ptr << std::endl
              << std::endl; // dec

    std::cout << "Signed Long: " << std::endl;
    std::cout << "hex: " << std::hex << *l_ptr << std::endl;      // hex
    std::cout << "bin: " << std::bitset<64>(*l_ptr) << std::endl; // bin
    std::cout << "dec: " << std::dec << *l_ptr << std::endl
              << std::endl; // dec

    std::cout << "Double: " << std::endl;
    std::cout << std::fixed << std::setprecision(2) << *d_ptr << std::endl;
    std::cout << std::scientific << *d_ptr << std::endl
              << std::endl;
}

int main()
{

    int x = 5;
    int y = -5;
    int z = 0xFF007100;

    // Task 1
    //--------------------------------------------------------------------------------------------------------------------
    std::cout << "Task 1" << std::endl;
    int value = 0;
    show_pointer(&value);
    std::cout << "-------------------------------------------------------------------";
    std::cout << std::endl;
    //--------------------------------------------------------------------------------------------------------------------

    // Task 2
    //--------------------------------------------------------------------------------------------------------------------
    std::cout << "Task 2" << std::endl;

    long long first = 0x1122334455667788;
    char second[] = "0123456789abcdef";

    print_pointer(&first);
    print_pointer(&second);
    std::cout << "-------------------------------------------------------------------";
    std::cout << std::endl;
    //--------------------------------------------------------------------------------------------------------------------

    // Task 3
    //--------------------------------------------------------------------------------------------------------------------
    std::cout << "Task 3" << std::endl;

    int *arr = new int[3];
    arr[0] = x;
    arr[1] = y;
    arr[2] = z;

    print_dump(&x, sizeof(5));
    print_dump(arr, sizeof(int) * 3);
    print_dump(&y, sizeof(-5));

    delete[] arr;
    std::cout << "-------------------------------------------------------------------";
    std::cout << std::endl;

    //--------------------------------------------------------------------------------------------------------------------

    // Task 4
    //--------------------------------------------------------------------------------------------------------------------
    std::cout << "Task 4" << std::endl;

    value = 65535;
    print16(&value);
    std::cout << "-------------------------------------------------------------------";

    std::cout << std::endl;

    //--------------------------------------------------------------------------------------------------------------------

    // Task 5
    //--------------------------------------------------------------------------------------------------------------------
    std::cout << "Task 5" << std::endl;

    print32(&x);
    print32(&y);
    print32(&z);
    std::cout << "-------------------------------------------------------------------";

    std::cout << std::endl;

    //--------------------------------------------------------------------------------------------------------------------

    // Task 6
    //--------------------------------------------------------------------------------------------------------------------
    std::cout << "Task 6" << std::endl;

    print64(&x);
    print64(&y);
    print64(&z);
    std::cout << "-------------------------------------------------------------------";

    std::cout << std::endl;

    //--------------------------------------------------------------------------------------------------------------------

    return 0;
}