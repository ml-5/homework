/**
这里限定的简单表达式求值问题是：用户输入一个包含“+”、
“-”、“*”、“/”、正整数和圆括号的合法算术表达式，计算该表
达式的运算结果。
例如，exp=“1+2*(4+12)” 中缀表达式

中缀表达式的运算规则：“先乘除，后加减，从左到右计算，先
括号内，后括号外”。
因此，中缀表达式不仅要依赖运算符优先级，而且还要处理括号。

算术表达式的另一种形式是后缀表达式或逆波兰表达式，
就是在算术表达式中，运算符在操作数的后面。
如1+2*3的后缀表达式为1 2 3 * +。
后缀表达式：
已考虑了运算符的优先级。没有括号。只有操作数和运算符，而且越放在前面的运算符来越优先执行。

中缀表达式的求值过程：
将中缀算术表达式转换成后缀表达式。
对该后缀表达式求值。
思路:
while (从exp读取字符ch，ch!='\0')
{ ch为数字：将后续的所有数字均依次存放到postexp中，
  并以字符'#'标志数值串结束;
   ch为左括号'('：将此括号进栈到Optr中;
    ch为右括号')'：将Optr中出栈时遇到的第一个左括号'('以前的运算符依次出
    栈并存放到postexp中，然后将左括号'('出栈;
    ch为其他运算符：
    if （栈空或者栈顶运算符为'('） 直接将ch进栈;
     else if (ch的优先级高于栈顶运算符的优先级)
      直接将ch进栈;
        else
       依次出栈并存入到postexp中，直到栈顶运算符优先级小于ch的优先级，
       然后将ch进栈; }若exp扫描完毕，则将Optr中所有运算符依次出栈并存放到postexp中。
**/
void trans(char *exp, char postexp[])
{
  char e; //定义运算符栈顶指针
  SqStack *Optr;
  InitStack(Optor); //初始化运算符栈
  int i = 0;
  while (*exp != '\0')
  {
    switch (*exp)
    {
    case '(': //判定左括号
      Push(Optr, '(');
      exp++;
      break;
    case ')': //判定右括号
      Pop(Optr, e);
      while (e != '(')
      {
        postexp[i++] = e;
        Pop(Optr, e);
      }
      exp++; //继续扫描其他元素
      break;
    case '+':
    case '-':
      while (!StackEmpty(Optr))
      {
        GetTop(Optr, e); //取栈顶元素
        if (e != '(')
        {
          postexp[i++] = e; //将e存放到postexp
          Pop(Optr, e);     //出栈元素e
        }
        else
          break;
      }
      Push(Optr, *exp); //将+ -进栈
      exp++;
      break;
    case '*':
    case '/':
      while (!StackEmpty(Optr)) //栈不为空时候
      {
        GetTop(Optr, e);          //取栈顶元素
        if (e == '*' || e == '/') //将* /出栈存放到postexp
        {
          postexp[i++] = e;
          Pop(Optr, e); //出栈元素e
        }
        else
          break;
      }
      Push(Optr, *exp); //将* or /进栈
      exp++;
      break;
    default:
      while (*exp >= '0' && *exp <= '9') //判定为数字字符
      {
        postexp[i++] = *exp;
        exp++;
      }
      postexp[i++] = '#'; //用#号表示一个数字的结束
    }
  }
  while (!StackEmpty(Optr)) //此时exp扫描完毕，栈不为空
  {
    Pop(Optr, e); //出栈元素e
    postexp[i++] = e;
  }
  postexp[i] = '\0';
  DestroyStack(Optr); //销毁栈
}
/**
while (从postexp读取字符ch，ch!='\0')
{   ch为'+'：从Opnd栈中出栈两个数值a和b，计算c=b+a;将c进栈;
    ch为'-'： 从Opnd栈中出栈两个数值a和b，计算c=b-a;将c进栈;
    ch为'*'：从Opnd栈中出栈两个数值a和b，计算c=b*a;将c进栈;
    ch为'/'： 从Opnd栈中出栈两个数值a和b，若a不为零，计算c=b/a;将c进栈;
     ch为数字字符：将连续的数字串转换成数值d，将d进栈; }
    返回Opnd栈的栈顶操作数即后缀表达式的值;
**/
double compvalue(char *postexp)
{
  double d, a, b, c, e;
  SqStack *Opnd;           //定义花操作数栈
  InitStack(Opnd);         //初始化栈
  while (*postexp != '\0') //遍历扫描
  {
    switch (*postexp)
    {
    case '+':        //判定元素为加号
      Popl(Opnd, a); //出栈元素a
      Popl(Opnd, b); //出栈元素b
      c = a + b;
      Push(Opnd, c); //计算结果c进栈
      break;
    case '-':
      Popl(Opnd, a); //出栈元素a
      Popl(Opnd, b); //出栈元素b
      c = b - a;
      Push(Opnd, c); //计算结果c进栈
      break;
    case '*':
      Popl(Opnd, a); //出栈元素a
      Popl(Opnd, b); //出栈元素b
      c = b * a;
      Push(Opnd, c); //计算结果c进栈
      break;
    case '/':
      Popl(Opnd, a); //出栈元素a
      Popl(Opnd, b); //出栈元素b
      if (a != 0)
      {
        c = a / b;
        Push(Opnd, c); //计算结果c进栈
        break;
      }
      else
      {
        printf("\n\t除零错误\n");
        exit(0);
      }
      break;
    default: //处理数字字符
      d = 0;
      while (*postexp >= '0' && *postexp <= '9') //将连续的数字字符转化为队友的数值
      {
        d = 10 * d + *postexp - '0';
        postexp++;
      }
      Push(Opnd, d);
      break;
    }
    postexp++; //鸡血处理其它字符
  }
  GetTopl(Opnd, e);    //取栈顶元素
  DestroyStackl(Opnd); //销毁栈
  return e;
}