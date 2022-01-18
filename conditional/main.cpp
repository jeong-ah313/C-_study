#include <iostream>
/*���ǹ�
    ����� ����: ���ǹ�, �ݺ���
*/

void example1()
{
    //����1
    //���ǹ��� ����: if��, if/else��, if/else if/else��, swiitch��
    //if��-����� ���̸� �־��� ����� �����ϰ�, �����̸� �ƹ��͵� �������� �ʴ´�.
    int num = 10;

    if (num < 5)
    {
        std::cout << "�Է��Ͻ� ���� 5���� �۽��ϴ�." << std::endl;

    }
    if (num == 5)
    {
        std::cout << "�Է��Ͻ� ���� 5�Դϴ�." << std::endl;
    }
    if (num > 5)
    {
        std::cout << "�Է��Ͻ� ���� 5���� Ů�ϴ�." << std::endl;
    }

    //����2
    //if/else��-�־��� ���ǽ��� ����� �����̸� �־��� ��ɹ��� �����Ѵ�
    if (num < 5)
    {
        std::cout << "�Է��Ͻ� ���� 5���� �۽��ϴ�." << std::endl;
    }
    else
    {
        if(num == 5)
        {
            std::cout << "�Է��Ͻ� ���� 5�Դϴ�." << std::endl;
        }
        else
        {
            std::cout << "�Է��Ͻ� ���� 5���� Ů�ϴ�." << std::endl;
        }
    }

    //����3
    //if / else if /else��
    if (num<5)
    {
        std::cout << "�Է��Ͻ� ���� 5���� �۽��ϴ�." <<std::endl;
    }
    else if (num == 5)
    {
        std::cout << "�Է��Ͻ� ���� 5�Դϴ�." << std::endl;
    }
    else
    {
        std::cout << "�Է��Ͻ� ���� 5���� Ů�ϴ�." << std::endl;
    }

    //����4
    //switch��
    switch (num)
    {
    case 1:
        std::cout << "�Է��Ͻ� ���� 1�Դϴ�." << std::endl;
        break;
    case 2:
        std::cout << "�Է��Ͻ� ���� 2�Դϴ�." << std::endl;
        break;
    case 3:
        std::cout << "�Է��Ͻ� ���� 3�Դϴ�." << std::endl;
        break;
    case 4:
        std::cout << "�Է��Ͻ� ���� 4�Դϴ�." << std::endl;
        break;
    case 5:
        std::cout << "�Է��Ͻ� ���� 5�Դϴ�." << std::endl;
        break;
    default:
        std::cout << "1���� 5������ ���� �Է��� �ּ���!" << std::endl;
       break;


    }
}

void example2()
{
    //����1
    //�ݺ���(iteration statements)-���α׷� ������ �Q���� ����� ���� Ƚ����ŭ �����ϵ��� �����ϴ� ��ɹ�
    //while��, do/while��, for��, ���� ����� for��

    //while��-Ư�� ������ ������ ������ ��Ұ��� �־��� ��ɹ��� �ݺ� ����
    int i = 0;
    int num = 5;


    while (i < num)
    {
        std::cout <<"whie���� ����" << i+1 << "������ �ݺ� �������Դϴ�." << std::endl;
        i++; //�� �κ��� �����ϸ� ���� ������ ������ �ȴ�.
    }
    std::cout << "while���� ����� �� ���� i�� ����" << i << "�Դϴ�." << std::endl; //i���� 5���Ǽ� �ݺ����� �� �� ���� �� ��

    //����2
    //do-while��:while���� �����ϱ� ���� ���ǹ����� �˻�, ���� ���ǹ��� ������ 1���� �����ϰ� ��

    do {
        std::cout << "do / while���� ����" << i + 1 << "���� �������Դϴ�." << std::endl;
        i++;
    } while (i < num);
    std::cout << "do-while���� ����� �� ���� i ����" << i << "�Դϴ�." << std::endl;

    //����3
    //for��<->while��: for���� while���� �޸� ��ü������,�ʱ��, ���ǽ�, �������� ��� �����ϰ� �ִ� �ݺ���
    for (i = 0; i < num; i++)
    {
        std::cout << "for���� ����" << i + 1 << "���� �ݺ� �������Դϴ�." << std::endl;
     }
    std::cout << "for���� ����� �� ���� i�� ���� " << i << "�Դϴ�." << std::endl;
    //��, for���� for������ ���� ����� ������ for���� ����Ǹ� ���� �Ҹ�ȴ�.

    //����4
    //���� ����� for��: ���� ����� for���� ǥ���� �ȿ� ���ԵǾ� �ִ� ��� ���� �뷡 �� ���� ������ ��������
    int arr[5] = {1,3,5,7,9};

    for (int element : arr)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;


}

//22.��Ÿ���
void example3()
{
    //continue��, break��, goto��- continue�� break���� ������ �帧�� ����ڰ� ���� ������ �� �ֵ��� �����ش�.

    //����1
    //continue��: ���� ������ �ش� ������ ������ �κ��� �ǳʶٰ�, �ٷ� ���� ���ǽ��� �Ǵ����� �Ѱ��ش�
    int except_num = 2;

    for (int i = 1; i <= 100; i++)
    {
        if (i % except_num == 0)
        {
            continue;
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;

    //����2
    //break��: ���� ������ ����Ͽ� �ش� �ݺ����� ������ �����Ų ��, �ݺ��� �ٷ� ������ ��ġ�� ��ɹ��� ����
    //��, �ݺ����� ������ ���� ���� �� ���!
    int num = 1, sum =0;
    int end_num = 10;

    while (1) //���ѷ���
    {
        sum += num;
        if (num == end_num)
        {
            break;
        }
        num++;
    }
    std::cout << "1����" << end_num << "���� ���� ���� " << sum << " �Դϴ�." << std::endl;
}


int main()
{
    example1();
    example2();
    example3();

}
