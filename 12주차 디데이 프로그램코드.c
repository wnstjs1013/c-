#include <stdio.h>
#include <time.h>

int calculate_d_day(int year, int month, int day) {
    // 현재 날짜 가져오기
    time_t t = time(NULL);
    struct tm today = *localtime(&t);

    // 목표 날짜 설정
    struct tm target_date = { 0 };
    target_date.tm_year = year - 1900; // 년도는 1900년 기준으로 입력
    target_date.tm_mon = month - 1;   // 월은 0부터 시작
    target_date.tm_mday = day;

    // 시간차 계산
    time_t target_time = mktime(&target_date);
    time_t current_time = mktime(&today);
    double difference = difftime(target_time, current_time);

    return (int)(difference / (60 * 60 * 24)); // 일 단위로 변환
}

int main() {
    int year, month, day;
    printf("디데이 계산 프로그램입니다.\n");
    printf("목표 날짜를 입력하세요 (YYYY MM DD): ");
    scanf("%d %d %d", &year, &month, &day);

    int d_day = calculate_d_day(year, month, day);

    if (d_day > 0) {
        printf("D-%d일 남았습니다.\n", d_day);
    }
    else if (d_day == 0) {
        printf("오늘이 D-Day입니다!\n");
    }
    else {
        printf("D+%d일 경과하였습니다.\n", -d_day);
    }

    return 0;
}
