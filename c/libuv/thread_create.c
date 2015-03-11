#include <stdio.h>
#include <unistd.h>
#include <uv.h>

void hare(void* arg) {
    int tracklen = *(int*)arg;
    while(tracklen) {
        tracklen-=2;
        sleep(5);
        fprintf(stderr, "Hare ran another step\n");
    }
    fprintf(stderr, "Hare done running\n");
}

void tortoise(void* arg) {
    int tracklen = *(int*)arg;
    while(tracklen) {
        tracklen--;
        sleep(1);
        fprintf(stderr, "Tortoise ran another step\n");
    }
    fprintf(stderr, "Tortoise done running\n");
}

int main() {
    int tracklen = 10;
    uv_thread_t hare_id;
    uv_thread_t tortoise_id;
    uv_thread_create(&hare_id, hare, &tracklen);
    uv_thread_create(&tortoise_id, tortoise, &tracklen);
    uv_thread_join(&hare_id);
    uv_thread_join(&tortoise_id);
}
