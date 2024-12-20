#include "../exercise.h"

// TODO: 验证更简单的修改方法，最小化修改内容
constexpr unsigned long long fibonacci(int i) {
    if (i <= 1) return i;
    unsigned long long a = 0, b = 1, c = 0;
    for (int n = 2; n <= i; ++n) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char **argv) {
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // PS: 编译运行，但是不一定能算出结果……
    constexpr auto ANS_N = 90;
    constexpr auto ANS = fibonacci(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
