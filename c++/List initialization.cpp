List Initialization���б��ʼ����

1. Before C++ 11(C++ 11��׼֮ǰ�ĳ�ʼ������)

int x = 0;

int y(2);

char c('a');

int arr[] = {1, 2, 3};

char s[] = "Hello";

C++11 also support the old ways (C++11��׼��Ȼ֧�־ɵĳ�ʼ������)
 

2.     List Initialization (�б��ʼ��)
 

2.1.       List initialization is a new feature for C++11 (�б��ʼ����C++11��һ��������)
 

2.2.       List: braced-init-list (���б����û�������������һ(Щ)ֵ)
 

2.3.       �б��ʼ������������
1. Direct list initialization (ֱ���б��ʼ��)
2. Copy list initialization (�����б��ʼ��)
 

//ֱ���б��ʼ��)

/* Variable initialization */ 

int x{}; // x is 0;

int y{1}; // y is 1;

/* Array initialization */

int array1[]{1, 2, 3};

char s1[3]{'o', 'k'};

char s3[]{"Hello"};

//�����б��ʼ��

/* Variable initialization */

int z = {2};

/* Array initialization */

int array2[] = {4, 5, 6};

char s2[] = {'y', 'e', 's'};

char s4[] = {"World"};

char s5[] = "Aloha"; // Omit curly braces (ʡ�Ի�����)

3. When do we use list initialization(��ʱʹ���б��ʼ��)

        3.1. List initialization is also called "unified initialization"(�б��ʼ��Ҳ����Ϊ��ͳһ��ʼ��������)
            Variables and arrays are initialized in the same form(������������ͬ������ʽ��ʼ��)

                3.2. There are still some argues about when to use list
    - init(Ŀǰ���ں�ʱʹ���б��ʼ����Ȼ��һЩ����)
          https : //stackoverflow.com/questions/18222926/why-is-list-initialization-using-curly-braces-better-than-the-alternatives

                  3.3. A point of view(һ�ֹ۵�)

                      Prefer
{
}
initialization over alternatives unless you have a strong reason not to������ʹ���б��ʼ�����������и��ܺõĲ����������ɣ�

    Why : List initialization does not allow narrowing��ԭ���б��ʼ��������խ��������������ʧ���ݾ��ȵ���ʽ����ת����

�б��ʼ����һ�������˵����������ʹ��{}��ʱ��ʵ���Ͼ�����ʹ���б��ʼ���Ĺ��ܣ�ʵ���ϵ�������ʹ�û����ŵ�ʱ�򣬴�ʱ�������Ὣ��Щ���ݴ�����һ����ʱ����initializer_list��һ�����ͣ���������˵����������ʼ���б������initializer_list��

Ҳ�������ֺ����裬������ʵ������ƽ����ʹ���о����漰����������������룺������ʹ��printf��ʱ�򣬴��ݵı�������������ʼ��һֻ����͸�������������ʽ�����ĸ����Ĳ�ȷ���ԣ�������룺initializer_list���������⣨��Ȼinitializer_list�����ò�ֹ��ˣ���ҿ��Կ�һ��������ӣ�

//initializer_list�����ã�Ϊ������ݲ���������Ψһ��ͨ��initailizer_list������ʱ���󣬽�����ֵ���ݸ�����
#include void print(std::initializer_list list) {                     
    for (auto it = list.begin(); it != list.end(); it++) {
        std::cout << *it << " "; 
    }
    std::cout << std::endl;
}
 
int main() {
    print({ 1, 2, });
}