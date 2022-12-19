#include <pthread.h>     // 引用 pthread 函式庫
#include "http.h"
#include "list.c"

int port;
char *host;

void* getPage(void *ip) {
  int i = *(int*) ip;
  char file[100], head[PACKET_MAX];
  sprintf(file, "page/%s", list[i]);
  httpDownload(host, port, list[i], head, file);
  return NULL;
}

int main(int argc, char *argv[]) {
  port = (argc >= 2) ? atoi(argv[1]) : PORT;
  host = (argc >= 3) ? argv[2] : "localhost";
  pthread_t thread[LIST_SIZE];
  int idx[LIST_SIZE];
  for (int i=0; i<LIST_SIZE; i++) {
    idx[i] = i; // 不能直接傳 &i 進去，否則會因為共用而導致 bug，所以宣告 idx 陣列，避開共用問題！
    pthread_create(&thread[i], NULL, getPage, (void*) &idx[i]);
  }
  for (int i=0; i<LIST_SIZE; i++) {
    pthread_join(thread[i], NULL);
  }
  return 0;    
}