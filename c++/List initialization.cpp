List Initialization（列表初始化）

1. Before C++ 11(C++ 11标准之前的初始化方法)

int x = 0;

int y(2);

char c('a');

int arr[] = {1, 2, 3};

char s[] = "Hello";

C++11 also support the old ways (C++11标准仍然支持旧的初始化方法)
 

2.     List Initialization (列表初始化)
 

2.1.       List initialization is a new feature for C++11 (列表初始化是C++11的一个新特性)
 

2.2.       List: braced-init-list (“列表”是用花括号括起来的一(些)值)
 

2.3.       列表初始化的两个分类
1. Direct list initialization (直接列表初始化)
2. Copy list initialization (拷贝列表初始化)
 

//直接列表初始化)

/* Variable initialization */ 

int x{}; // x is 0;

int y{1}; // y is 1;

/* Array initialization */

int array1[]{1, 2, 3};

char s1[3]{'o', 'k'};

char s3[]{"Hello"};

//拷贝列表初始化

/* Variable initialization */

int z = {2};

/* Array initialization */

int array2[] = {4, 5, 6};

char s2[] = {'y', 'e', 's'};

char s4[] = {"World"};

char s5[] = "Aloha"; // Omit curly braces (省略花括号)

3. When do we use list initialization(何时使用列表初始化)

        3.1. List initialization is also called "unified initialization"(列表初始化也被称为“统一初始化方法”)
            Variables and arrays are initialized in the same form(变量和数组用同样的形式初始化)

                3.2. There are still some argues about when to use list
    - init(目前对于何时使用列表初始化仍然有一些争论)
          https : //stackoverflow.com/questions/18222926/why-is-list-initialization-using-curly-braces-better-than-the-alternatives

                  3.3. A point of view(一种观点)

                      Prefer
{
}
initialization over alternatives unless you have a strong reason not to（尽量使用列表初始化，除非你有个很好的不用它的理由）

    Why : List initialization does not allow narrowing（原因：列表初始化不允许“窄化”，即不允许丢失数据精度的隐式类型转换）

列表初始化是一个形象的说法，当我们使用{}的时候，实际上就是在使用列表初始化的功能，实际上当我们在使用花括号的时候，此时编译器会将这些内容传化成一个临时对象，initializer_list是一个类型，就向大家所说的那样，初始化列表会编译成initializer_list；

也许看着名字很生疏，但是其实在我们平常的使用中就曾涉及这个东西，请大家想想：在我们使用printf的时候，传递的变量参数不可能始终一只，这就给函数带来了形式参数的个数的不确定性，因此引入：initializer_list解决这个问题（当然initializer_list的作用不止如此）大家可以看一下这个例子：

//initializer_list的作用：为解决传递参数数量不唯一，通过initailizer_list创建临时对象，将参数值传递给函数
#include void print(std::initializer_list list) {                     
    for (auto it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " "; 
    }
    std::cout << std::endl;
}
 
int main() {
    print({ 1, 2, });
}