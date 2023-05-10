1.project 주요 개념 + 주제
=================

1. 배울 주요 개념
- 가변인자
- va_start, va_arg, va_copy, va_end 함수에 대한 개념
</br>
   
2. 주제
- 실제 printf의 동작을 모방한 ft_printf 포함한 라이브러리 작성
- 다음의 서식 지정자를 구현해라. `c s p d i u x X %`(실제 printf와 비교해서 구현)
</br>

2.가변인자 함수 
==========
함수에서 고정된 인자가 아닌, 정해지지 않은 여러 개의 인자를 받고 싶은 경우가 있을 수 있다! </br> 
**리턴형 함수명(고정인자, ...)** <- 이런 형식의 가변인자 함수 선언문
### 1. 가변인자 함수 3가지
- **va_start(ap,v)**
   - ap가 가변인자의 첫 번째 인자를 포인트하게 초기화한다.
   - v는 가변인자 바로 직전의 인자, 즉 마지막 고정인자이다. 
      - (이 마지막 고정인자 다음으로 ap를 맞춰줘서, ap가 가변인자의 첫 번째 인자를 포인트하게 한다)

- **va_arg(ap, type)**
   - ap 위치에서 type으로 지정한 값을 읽어 값 리턴
   - ap를 다음 가변인수 위치로 옮겨줌
- **va_end(ap)**
   - va_start()로 초기화된 ap 포인터를 제거
</br>

### 2. 가변인자 함수 예제
<pre>
<code>
#define END 0
#define INT 1
#define DOUBLE 2

double va_sum(int, ...);

int main(void)
{
   printf("sum : %.3f\n", va_sum(INT, 3, DOUBLE, 3.0, END)); // 3 + 3.0 = 6.0 을 하고 싶다.
   printf("sum : %.3f\n", va_sum(DOUBLE, 20.0, INT, 90, DOUBLE, 0.5, END)); 
}

double va_sum(int type, ...)
{
   double sum = 0.0;
   va_list = ap; // va_list는 void*형으로, ap는 어떠한 자료형이든 point할 수 있다.
   
   va_start(ap,type); //ap는 마지막 고정인자 type 바로 다음부터인 첫번째 가변인자를 가리킨다. // 첫번째 예시로 따지면, type은 INT(1), ap는 3을 가리킨다.
   while (type != 0)
   {
      if (type == INT)
         sum = sum + va_arg(ap, int); //ap가 가리키던 값을 int형으로 읽어 리턴해주고(3), ap는 그 다음 가변인자(DOUBLE)를 가리킨다.
      else
         sum = sum + va_arg(ap, double);
      type = va_arg(ap, int); //ap가 가리키던 DOUBLE을 int형으로 리턴(2) + ap는 그 다음 가변인자인 3.0 가리킨다.
   }
   va_end(ap); // ap 포인터 제거
   return (sum);
 }
 </pre>
 </code>
 
 </br>
 
 3.프로젝트 진행 중 알게 된 점
 ==========
 1. va_arg(ap, char)형 -> waring
 실제로 va_arg()함수는 char형 타입을 읽는 것을 정의하고 있다. </br>
 하지만 이때 문제는, va_arg함수가 인자를 읽을 때,인자들은 char형을 int형으로 promotion되어 더 큰 자료형으로 형변환된다는 것!</br>
 
 이때, promotion은 c언어에서 자료형의 크기가 작은 타입 -> 큰 타입으로 자동 형변환되는 것. 이 프로모션은 의도치 않은 결과를 초래할 수
 있기에 문제가 된다. </br>
 예를 들어, signed int가 unsigned int로 promotion이 일어날 때, 부호 비트가 0이 아닌 signed int가(음수) unsigned int로
 형변환되면, 그냥 큰 양수로 인식되어 잘못된 결과를 초래할 수도 있다.
 






