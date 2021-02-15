#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 3;           //ͣ�����������ɳ�������
typedef pair<int, int> time; //ʱ�� XX:XX
typedef struct
{
    string car_number;
    time reach, leave;
} Car; //��
typedef struct
{
    Car *stack[MAX + 1];
    int top;
} SqStack; //ͣ����
typedef struct car
{
    Car *data;
    struct car *next;
} QueueNode; //���еĽڵ�
typedef struct Node
{
    QueueNode *head;                                     //��ͷָ��
    QueueNode *rear;                                     //��βָ��
} LinkQueue;                                             //���
void InitStack(SqStack *s, int n);                       //��ʼ��ͣ����
int InitQueue(LinkQueue *Q);                             //��ʼ���������
void print(Car *p);                                      //��ӡ�����뿪��Ϣ
void Arrive(SqStack *A, LinkQueue *B, int n);            //��������ͣ����
void Leave(SqStack *A, SqStack *C, LinkQueue *B, int n); //�뿪ͣ����

int main(void)
{
    SqStack Enter, Temp;
    LinkQueue Wait;
    int ch, n;
    n = MAX;
    InitStack(&Enter, n);
    InitStack(&Temp, n);
    InitQueue(&Wait);
    while (1)
    {
        cout << "		ͣ��������ϵͳ		" << endl;
        cout << "    *******************************" << endl;
        cout << "		1.������վ		" << endl;
        cout << "		2.������վ		" << endl;
        cout << "		3.�˳�ϵͳ		" << endl;
        cout << "��ѡ��: 1~3: " << endl;
        cin >> ch;
        if (ch > 3 || ch < 1)
        {
            do
            {
                cout << "��������,����������" << endl;
                cin >> ch;
            } while (ch <= 3 && ch >= 1);
        }
        switch (ch)
        {
        case 1:
            Arrive(&Enter, &Wait, n);
            break;
        case 2:
            Leave(&Enter, &Temp, &Wait, n);
            break;
        case 3:
            exit(0);
        default:
            break;
        }
    }
}
void InitStack(SqStack *s, int n) //��ʼ��ͣ����
{
    int i = 0;
    s->top = 0;
    s->stack[s->top] = NULL;
}
int InitQueue(LinkQueue *Q) //��ʼ���������
{
    Q->head = new QueueNode;
    if (Q->head != NULL)
    {
        Q->head->next = NULL;
        Q->rear = Q->head;
        return 1;
    }
    else
        return 0;
}
void print(Car *p) //��ӡ�����뿪��Ϣ
{
    int A1, A2, B1, B2, t, h, m; //hСʱ m����
    char ch;                     //��������ʱ��� ��
    cout << "�������뿪��ʱ��: " << endl;
    cin >> p->leave.first >> ch >> p->leave.second;
    A1 = p->reach.first, A2 = p->reach.second, B1 = p->leave.first, B2 = p->leave.second;
    t = (B1 - A1) * 60 + B2 - A2;
    if (t >= 60)
    {
        h = t / 60;
        m = t - 60 * h;
    }
    else
    {
        h = 0;
        m = t;
    }
    cout << "		��վ��������Ϣ" << endl;
    cout << "    *******************************" << endl;
    cout << "���ƺ�: " << p->car_number << endl;
    cout << "��ͣ����ʱ��		" << endl;
    cout << p->reach.first << ":" << p->reach.second << endl;
    cout << "��ͣ������ʱ��		" << endl;
    cout << p->leave.first << ":" << p->leave.second << endl;
    cout << "ͣ��ʱ�䣺	" << endl;
    cout << h << "h" << m << "m" << endl;
    cout << "Ӧ������(ÿ����0.1Ԫ):" << endl;
    cout << 0.1 * t << "Ԫ" << endl
         << endl;

    free(p); //�ͷŽڵ�
}
void Arrive(SqStack *A, LinkQueue *B, int n) //��������ͣ����
{
    Car *p;
    QueueNode *t;
    char c;
    p = new Car;
    cout << "�����복�ƺ�(eg:AC666):" << endl;
    cin >> p->car_number;
    if (A->top < n)
    {
        A->top++;
        cout << "�����뵽���ʱ��:" << endl;
        cin >> p->reach.first >> c >> p->reach.second;
        cout << "������ͣ������λ��Ϊ" << A->top << endl
             << endl;
        A->stack[A->top] = p;
    }
    else
    {
        cout << "ͣ�����Ѿ�����,��Ҫ�Ⱥ�" << endl;
        t = new QueueNode;
        t->data = p;
        t->next = NULL;
        B->rear->next = t;
        B->rear = t;
    }
}
void Leave(SqStack *A, SqStack *C, LinkQueue *B, int n) //�뿪ͣ����
{
    int room;   //����Ҫ�뿪λ��
    Car *p, *t; //p����Ҫ�뿪�ĳ�
    QueueNode *q;
    cout << "������Ҫ�뿪�ĳ����ڵ�λ��" << endl;
    cin >> room;
    while (A->top > room) //������һ��ջ��ɳ����õ�
    {
        C->top++;
        C->stack[C->top] = A->stack[A->top];
        A->stack[A->top] = NULL;
        A->top--;
    }
    p = A->stack[A->top];
    A->stack[A->top] = NULL;
    A->top--;
    while (C->top >= 1)
    {
        A->top++;
        A->stack[A->top] = C->stack[C->top];
        C->stack[C->top] = NULL;
        C->top--;
    }
    print(p);
    if ((B->head != B->rear) && A->top < n)
    {
        q = B->head->next;
        t = q->data;
        A->top++;
        cout << "�������������ͣ�������ó��ĳ��ƺ�Ϊ:"
             << t->car_number << endl;
        cout << "�ó�����ͣ������λ��Ϊ:" << A->top << endl;
        B->head->next = q->next;
        if (q == B->rear)
            B->rear = B->head;
        A->stack[A->top] = t;
        free(q);
    }
}
