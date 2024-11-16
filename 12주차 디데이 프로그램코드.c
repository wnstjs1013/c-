#include <stdio.h>
#include <time.h>

int calculate_d_day(int year, int month, int day) {
    // ���� ��¥ ��������
    time_t t = time(NULL);
    struct tm today = *localtime(&t);

    // ��ǥ ��¥ ����
    struct tm target_date = { 0 };
    target_date.tm_year = year - 1900; // �⵵�� 1900�� �������� �Է�
    target_date.tm_mon = month - 1;   // ���� 0���� ����
    target_date.tm_mday = day;

    // �ð��� ���
    time_t target_time = mktime(&target_date);
    time_t current_time = mktime(&today);
    double difference = difftime(target_time, current_time);

    return (int)(difference / (60 * 60 * 24)); // �� ������ ��ȯ
}

int main() {
    int year, month, day;
    printf("���� ��� ���α׷��Դϴ�.\n");
    printf("��ǥ ��¥�� �Է��ϼ��� (YYYY MM DD): ");
    scanf("%d %d %d", &year, &month, &day);

    int d_day = calculate_d_day(year, month, day);

    if (d_day > 0) {
        printf("D-%d�� ���ҽ��ϴ�.\n", d_day);
    }
    else if (d_day == 0) {
        printf("������ D-Day�Դϴ�!\n");
    }
    else {
        printf("D+%d�� ����Ͽ����ϴ�.\n", -d_day);
    }

    return 0;
}
