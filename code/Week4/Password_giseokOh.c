// Your program should continuously prompt the user to enter a password
// You must use a while loop to keep asking for input until the correct password is entered
// The correct password should be predefined in the program (e.g.,1234)
// Display a success message when the correct password is entered and terminate the program
#include <stdio.h>

int main(void)
{
    int password = 1234;
    int inputNum = 0;

    // 오버플로우가 되더라도, 컴퓨터에서는 같은 메모리로 인식(or 컴파일에러)
    // 만약 int 자리 수를 max로 입력받고, +1을 하면 비트 부호 맨앞이 바뀌어 양수는 음수로, 음수는 양수로 변한다.
    // sizeof는 변수의 메모리 크기만 계산하기 때문에 길이 제한으로 사용할 수 없다.
    // int 1이나, int 1000 이나 똑같은 4비이트로 인식
    do
    {
        printf("Input password\n");
        scanf("%d", &inputNum);
    } while (inputNum != password);

    printf("login success\n");
    return 0;
}
